import paho.mqtt.client as mqtt
import time

broker = "mqtt.eclipse.org"

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

client = mqtt.Client()
client.on_connect = on_connect
client.connect(broker, 1883, 60)
client.loop_start()

def main():
    try:
        while True:
            client.publish("ixe", "red")
            time.sleep(1)
            client.publish("ixe", "green")
            time.sleep(1)
            client.publish("ixe", "blue")
            time.sleep(1)
    except KeyboardInterrupt:
        client.disconnect()
        client.loop_stop()
        print("done")

if __name__ == '__main__':
    main()
