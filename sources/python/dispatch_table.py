from collections import namedtuple

Directive = namedtuple('Directive', 'trig_in address osc_message clock_div')

dispatch_table = [
    Directive(trig_in=1, address=('ottomann.local', 4242), osc_message=('/debug', [1]), clock_div=1),
    Directive(trig_in=2, address=('ottomann.local', 4242), osc_message=('/debug', [2]), clock_div=2),
    Directive(trig_in=3, address=('ottomann.local', 4242), osc_message=('/debug', [3]), clock_div=4),
    Directive(trig_in=4, address=('ottomann.local', 4242), osc_message=('/debug', [4]), clock_div=8),
]
