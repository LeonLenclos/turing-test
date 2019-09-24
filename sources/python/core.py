#! /usr/bin/python3.5
    
import datetime
from threading import Thread
from collections import OrderedDict

from pythonosc import osc_message_builder
from pythonosc import udp_client
from signal import pause
from gpiozero import Button
from dispatch_table import dispatch_table

import requests


# keys are trig_index values are pin number
trig_patch = {
    'GPIO4' :1,
    'GPIO17':2,
    'GPIO22':3,
    'GPIO27':4,
}






class TrigHandler(Thread):

    def __init__(self, table):
        Thread.__init__(self)
        self.table = table
        self.session = requests.session()
        self.log("-"*50)
        self.log("CORE : new session ({})".format(datetime.datetime.now()))

        # `clients` is a dict containing all osc client.
        # Because we need one osc client by ip adress.
        # So, keys are (ip, port) and values are SimpleUDPClient(ip, port)
        self.osc_clients = {}
        self.log("DISPATCH TABLE :")
        for directive in self.table:
            self.log("\t- {}".format(directive))
            address = directive.hostname, directive.port
            if directive.scheme == 'osc' and directive.netloc not in self.osc_clients:
                self.osc_clients[directive.netloc] = udp_client.SimpleUDPClient(directive.hostname, directive.port)


        self.buttons = {}
        for pin, trig_index in trig_patch.items():
            self.log('PATCH: trig {} on {}'.format(trig_index, pin))
            self.buttons[trig_index] = Button(pin)
            self.buttons[trig_index].when_released = self.on_trig

    def run(self):
        self.log('START SERVING...')
        pause()

    def log(self, msg):
        """Write a message in the log file."""
        print(msg)
        print(msg, file=open("/home/pi/log", "a"))
    
    def on_trig(self, button):
        """
        Do the directives.
        """
        trig_index = trig_patch[repr(button.pin)]
        self.log('TRIG IN : {}'.format(trig_index))
        for directive in self.table:
            if directive.trig_in == trig_index:
                if directive.clock_div.clock():
                    self.log('\t> doing {}'.format(directive))
                    try:
                        if directive.scheme == 'osc':
                            self.osc_clients[directive.netloc].send_message(directive.path, directive.content)
                        elif directive.scheme == 'http':
                            self.session.post(directive.url, json=directive.content)
                        else :
                            raise Exception('Core dont know the {} protocole'.format(directive.scheme))
                    except Exception as e:
                        self.log('\tERROR ! {}'.format(e))


thread1 = TrigHandler(dispatch_table)
thread1.start()
thread1.join()