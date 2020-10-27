from flask import Flask, Response, render_template
from imutils.video import VideoStream

app = Flask(__name__)

@app.route('/')
def index():
    return 'This is Darren\'s server!'

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')