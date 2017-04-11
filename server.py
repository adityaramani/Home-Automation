from flask import Flask, render_template, request, url_for
import threading
import serial
import sys
import time

input_ard =  serial.Serial('/dev/ttyACM1', 1200)
input_ard.timeout= 20
output_ard = serial.Serial('/dev/ttyACM0', 1200)
outputs= [0 for i in range(6) ]

def init():
    pass

def check():
        prev = [0,0,0,0,0]
        while 1:
            d = []
            sys.stderr.write("Sleeping")
            time.sleep(1)

            sys.stderr.write("Wake")

            sys.stderr.write('\n'+str(input_ard.inWaiting()))

            if(input_ard.inWaiting()  > 4):
                sys.stderr.write("in if")
                while(len(d) < 6):
                    try:
                        a = input_ard.readline().strip()
                        sys.stderr.write(str(a))

                        a = int(a)
                        d.append(a)
                    except:
                        sys.stderr.write('')

                sys.stderr.write("after While")

                if (d[0] and prev[0] == 1):
                    outputs[0] = 9
                    outputs[1] = 9
                    outputs[4] = 9

                if d[1] and prev[1]== 1:
                    outputs[2] = 9
                    outputs[5] = 9

                if d[2] and prev[2] == 0:
                    outputs[1] = 1
                    outputs[2] = 1

                if d[3] and prev[3] ==   0:
                    outputs[4] = 0
                    outputs[5] = 1

                for i in range(5):
                    sys.stderr.write(str(d[i]))
                    output_ard.write(str(outputs[i]).encode('utf-8'))
                    #str(outputs[i]).encode('utf-8')
                prev = list(d)

# Initialize the Flask application
app = Flask(__name__)

# Define a route for the default URL, which loads the form
@app.route('/door', methods=['POST'])
def toogle():
    outputs[0] = 1
    for i in range(6):
        input_ard.write(str(outputs[i]))

@app.route('/',methods=['GET'])
def index():
    return 'Hello'



# Define a route for the action of the form, for example '/hello/'
# We are also defining which type of requests this route is
# accepting: POST requests in this case

@app.route('/h/', methods=['POST'])
def hello():

    return
# Run the app :)
if __name__ == '__main__':
    init()
    try:
        a=threading.Thread(target= check)
        a.start()
    except:
        print("Error")
    app.run(
        host = '0.0.0.0'

        )
