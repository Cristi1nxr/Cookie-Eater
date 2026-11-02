# Cookie Eater

**Cookie Eater** is a lightweight Windows C utility designed to enhance browsing privacy by automatically wiping Firefox cookie data immediately after a browser session terminates.

> **Compatibility Note:** This version is made for **Mozilla Firefox** on Windows systems only.

## Features

- **Target Window Tracking:** Accepts a window title input and resolves its Process ID (PID) using Windows API functions (`FindWindow`, `GetWindowThreadProcessId`, `OpenProcess`).
- **Session Exit Synchronization:** Remains idle using `WaitForSingleObject` until the monitored process closes, ensuring data is not purged while the browser is actively in use.
- **Automated Cookie Wiping:** Executes a command prompt routine to locate and delete the `cookies.sqlite` database across all Firefox user profiles in `%APPDATA%`.

## How It Works

1. **Input:** Prompts the user to enter the target window title.
2. **Monitor:** Holds execution until the process associated with that window shuts down completely.
3. **Purge:** Removes stored cookies from `%APPDATA%\Mozilla\Firefox\Profiles\` to prevent session persistence across restarts.

## Building and Running

### Requirements
- Windows OS
- C Compiler (e.g., MinGW/GCC or Visual Studio MSVC)

### Build
```cmd
gcc main.c -o CookieEater.exe
