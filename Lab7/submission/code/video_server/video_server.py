from flask import Flask, Response, render_template
from imutils.video import VideoStream
import io
import socket
import datetime
import imutils
import time
import cv2
import paho.mqtt.client as mqtt
import serial

##--------------MQTT-------------------------
broker = "mqtt.eclipse.org"

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("ixe")

def on_message(client, userdata, msg):
    message = str(msg.payload.decode("utf-8"))
    print("received message = " + message)
    if("red" in message):
        print(b'r')
        ser.write(b'r')
    elif("green" in message):
        print(b'g')
        ser.write(b'g')
    elif("blue" in message):
        print(b'b')
        ser.write(b'b')

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(broker, 1883, 60)
client.loop_start()

ser = serial.Serial('/dev/ttyUSB1', 9600)
ser.flushInput()

app = Flask(__name__)

##---------------Server & Video-----------------------

vs = VideoStream(src=0).start()
time.sleep(2)

@app.route('/')
def index():
    return render_template("index.html")

def gen():
    try:
        while True:
            frame = vs.read()
            frame = imutils.resize(frame, width=400)
            timestamp = datetime.datetime.now()
            cv2.putText(frame, timestamp.strftime("%A %d %B %Y %I:%M:%S%p"), (10, frame.shape[0] - 10),cv2.FONT_HERSHEY_SIMPLEX, 0.35, (0, 0, 255), 1)
            cv2.imwrite('pic.jpg', frame)
            yield (b'--frame\r\n'b'Content-Type: image/jpeg\r\n\r\n' + open('pic.jpg', 'rb').read() + b'\r\n')

    except KeyboardInterrupt:
        client.disconnect()
        client.loop_stop()

@app.route('/video_feed')
def video_feed():
   """Video streaming route. Put this in the src attribute of an img tag."""
   return Response(gen(),
                   mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0')
