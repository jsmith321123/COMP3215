from flask import Flask, render_template, redirect, url_for
import serial

app = Flask(__name__)

ser = serial.Serial('COM3')


@app.route("/")
def index():
    return render_template("index.html", message="none")


@app.route("/lights-on")
def lights_on():
    print("lights on")

    return redirect(url_for("index"))


@app.route("/lights-off")
def lights_off():
    print("lights off")

    return redirect(url_for("index"))


if __name__ == '__main__':
    while True:
        print(ser.read())

    app.run()