#! /usr/bin/python3.5

import datetime
from collections import OrderedDict
from pythonosc import osc_message_builder
from pythonosc import udp_client
from signal import pause
from gpiozero import Button

from dispatch_table import dispatch_table



def log(msg):
    """Write a message in the log file."""
    print(msg)
    print(msg, file=open("log", "a"))


log("-"*50)
log("CORE : new session ({})".format(datetime.datetime.now()))

# keys are trig_index values are pin number
trig_patch = {
    'GPIO4' :1,
    'GPIO17':2,
    'GPIO22':3,
    'GPIO27':4,
}

# `clients` is a dict containing all osc client.
# Because we need one osc client by ip adress.
# So, keys are (ip, port) and values are SimpleUDPClient(ip, port)
osc_clients = {}

log("DISPATCH TABLE :")
for directive in dispatch_table:
    log("\t- {}".format(directive))
    address = directive.hostname, directive.port
    if directive.scheme == 'osc' and address not in osc_clients:
        osc_clients[address] = udp_client.SimpleUDPClient(*address)


def on_trig(button):
    """
    Do the directives.
    """
    trig_index = trig_patch[repr(button.pin)]
    log('TRIG IN : {}'.format(trig_index))
    for directive in dispatch_table:
        if directive.trig_in == trig_index:
            if directive.clock_div.clock():
                log('\t> doing {}'.format(directive))
                try:
                    if directive.netloc == 'osc':
                        osc_clients[directive.address]
                        .send_message(*directive.content)
                    elif directive.netloc == 'http' :
                        requests.post(directive.url, json=directive.content)
                except Exception as e:
                    log('\tERROR !')
buttons = {}

for pin, trig_index in trig_patch.items():
    log('PATCH: trig {} on {}'.format(trig_index, pin))
    buttons[trig_index] = Button(pin)
    buttons[trig_index].when_released = on_trig

log('START SERVING...')

pause()
