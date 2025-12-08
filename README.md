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

- Qt 6.x (Qt Widgets module)
- CMake 3.16 or higher
- C++17 compatible compiler

## Building the Application

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
./ToDoList
```

### Using qmake (Alternative)

Create a `.pro` file or use Qt Creator to open the project.

## Usage

1. **Add a Task**: Type your task in the input field and click "Add" or press Enter
2. **Mark Complete**: Select a task and click "Mark Complete" to toggle completion status
3. **Remove Task**: Select a task and click "Remove" to delete it
4. **Clear All**: Click "Clear All" to remove all tasks (with confirmation)

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