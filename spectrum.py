import serial
import matplotlib
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from drawnow import *

ser = serial.Serial('COM3', 11200)

plt.ion()
fig = plt.figure()
rects = None


def get_data():
    while(ser.inWaiting()==0):
        pass

    data = ser.readline()
    print data
    amps = data.split("\t")
    amps = amps[:-1]
    print amps
    amps = [float(amp) for amp in amps]
    return len(amps) == 7, amps

def make_graph(data):
    rects = plt.bar(range(len(data)), data,  align = 'center', color='r')
    for rect, h in zip(rects, data):
            rect.set_height(h)
    fig.canvas.draw()


def main():

    while(1):
        status, data = get_data()
        if not status:
            continue
        make_graph(data)
        plt.pause(.0001)

if __name__ == '__main__':
    main()
