#! /usr/bin/python
import datetime

from pythonosc import osc_message_builder
from pythonosc import udp_client
from signal import pause
from gpiozero import Button

from dispatch_table import dispatch_table

def log(msg):
    """
    write a message in the log file
    """
    print(msg)
    print(msg, file=open("log", "a"))

log("-"*50)
log("CORE : new session ({})".format(datetime.datetime.now()))

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


def on_trig(trig_index):
    """
    Send the osc messages for all the directives that listen to trig_index
    """
    log('TRIG IN : {}'.format(trig_index))
    for directive in dispatch_table:
        if directive.trig_in == trig_index:
            clients[directive.address].send_message(*directive.osc_message)
            log('\t-> OSC OUT : {osc_message} to {address}'.format(
                osc_message=directive.osc_message,
                address=directive.address)
            )

# keys are trig_index values are pin number
trig_patch = {
    1:3
    2:7
    3:8
    4:2
}

for trig_index, pin in trig_patch.items():
    trig = Button(pin)
    trig.when_pressed = lambda : on_trig(trig_index)

log('START SERVING...')

pause()