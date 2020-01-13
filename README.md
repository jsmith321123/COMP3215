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

## Board
Due to complications in generating a makefile which is not specific to only one machine, MCUXpresso must be downloaded in order to make the project and flash it to the board.
1. Download MCUXpresso, https://mcuxpresso.nxp.com/en/welcome, and select the KW41z as the development board.
1. With this downloaded, clone the code from this git repository.
1. Open the code under the folder board as a new project in MCUxpresso, and build the project.
1. Plug the board into the computer, and select the blue debug option, and step through it. The code will then be flashed onto the board.
1. Repeat for all boards.

Optional Alternative:
Due to the limited scope in which we edited this code from the base example, the code can be copied directly from the SDK.
1. Ensure that the SDK includes example projects.
1. Open new project.
1. Select import SDK examples, press next.
1. Select the board, press next.
1. Under wireless examples and thread, select router eligible device. 
1. Select UART and not semihost, press next.
1. Select Finish.
1. Now build and flash as detailed above.

How to Set Up Network Settings:
1. Go to nwk_ip/app/config/app_thread_config.h
1. On line 192, change the THR_PSK_D to your chosen passphrase, and edit the number to the length of the new passphrase.
1. On line 203, change the THR_NETWORK_NAME to your chosen network name, and update length.

How to use mac filter to test routing:
1. Use Get Neighbor to obtain the mac address of other boards on the network.
1. Use mac filter in the following way “macfilter add [mac address] reject 1” in order to reject packets from this mac address.
1. If other nodes are on the network, this should not affect control.

