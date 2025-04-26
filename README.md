# ESP-Robot

This repository contains the PlatformIO project for the **ESP32 Development Board** used in the **Hazard Detection Robot** project.

## How to Use

1. **Clone this repository**:
    ```bash
    git clone https://github.com/jithangowda/ESP-Robot.git
    ```

2. **Download and Install Visual Studio Code**:
    - Go to [VSCode Downloads](https://code.visualstudio.com/Download) and install it.

3. **Install the PlatformIO Extension** inside Visual Studio Code:
    - Open VSCode, go to Extensions (`Ctrl+Shift+X`).
    - Search for **PlatformIO IDE** and click Install.

4. **Open the cloned project**:
    - After installing PlatformIO, open VSCode and click the **PlatformIO** icon in the left sidebar.
    - Click **Open Project** and select the folder where you cloned this repo.

5. **Build and Upload** using PlatformIO interface:
    - In the PlatformIO toolbar (at the bottom), click **Build** to compile the code.
    - Once the build is successful, click **Upload** to flash the code to your ESP32.

6. **Connect to Wi-Fi**:
    - After uploading, the ESP32 will start a temporary Wi-Fi network named **ESP32_Robot**.
    - Connect to this network using the password: `robot123`.
    - A configuration page will appear where you can set your home Wi-Fi credentials.
    - After configuration, the ESP32 will automatically reconnect to your Wi-Fi in future boots.

## Requirements

- ESP32 Development Board
- Visual Studio Code
- PlatformIO Extension
