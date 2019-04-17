from collections import namedtuple
from urllib.parse import urlparse

class ClockDiv():
    """A clock divider"""
    def __init__(self, division=1, offset=0):
        self.division = division
        self.offset = offset
        self.counter = offset

    def clock(self):
        self.counter += 1
        return self.counter % self.division == 0

    def __repr__(self):
        return 'ClockDiv({}, {})'.format(self.division, self.offset)

class Directive():
    """A network action to do on trig"""
    def __init__(self, trig_in, url, content, clock_div=ClockDiv()):        
        self.trig_in = trig_in
        self.url = url
        self.content = content
        self.clock_div = clock_div

        parsed_url = urlparse(self.url)
        self.scheme = parsed_url.scheme
        self.netloc = parsed_url.netloc
        self.port = parsed_url.port
        self.hostname = parsed_url.hostname
        self.path = parsed_url.path

    def __repr__(self):
        return 'Directive(trig_in={}, url={}, content={}, clock_div={})'.format(self.trig_in, self.url, self.content, self.clock_div)
            
        
debug_table = [
    Directive(1, 'osc://ottomann.local:4242/debug', ['trig 1']),
    Directive(2, 'osc://ottomann.local:4242/debug', ['trig 2']),
    Directive(3, 'osc://ottomann.local:4242/debug', ['trig 3']),
    Directive(4, 'osc://ottomann.local:4242/debug', ['trig 4']),

    Directive(1, 'osc://ottomann.local:4242/debug', ['trig 1 div by 2'], ClockDiv(2)),
    Directive(1, 'osc://ottomann.local:4242/debug', ['trig 1 div by 2+1'], ClockDiv(2,1)),
    Directive(1, 'osc://ottomann.local:4242/debug', ['trig 1 div by 4'], ClockDiv(4)),
    
    Directive(1, 'http://ottomann.local:8000/debug', {}, ClockDiv(4)),
]
        

dispatch_table = debug_table
