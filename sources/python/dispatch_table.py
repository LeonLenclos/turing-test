from collections import namedtuple

Directive = namedtuple('Directive', 'trig_in address osc_message')

dispatch_table = [
    Directive(trig_in=1, address=('ottomann.local', 4242), osc_message=('/debug', [1])),
    Directive(trig_in=2, address=('ottomann.local', 4242), osc_message=('/debug', [2])),
    Directive(trig_in=3, address=('ottomann.local', 4242), osc_message=('/debug', [3])),
    Directive(trig_in=4, address=('ottomann.local', 4242), osc_message=('/debug', [4])),

    Directive(trig_in=2, address=('lucy.local', 4242), osc_message=('/dance', [])),

    Directive(trig_in=1, address=('godel.local', 4242), osc_message=('/clock', [])),
    Directive(trig_in=3, address=('10.0.0.2', 50460), osc_message=('/control/navigator/run', ['default'])),
]
