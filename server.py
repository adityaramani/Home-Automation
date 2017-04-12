from flask import Flask, render_template, request, url_for
import threading
import serial
import sys
import time

ard =  serial.Serial('/dev/ttyACM0', 9600)
outputs= [0 for i in range(6) ]

def init():
    pass

def check():

        d = []
        while 1:
            time.sleep(1)



            if(ard.inWaiting()  > 4):
                sys.stderr.write("in if")
                while(len(d) < 6):
                    try:
                        a = input_ard.readline().strip()
                        sys.stderr.write(str(a))

                        a = int(a)
                        d.append(a)
                    except:
                        sys.stderr.write('')


                if d[0] :
                    outputs[0] = 1
                    outputs[1] = 1
                    outputs[4] = 1

                if d[1] :
                    outputs[2] = 1
                    outputs[5] = 1

                if  not d[2] :
                    outputs[1] = 0
                    outputs[2] = 0

                if d[3] :
                    outputs[4] = 0
                    outputs[5] = 1

                for i in range(6):
                        pass
                        #ard.write(str(outputs[i]).encode('utf-8'))

# Initialize the Flask application
app = Flask(__name__)

# Define a route for the default URL, which loads the form
@app.route('/toggle0', methods=['POST'])
def toogle0():
    outputs[0] = int(not outputs[0])
    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))


    return "toggled"

@app.route('/toggle1', methods=['POST'])
def toogle1():
    outputs[1] = int(not outputs[1])
    for i in range(5):
        sys.stderr.write(str(outputs[i]))

        ard.write(str(outputs[i]).encode('utf-8'))

    return "toggled"

@app.route('/toggle2', methods=['POST'])
def toogle2():
    outputs[2] = int(not outputs[2])
    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))

    return "toggled"

@app.route('/toggle3', methods=['POST'])
def toogle3():
    outputs[3] = int(not outputs[3])
    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))

    return "toggled"

@app.route('/toggle4', methods=['POST'])
def toogle4():
    outputs[4] = int(not outputs[4])
    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))

    return "toggled"

@app.route('/toggle5', methods=['POST'])
def toogle5():
    outputs[5] = int(not outputs[5])
    for i in range(5):
        sys.stderr.write(str(outputs[i]))
        ard.write(str(outputs[i]).encode('utf-8'))

    return "toggled"


if __name__ == '__main__':
    init()
    try:
        a=threading.Thread(target= check)
        #a.start()
    except:
        print("Error")
    app.run(
        host = '0.0.0.0'

        )
