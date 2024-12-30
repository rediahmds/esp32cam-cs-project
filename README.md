# Alat Pemantauan Kucing

## Getting Started

### Prerequisites

- [Visual Studio Code (VSCode)](https://code.visualstudio.com/) installed on your computer.
- PlatformIO extension installed on your VSCode. You can follow the installation guide [here](https://platformio.org/install/ide?install=vscode).

> [!NOTE]
For first time user, it might take some time to install the required tools and dependencies, so prepare a cup of coffee while waiting :coffee:.

### Installation

#### 1. Clone the repository

Clone this repository to your local machine using the following command:

```bash
git clone https://github.com/rediahmds/esp32cam-cs-project.git
```

#### 2. Configure git submodules

This project uses git submodules to manage the firmware version. To open and configure the submodules, run the following commands:

- On Linux or macOS:

```bash
cd esp32cam-cs-project
chmod +x setup.sh
./setup.sh
code .
```

- On Windows:

```ps1
cd esp32cam-cs-project
.\setup.bat
code .
```

> [!NOTE]
If VSCode is not opened, you can open it manually and open the project directory.

#### 3. Set up the project environment with PlatformIO

If you have installed the PlatformIO extension on your VSCode, it will automatically detect the `platformio.ini` file and install the required tools and dependencies. If the setup is successful, you will see something like this:

![PlatformIO successfully setup the project](/assets/guide/pio-config-success.png)

> [!NOTE]
> This process might take some time, so drink your coffee while waiting :coffee:.

#### 4. Configure credentials

There are two files that you need to configure before uploading the firmware to the ESP32-CAM board:

- `src/iot/credentials.h`: This file contains the credentials for the [Blynk](https://blynk.io/) server, Wi-Fi, and access point. You can copy the `src/iot/credentials.example.h` file and rename it to `src/iot/credentials.h`. Then, fill in the credentials accordingly.
- `src/ota/credentials.h`: This file contains the credentials for the [ElegantOTA](https://docs.elegantota.pro/) server. You can copy the `src/ota/credentials.example.h` file and rename it to `src/ota/credentials.h`. Then, fill in the credentials accordingly.

#### 5. Build and upload the firmware to the ESP32-CAM board

Before uploading the firmware, make sure you have connected the ESP32-CAM board to your computer using a USB cable. Then, follow these steps:

- To build the firmware, just click the `✓` icon on the bottom toolbar of the VSCode or press `Ctrl + Alt + B` on your keyboard.
- To upload the firmware, click the `➡` icon on the bottom toolbar of the VSCode or press `Ctrl + Alt + U` on your keyboard.

The build and upload process will take some time, so drink your coffee while waiting :coffee:. If the process is successful, you will see something like this:

![PlatformIO successfully uploaded the firmware](/assets/guide/pio-build-upload-success.png)

## Roadmap

- [ ] Implement websocket server for real-time communication with the client.
- [ ] Integate the websocket server with a flutter app.
- [ ] Implement webserial for wireless serial logging.
