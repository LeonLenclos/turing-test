from collections import namedtuple

Directive = namedtuple('Directive', 'trig_in adress osc_message')

dispatch_table = [
    Directive(trig_in=1, address=('10.0.0.2', 5050), osc_message=('/path', 3)),
]