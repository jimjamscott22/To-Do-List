# To-Do List Application

A simple and elegant to-do list application built with Qt (C++).

## Features

- ✅ Add new tasks
- ✅ Mark tasks as complete (with strikethrough effect)
- ✅ Remove individual tasks
- ✅ Clear all tasks at once
- ✅ Checkbox support for each task
- ✅ Clean and modern UI

## Prerequisites

Before building this application, you'll need:

- **Qt 6.x** (Qt Widgets module)
- **CMake 3.16 or higher**
- **C++17 compatible compiler** (MSVC, GCC, Clang, or MinGW)

## Installation & Setup

### Windows

#### 1. Install Qt 6

1. Download the Qt Online Installer from [qt.io/download-open-source](https://www.qt.io/download-open-source)
2. Run the installer and create a Qt account (free)
3. During installation, select:
   - Qt 6.x (latest stable version)
   - Under Qt 6.x, check:
     - **MSVC 2019 64-bit** (if using Visual Studio) or **MinGW 64-bit**
     - **Qt Widgets** (should be selected by default)
   - Developer and Designer Tools:
     - **CMake** (if not already installed)
     - **Ninja** (optional, for faster builds)

#### 2. Install a C++ Compiler

**Option A: Visual Studio (Recommended)**
1. Download [Visual Studio Community](https://visualstudio.microsoft.com/downloads/) (free)
2. During installation, select "Desktop development with C++"
3. This includes the MSVC compiler

**Option B: MinGW (Included with Qt)**
- If you selected MinGW during Qt installation, the compiler is already included

#### 3. Install CMake (if not included with Qt)

**Option A: Using winget (PowerShell)**
```powershell
winget install Kitware.CMake
```

**Option B: Manual Download**
1. Download from [cmake.org/download](https://cmake.org/download/)
2. Run the installer and check "Add CMake to system PATH"

#### 4. Verify Installation

Open PowerShell and verify:
```powershell
cmake --version       # Should show 3.16 or higher
```

Find your Qt installation path (typically `C:\Qt\6.x.x\msvc2019_64` or `C:\Qt\6.x.x\mingw_64`)

### macOS

#### 1. Install Qt 6

**Option A: Using Homebrew (Recommended)**
```bash
brew install qt@6
```

**Option B: Qt Online Installer**
Download from [qt.io/download-open-source](https://www.qt.io/download-open-source)

#### 2. Install Build Tools

```bash
brew install cmake
```

Xcode Command Line Tools (includes Clang compiler):
```bash
xcode-select --install
```

### Linux (Ubuntu/Debian)

#### Install all dependencies:

```bash
sudo apt update
sudo apt install qt6-base-dev qt6-tools-dev cmake build-essential
```

For other distributions, install equivalent Qt 6 development packages.

## Building the Application

### Windows with Visual Studio

1. Open PowerShell or Command Prompt
2. Navigate to the project directory:
   ```powershell
   cd d:\Code\C\To-Do-List
   ```

3. Configure the project with CMake:
   ```powershell
   mkdir build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH="C:\Qt\6.x.x\msvc2019_64"
   ```
   *(Replace `6.x.x` with your Qt version)*

4. Build the application:
   ```powershell
   cmake --build . --config Release
   ```

5. Run the application:
   ```powershell
   .\Release\ToDoList.exe
   ```

### Windows with MinGW

1. Open PowerShell
2. Navigate to the project directory:
   ```powershell
   cd d:\Code\C\To-Do-List
   ```

3. Configure and build:
   ```powershell
   mkdir build
   cd build
   cmake .. -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:\Qt\6.x.x\mingw_64"
   mingw32-make
   ```

4. Run the application:
   ```powershell
   .\ToDoList.exe
   ```

### macOS / Linux

1. Navigate to the project directory:
   ```bash
   cd ~/path/to/To-Do-List
   ```

2. Configure and build:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the application:
   ```bash
   ./ToDoList
   ```

### Alternative: Using Qt Creator

1. Open Qt Creator
2. Click **File → Open File or Project**
3. Select `CMakeLists.txt` from the project directory
4. Configure the project with your installed Qt kit
5. Click the **Run** button (green play icon) or press `Ctrl+R`

## Usage

1. **Add a Task**: Type your task in the input field and click "Add" or press Enter
2. **Mark Complete**: Select a task and click "Mark Complete" to toggle completion status
3. **Remove Task**: Select a task and click "Remove" to delete it
4. **Clear All**: Click "Clear All" to remove all tasks (with confirmation)

## Troubleshooting

### CMake can't find Qt
- Make sure to set `CMAKE_PREFIX_PATH` to your Qt installation directory
- Example: `-DCMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"`

### "make" command not found (Windows)
- Use `cmake --build .` instead of `make`
- Or use MinGW with `mingw32-make`

### Compiler not found
- Ensure Visual Studio or MinGW is properly installed
- For Visual Studio, run cmake from "Developer Command Prompt for VS"

## File Structure

```
To-Do-List/
├── main.c           # Application entry point
├── mainwindow.h     # Main window class header
├── mainwindow.cpp   # Main window implementation
├── CMakeLists.txt   # CMake build configuration
└── README.md        # This file
```

## License

This project is open source and available under the MIT License.