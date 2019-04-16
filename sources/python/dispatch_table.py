from collections import namedtuple

Directive = namedtuple('Directive', 'trig_in address osc_message, clock_div')

dispatch_table = [
    # debug (send /debug to ottomann)
    Directive(trig_in=1, address=('ottomann.local', 4242), osc_message=('/debug', [1]), clock_div=1),
    Directive(trig_in=2, address=('ottomann.local', 4242), osc_message=('/debug', [2]), clock_div=1),
    Directive(trig_in=3, address=('ottomann.local', 4242), osc_message=('/debug', [3]), clock_div=1),
    Directive(trig_in=4, address=('ottomann.local', 4242), osc_message=('/debug', [4]), clock_div=1),

    # ACTE 2 (send clock to godel and ottomann from trig_in 2)
    Directive(trig_in=2, address=('godel.local', 4242), osc_message=('/clock', []), clock_div=1),
    Directive(trig_in=2, address=('10.0.0.2', 50460), osc_message=('/control/navigator/run', ['default']), clock_div=2),

    # ACTE 3 (send messages to bots from trig_in 3)
    Directive(trig_in=2, address=('lucy.local', 4242), osc_message=('/dance', []), clock_div=2),
]
