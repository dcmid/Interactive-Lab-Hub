# HelloPi by Wendy Ju
#
# June 25, 2020
# to use the ACT LED, you must first run $ echo none | sudo tee /sys/class/leds/led0/trigger from the command line
# to restore the ACT LED, reboot, or run echo mmc0 | sudo tee /sys/class/leds/led0/trigger

import warnings
import serial
import time
import wave
import sys
import os
import json
from vosk import Model, KaldiRecognizer
from gpiozero import LED, PinNonPhysical
from subprocess import call

# This disables the PinNonPhysical warning for the rest of the script
warnings.simplefilter('ignore', category=PinNonPhysical)


ser=serial.Serial("/dev/ttyUSB0",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600
actled = LED(29)


while True:
   try:
      message=ser.readline()
      print(message)
      actled.blink()

      call(["arecord","-D","hw:2,0","-f","cd","-c1","-r","48000","-d","3","-t","wav","audin.wav"])

      wf = wave.open("audin.wav", "rb")
      if wf.getnchannels() != 1 or wf.getsampwidth() != 2 or wf.getcomptype() != "NONE":
          print ("Audio file must be WAV format mono PCM.")
          exit (1)

      model = Model("model")
      # You can also specify the possible word list
      rec = KaldiRecognizer(model, wf.getframerate(), "hi hello hey how [unk]")

      while True:
          data = wf.readframes(4000)
          rec.AcceptWaveform(data)
          if len(data) == 0:
              break
      words = json.loads(rec.FinalResult())['text']
      print("WORDS:",words)
      if("how" in words):
          print("I'm well, and you?")
          call(["aplay","inquiry.wav"])
      elif("hi" in words or "hello" in words):
          print("Well, hello!")
          call(["aplay","greeting.wav"])

   except KeyboardInterrupt:
      ser.close()
      break
