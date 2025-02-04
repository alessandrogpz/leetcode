## **Project Structure**

```plaintext
project-root/
├── CMakeLists.txt        # Centralized CMake configuration
├── build/                # Single build directory for all problems
├── exercises/            # Folder containing all problems
│   ├── problem1/         # Example problem folder
|   |   ├── approach.md
│   │   ├── functions.cpp
│   │   ├── functions.h
│   │   ├── main.cpp
│   │   └── test.cpp
│   ├── problem2/         # Another problem folder
|   |   ├── approach.md
│   │   ├── functions.cpp
│   │   ├── functions.h
│   │   ├── main.cpp
│   │   └── test.cpp
│   └── ...               # Additional problem folders
├── scripts/
│   └── create_exercise.py # Python script for automating problem setup
├── .vscode/
│   └── tasks.json        # VS Code build configuration
```

---

## **Working with the Configuration**

This project uses a **centralized `CMakeLists.txt` file** to manage all exercises. A single `build/` directory is used for all build files. You specify the problem you want to build by changing the **name of the active problem folder** in the `CMakeLists.txt` file.

---

### **1. Automating Problem Setup**

The `create_exercise.py` script automates the creation of problem folders and updates configurations, saving time and reducing errors.

#### **Using the Script**

1. Navigate to the project root.
2. Run the script with the new problem name as the argument:
   ```bash
   python scripts/create_exercise.py <problem_name>
   ```

#### **Example**

To create a new problem named `1234.NewProblem`, run:

```bash
python scripts/create_exercise.py 1234.NewProblem
```

#### **What It Does**

- Creates a new folder under `exercises/` with the following structure:
  ```plaintext
  exercises/1234.NewProblem/
  ├── approach.md
  ├── functions.cpp
  ├── functions.h
  ├── main.cpp
  └── test.cpp
  ```
- Updates the `ACTIVE_PROBLEM` line in `CMakeLists.txt`:
  ```cmake
  set(ACTIVE_PROBLEM "1234.NewProblem")
  ```
- Updates the `args` section in `.vscode/tasks.json` to point to the new files.

---

### **2. Setting the Active Problem Manually**

If you prefer manual updates:

1. Open the `CMakeLists.txt` file.
2. Locate the line:
   ```cmake
   set(ACTIVE_PROBLEM "problem1")
   ```
3. Replace `"problem1"` with the name of the new problem folder, e.g.:
   ```cmake
   set(ACTIVE_PROBLEM "1234.NewProblem")
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
   cmake -DCMAKE_TOOLCHAIN_FILE="<path_to_vcpkg>/scripts/buildsystems/vcpkg.cmake" ..
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
   ./build/bin/Debug/main_program
   ```

2. Run the test program:
   ```bash
   ./build/bin/Debug/test_program
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
  set(BOOST_ROOT "<path_to_vcpkg>/installed/x64-mingw-dynamic")
  ```

### **2. Symbol Conflicts**

If you see errors about multiple definitions of `main()`, ensure the `CMakeLists.txt` file correctly separates source files for `main_program` and `test_program`.

---
