# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

The build directory is `build/` (already configured). From the project root:

```bash
# Configure (first time or after CMakeLists.txt changes)
mkdir -p build && cd build && cmake ..

# Build
cd build && make

# Run
./build/ToDoList
```

On Linux, Qt6 dev packages are required: `sudo apt install qt6-base-dev qt6-tools-dev cmake build-essential`

## Architecture

This is a Qt6 Widgets desktop application (C++17) with no external dependencies beyond Qt.

- `main.cpp` — Creates `QApplication`, instantiates `MainWindow`, sets title/size, shows window
- `mainwindow.h` / `mainwindow.cpp` — The entire application UI and logic lives here

`MainWindow` uses Qt's signal/slot mechanism (no `.ui` file — layout is built programmatically in `setupUI()`). `connectSignals()` wires buttons and `QLineEdit::returnPressed` to slots. Task state (complete/incomplete) is stored directly on `QListWidgetItem` via `Qt::CheckStateRole` and font strikethrough — there is no separate data model.

CMake uses `CMAKE_AUTOMOC` to auto-generate MOC files; the `build/ToDoList_autogen/` directory is generated and should not be edited manually.
