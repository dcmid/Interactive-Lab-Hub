## Serving webpages with the Raspberry Pi

**Customize the code enough that the webpage served up is clearly your own, and include a screenshot and any modified code in the lab folder.**

![](./media/darrenserver.png)

My code can be found [here](./code/darrenserver.py).

### Flash the HelloYou Sketch onto the Arduino

**What messages are sent from the Arduino to the Pi?**  
The Arduino writes the current state of the button ('light' or 'dark') over serial.

**What messages are expected from the Pi to the Arduino?**  
The Pi writes 'H' or 'L' over serial whenever an input comes to the server.

**What happens if the Pi sends an unexpected message to the Arduino?**  
The LED is turned off. This is because the Arduino code uses an if else statement, so all inputs that don't satisfy the if condition will fall through to the else.

**How fast does the Arduino communicate with the Pi? What would you change to make it send messages less often?**  
It communicates at 9600 baud. The Arduino only sends messages when the button state changes. So, to send messages less often, press the button more slowly. To send messages more slowly, lower the baud rate.

### Run the HelloYou server on the RPi

**What messages are sent from the Pi to the Arduino?**  
The Pi writes 'H' or 'L' over serial whenever an input comes to the server.

**What messages are expected from the Arduino to the Pi?**  
The Arduino writes the current state of the button ('light' or 'dark') over serial.


**What happens if the Arduino sends an unexpected message to the Pi?**  
Nothing happens. This is because the js explicitly checks for both expected messages in a switch statement, so an unexpected value simply falls through without executing any code.

**What messages are sent to the console? When?**  
"ledOn" and "ledOff" are printed when the led is toggled

## Internet of Cornell Tech Things

You will join a network of loosely networked Cornell Tech Things, which use the MQTT to communicate to one another. For the first step in this, we will build a simple client-server between your computer and your Interaction Engine. (Use the ``HelloThere`` and ``HelloFromHere`` code samples to do this!)

```
### Important side note
The ``HelloThere`` and ``HelloFromHere`` examples are used to use an MQTT server/broker that is no longer active. In order to test and experiment with these examples please use the ```mqtt.eclipse.org``` address.

Set up your Arduino so that it can control an RGB LED and read input from a button.
```

Now, change the code for your Interaction Engine so that you can set different buttons on a remote webpage that change the color of the RGB LED. Also, set it so that you can press a button to change the background color on the webpage. (Again, the ``HelloThere`` and ``HelloFromHere`` code samples show you how to communicate with a MQTT server. Merge the code from those samples into your interaction engine code to control the light and to send messages based on the button press.)

Now we will modify our Interaction Engine to send messages to a MQTT server/broker.  

When you start your MQTT client, you will specify “your color”. When you press your button, the client will send this color to the MQTT server, and all the other devices on the server will change their LEDs this color.

We will use ```mqtt.eclipse.org```, channel IxE for a MQTT server/broker for the course. The TA [has set up a web camera with her devices being broadcast](http://farlab.infosci.cornell.edu:8081) so that you can see if your actions change the LED of her Thing. You should be able to press your button and see the remote LED change to your color. On the remote webpage, you should be able to press a color button and see it show up on your LED.

When everyone in the class is connected to the server, everyone will be able to push their color out to everyone else’s Things by pressing their own buttons.

Technical specification:
```
MQTT_boker: mqtt.eclipse.org
Topic: ixe/
Acceptable messages (string): 'red' || 'green' || 'blue' (more to be added later)
Webcam: http://farlab.infosci.cornell.edu:8081
```

## OpenCV try out

We included 4 standard OpenCV examples in the IxE.  These examples include contour(blob) detection, face detection with the ``Haarcascade``, flow detection(a type of keypoint tracking), and standard object detection with the [Yolo](https://pjreddie.com/darknet/yolo/) darknet.

Most examples can be run with a screen (I.e. VNC or ssh -X or with an HDMI monitor), or with just the terminal. The examples are separated out into different folders. Each folder contains a ```HowToUse.md``` file, which explains how to run the python example.

```shell
pi@ixe00:~/openCV-examples $ tree -l
.
├── contours-detection
│   ├── contours.py
│   └── HowToUse.md
├── data
│   ├── slow_traffic_small.mp4
│   └── test.jpg
├── face-detection
│   ├── face-detection.py
│   ├── faces_detected.jpg
│   ├── haarcascade_eye_tree_eyeglasses.xml
│   ├── haarcascade_eye.xml
│   ├── haarcascade_frontalface_alt.xml
│   ├── haarcascade_frontalface_default.xml
│   └── HowToUse.md
├── flow-detection
│   ├── flow.png
│   ├── HowToUse.md
│   └── optical_flow.py
└── object-detection
    ├── detected_out.jpg
    ├── detect.py
    ├── frozen_inference_graph.pb
    ├── HowToUse.md
    └── ssd_mobilenet_v2_coco_2018_03_29.pbtxt
```

## Video doorbell

Now, using design a video doorbell, or any application where you can remotely control and observe action at another location. It is okay to partner up on this assignment so that you and someone else in the class have devices that communicate with one another.

** Please include video of the project **
** All supporting designs materials and code should be in your lab assignment folder, and documented enough that you could recreate it from scratch if you had memory loss. **
