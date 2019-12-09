from flask import Flask, render_template, redirect, url_for, request
import serial
import time

current_milli_time = lambda: int(round(time.time() * 1000))

app = Flask(__name__)

TIMEOUT = 10

ser = serial.Serial('COM3', baudrate=115200, timeout=TIMEOUT)

lights = []

not_created = True


@app.route("/")
def index():
    return render_template("index.html", lights=lights, not_created=not_created)


@app.route("/lights-on")
def lights_on():
    light = request.args.get('light')

    command = b"coap CON POST " + bytes(light, "ASCII") + b" /led on\n"

    print(command)

    ser.write(command)
    ser.readline()

    resp = ser.readline()
    start = current_milli_time()

    while b'ACK' not in resp:
        resp = ser.readline()

        if current_milli_time() - start >= TIMEOUT * 1000:
            for i in range(0, len(lights)):
                if lights[i]["addr"] == light:
                    lights[i]["working"] = False

            return redirect(url_for("index"))

    print("ACKED")
    return redirect(url_for("index"))


@app.route("/lights-off")
def lights_off():
    light = request.args.get('light')

    command = b"coap CON POST " + bytes(light, "ASCII") + b" /led off\n"

    print(command)

    ser.write(command)
    ser.readline()

    resp = ser.readline()
    start = current_milli_time()

    while b'ACK' not in resp:
        resp = ser.readline()

        if current_milli_time() - start >= TIMEOUT * 1000:
            for i in range(0, len(lights)):
                if light == lights[i]["addr"]:
                    lights[i]["working"] = False

            return redirect(url_for("index"))

    print("ACKED")
    return redirect(url_for("index"))


@app.route("/create-network")
def create_network():
    global not_created

    ser.write(b'thr create\n')

    # read the output from the shell
    line = ser.readline()
    while line != b'\r\n':
        print(line)
        line = ser.readline()

    not_created = False
    return refresh()


@app.route("/refresh")
def refresh():
    global lights

    lights = []

    ser.write(b"getnodesip\n")

    lines = ser.readlines()

    print(lines)

    for i in range (0, len(lines)):
        if b"Received" in lines[i]:
            lights.append({
                "addr": lines[i + 2].decode("ASCII").replace("\n", "").replace("\r", ""),
                "working": True
            })

    return redirect(url_for("index"))


if __name__ == '__main__':
    app.run()