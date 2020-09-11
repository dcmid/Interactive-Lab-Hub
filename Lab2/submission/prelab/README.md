#Arduino True Analog Output Support
It bugs me to an unreasonable degree that Arduino's pwm function is called
_analogOut_, so I have decided to make it an actual analog output. This can
be fairly simply accomplished through the use of a buck converter, a DC-DC
converter circuit with an output voltage that is conveniently controlled
via pwm. A simple diagram of the potential design is shown below. I may need
to modify this design a little bit, as the buck converter's capacitor would
currently still filter the output when the converter is bypassed.
![](./media/schem.jpg)
