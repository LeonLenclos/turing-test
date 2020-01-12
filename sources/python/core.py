#! /usr/bin/python3.5
    
import datetime
from collections import OrderedDict

from pythonosc import osc_message_builder
from pythonosc import udp_client

from dispatch_table import dispatch_table

from gpiozero import Button

import requests


# keys are trig_index values are pin number
trig_patch = {
     4:1,
    17:2,
    22:3,
    27:4,
}
            
def log(msg):
    """Write a message in the log file."""
    print(msg)
    print(msg, file=open("/home/pi/log", "a"))


class TrigHandler():

    def __init__(self, table):

        self.queue = []
        self.table = table
        self.session = requests.session()
        log("-"*50)
        log("CORE : new session ({})".format(datetime.datetime.now()))

        # `clients` is a dict containing all osc client.
        # Because we need one osc client by ip adress.
        # So, keys are (ip, port) and values are SimpleUDPClient(ip, port)
        self.osc_clients = {}
        log("DISPATCH TABLE :")
        for directive in self.table:
            log("\t- {}".format(directive))
            if directive.scheme == 'osc' and directive.netloc not in self.osc_clients:
                self.osc_clients[directive.netloc] = udp_client.SimpleUDPClient(directive.hostname, directive.port)

        self.buttons = {}
        log("PATCH :")
        for pin, trig_index in trig_patch.items():
            log('\t- trig {} on {}'.format(trig_index, pin))
            self.buttons[trig_index] = Button(pin)

    def run(self):
        log('START SERVING...')
        pressed = set()
        while True:
            for trig_index, button in self.buttons.items():
                if button.is_pressed and trig_index not in pressed:
                    self.on_trig(trig_index)
                    pressed.add(trig_index)
                elif not button.is_pressed  and trig_index in pressed:
                    pressed.remove(trig_index)
            if not pressed and self.queue:
                directive = self.queue.pop()
                log('\t> executing {}'.format(directive))
                try:
                    if directive.scheme == 'osc':
                        self.osc_clients[directive.netloc].send_message(directive.path, directive.content)
                    elif directive.scheme == 'http':
                        self.session.post(directive.url, json=directive.content, timeout=0.0000000001)
                    else :
                        raise Exception('Core dont know the {} protocole'.format(directive.scheme))
                except requests.exceptions.ReadTimeout: 
                    pass
                except Exception as e:
                    log('\tERROR ! {}'.format(e))

    
    def on_trig(self, trig_index):
        """
        Do the directives.
        """
        log('\t> TRIG IN : {}'.format(trig_index))
        for directive in self.table:
            if directive.trig_in == trig_index and directive.clock_div.clock():
                self.do_directive(directive)

    def do_directive(self, directive):
        log('\t> adding to queue {}'.format(directive))
        self.queue.append(directive)



handler = TrigHandler(dispatch_table)
handler.run()
