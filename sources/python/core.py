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
clients = {}

log("DISPATCH TABLE :")
for directive in dispatch_table:
    log("\t- {}".format(directive))
    address = directive.address
    if address not in clients:
        clients[address] = udp_client.SimpleUDPClient(*address)

clock_counters = {trig_index:0 for _, trig_index in trig_patch.items()}


def on_trig(button):
    """
    Send the osc messages for all the directives that listen to trig_index
    """
    trig_index = trig_patch[repr(button.pin)]
    clock_counters[trig_index] += 1
    log('TRIG IN : {} ({})'.format(trig_index, clock_counters[trig_index]))
    for directive in dispatch_table:
        if directive.trig_in == trig_index:
            if clock_counters[trig_index] % directive.clock_div == 0:
                clients[directive.address].send_message(*directive.osc_message)
                log('\t-> OSC OUT : {osc_message} to {address}'.format(
                    osc_message=directive.osc_message,
                    address=directive.address)
                )


buttons = {}

for pin, trig_index in trig_patch.items():
    log('PATCH: trig {} on GPIO{}'.format(trig_index, pin))
    buttons[trig_index] = Button(pin)
    buttons[trig_index].when_released = on_trig
    # buttons[trig_index].when_released = lambda : on_trig(trig_index)


log('START SERVING...')

pause()
