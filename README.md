# **Project Documentation**

This document provides an overview of the project structure, instructions for working with this configuration, and detailed steps for building and running exercises using **CMake**.

---

## **Project Structure**

```plaintext
project-root/
├── CMakeLists.txt    # Centralized CMake configuration
├── build/            # Single build directory for all problems
├── exercises/        # Folder containing all problems
│   ├── problem1/     # Example problem folder
│   │   ├── functions.cpp
│   │   ├── functions.h
│   │   ├── main.cpp
│   │   └── test.cpp
│   ├── problem2/     # Another problem folder
│   │   ├── functions.cpp
│   │   ├── functions.h
│   │   ├── main.cpp
│   │   └── test.cpp
│   └── ...           # Additional problem folders
```

---

## **Working with the Configuration**

This project uses a **centralized `CMakeLists.txt` file** to manage all exercises, and a single `build/` directory is used for all build files. You specify the problem you want to build by changing the **name of the active problem folder** in the `CMakeLists.txt` file.

### **1. Setting the Active Problem**

1. Open the `CMakeLists.txt` file in the root directory.
2. Locate the line:
   ```cmake
   set(ACTIVE_PROBLEM "problem1")
   ```
3. Update the value of `ACTIVE_PROBLEM` to the folder name of the exercise you want to work on. For example:
   ```cmake
   set(ACTIVE_PROBLEM "problem2")
   ```

---

## **Steps for Building and Running an Exercise**

### **Step 1: Set Up the Environment**

Ensure the following dependencies are installed:

1. **CMake**: Install it from [cmake.org](https://cmake.org/download/) and verify with:
   ```bash
   cmake --version
   ```
2. **vcpkg**: Clone the repository, bootstrap it, and integrate it with your system:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.bat
   vcpkg integrate install
   ```
3. Install **Boost** using vcpkg:
   ```bash
   vcpkg install boost-test:x64-mingw-dynamic
   ```

---

### **Step 2: Configure the Project**

1. Navigate to the project root and create the `build/` directory:

   ```bash
   cd project-root
   mkdir build
   cd build
   ```

2. Run CMake to configure the project, specifying the toolchain file for vcpkg:

   ```bash
   cmake -DCMAKE_TOOLCHAIN_FILE="C:/Program Files/vcpkg/scripts/buildsystems/vcpkg.cmake" ..
   ```

   This step generates build files in the `build/` directory.

---

### **Step 3: Build the Exercise**

1. Build the project:

   ```bash
   cmake --build .
   ```

2. CMake will generate two executables in the `bin/` directory:
   - `main_program.exe`: The main program for the exercise.
   - `test_program.exe`: The unit tests for the exercise.

---

### **Step 4: Run the Executables**

1. Run the main program:

   ```bash
   ./bin/main_program
   ```

2. Run the test program:
   ```bash
   ./bin/test_program
   ```

---

## **Troubleshooting**

### **1. Boost Not Found**

- Ensure Boost is installed via vcpkg:
  ```bash
  vcpkg install boost-test:x64-mingw-dynamic
  ```
- Verify the paths to Boost in the `CMakeLists.txt` file:
  ```cmake
  set(BOOST_ROOT "C:/Program Files/vcpkg/installed/x64-mingw-dynamic")
  ```

### **2. Symbol Conflicts**

If you see errors about multiple definitions of `main()`, ensure the `CMakeLists.txt` file correctly separates source files for `main_program` and `test_program`.

---

## **Adding a New Problem**

1. Create a new folder under `exercises/`:

   ```
   exercises/new_problem/
   ├── functions.cpp
   ├── functions.h
   ├── main.cpp
   └── test.cpp
   ```

2. Update `ACTIVE_PROBLEM` in `CMakeLists.txt`:

   ```cmake
   set(ACTIVE_PROBLEM "new_problem")
   ```

3. Follow the steps to configure, build, and run the project.

---

## **Summary**

- Organize problems under the `exercises/` folder.
- Use the `ACTIVE_PROBLEM` variable in `CMakeLists.txt` to select the problem to build.
- Use a single `build/` directory to avoid clutter.
- Output executables are placed in the `bin/` directory for easy access.
