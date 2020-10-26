# Lab 6  
**Record the IP address and the MAC address for the RPi.**  
192.168.1.161  
B8:27:EB:C3:A8:8A  

### Try some Python code on the Pi

**How do you know what the shell script is doing?**

Opening the shell scripts in vim reveals them to fairly simply and readably import the respective tools and then call them with the desired text. Changing what they say is as simple as replacing the text in the call.

Adapt the scripts so that they say what you want them to say.

Now try the shellscripts in the ``speechToText`` directory.

These scripts use a program called [``vosk``](https://alphacephei.com/vosk/) to recognize numbers.

**How do we use ``vosk`` to recognize words and phrases?**  
First, we specify a list of words to be recognized. Then, we pass in the audio.  

**Include the output of vosk recognizing phrases you taught it to look for.**

```shell
{
  "result" : [{
      "conf" : 1.000000,
      "end" : 1.650000,
      "start" : 0.630000,
      "word" : "raspberry"
    }, {
      "conf" : 1.000000,
      "end" : 2.670000,
      "start" : 1.950000,
      "word" : "pie"
    }, {
      "conf" : 1.000000,
      "end" : 3.780000,
      "start" : 3.090000,
      "word" : "tasty"
    }],
  "text" : "raspberry pie tasty"
}
```


**Include the listing for a shell script and model files that you use to get vosk to recognize these phrases.**
```shell
arecord -D hw:2,0 -f cd -c1 -r 48000 -d 5 -t wav raspi.wav
python3 pi_words.py raspi.wav
```

## Connect the Arduino and the RPi


### Hello Pi, Hello Arduino

With your Pi and Arduino, try out the ``helloPi`` and ``helloArduino`` sketches. Tweak them to make them do something new.

``HelloPi.ino`` sets up the Arduino to say hello to the Pi repeatedly.
``HelloPi.py`` echos the Arduino’s message to the console in text form.
``sayHelloPi.py`` plays the helloPi.wav file whenever the Pi gets any message from the Arduino on the serialPort.

Flash the Arduino with ``HelloPi.ino``.
With ``HelloPi.ino`` running on the Arduino, run ``HelloPi.py`` on the Pi using ``$python HelloPi.py``.

**What would you change to make sayHelloPi say something else?**  
Change the audio file that it plays.

**How could you make it so that the Pi would only say something if the lights came on in the room?**  
You could either attach a sensor to the Arduino and only output the message if the lights are on, or attach a sensor to the RPi and only play audio if the lights are on.

**How could you make it so that the Pi would say different things based on different sensor values read by the Arduino?**  
Pass the sensor data from the Arduino to the RPi over serial, and have a simple if statement based on that data that depermines what is output.

## Your own voice agent

**Record someone trying out your design**

My recording can be found [here](./media/chatbot.mp4)\.  

**Submit your code to Github**
