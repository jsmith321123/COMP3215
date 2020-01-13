# COMP3215
Mesh network on NXP KW41z

## Web Server
To run the web server:
1. Clone the git repository
1. Modify the `config.json` file so the correct port is selected.
1. Ensure the board is plugged into the configured serial port.
1. Run `host.py`.

To control the board:
1. Open `localhost:5000` in a web browser.
1. Click the `create network` button and wait for the page to stop loading.
1. Click the `refresh` button to gather a list of all connected boards, this step will need to be repeated after the addition of new boards.
1. Use the `On` and `Off` buttons next to each light to set the state of the light, any failure in communication will be reported on the same line.

