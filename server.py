from flask import Flask, render_template, request, url_for
import threading
import serial
import sys
import time

ard =  serial.Serial('/dev/ttyACM0', 9600)
outputs= [0 for i in range(5) ]

# Initialize the Flask application
app = Flask(__name__)

# Define a route for the default URL, which loads the form
@app.route('/door', methods=['POST'])
def door():
    outputs= [0 for i in range(5) ]

    outputs[0] = int(request.form.get('data'))
    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))
    return "door = " + str(outputs[0])


@app.route('/light', methods=['POST'])
def light():
    outputs= [0 for i in range(5) ]

    outputs[2] = int(request.form.get('data'))

    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))

    return "light = " + str(outputs[2])


@app.route('/fan', methods=['POST'])
def fan():
    outputs= [0 for i in range(5) ]

    outputs[3] = int(request.form.get('data'))
    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))
    return "fan = " + str(outputs[3])

@app.route('/pool', methods=['POST'])
def pool():
    outputs= [0 for i in range(5) ]
    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))
    return "All off"


if __name__ == '__main__':
    app.run(
        host = '0.0.0.0'

        )
