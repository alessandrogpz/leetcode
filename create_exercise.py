import os
import sys
import json

# Paths to key files
CMAKE_FILE = "CMakeLists.txt"
TASKS_FILE = ".vscode/tasks.json"

# Template content for each file
APPROACH_MD_TEMPLATE = """

"""

MAIN_CPP_TEMPLATE = """
#include <iostream>
#include "functions.h"

int main(int argc, char *argv[]) 
{

    return 0;
}
"""

FUNCTIONS_CPP_TEMPLATE = """
#include "functions.h"

"""

FUNCTIONS_H_TEMPLATE = """
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#endif
"""

TEST_CPP_TEMPLATE = """
#define BOOST_TEST_MODULE {exercise_name}
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

"""

def create_exercise_folder(base_path, exercise_name):
    # Create exercise folder
    exercise_path = os.path.join(base_path, exercise_name)
    os.makedirs(exercise_path, exist_ok=True)

    # Create necessary files
    with open(os.path.join(exercise_path, "approach.md"), "w") as f:
        f.write(APPROACH_MD_TEMPLATE)
    with open(os.path.join(exercise_path, "main.cpp"), "w") as f:
        f.write(MAIN_CPP_TEMPLATE)
    with open(os.path.join(exercise_path, "functions.cpp"), "w") as f:
        f.write(FUNCTIONS_CPP_TEMPLATE)
    with open(os.path.join(exercise_path, "functions.h"), "w") as f:
        f.write(FUNCTIONS_H_TEMPLATE)
    with open(os.path.join(exercise_path, "test.cpp"), "w") as f:
        f.write(TEST_CPP_TEMPLATE.format(exercise_name=exercise_name))

    print(f"Exercise folder and files created: {exercise_path}")
    return exercise_path

def update_cmake(active_problem):
    with open(CMAKE_FILE, "r") as f:
        lines = f.readlines()

    # Update the ACTIVE_PROBLEM line
    with open(CMAKE_FILE, "w") as f:
        for line in lines:
            if line.strip().startswith("set(ACTIVE_PROBLEM"):
                f.write(f'set(ACTIVE_PROBLEM "{active_problem}")  # Example problem\n')
            else:
                f.write(line)

    print(f"Updated {CMAKE_FILE} with ACTIVE_PROBLEM: {active_problem}")

def update_tasks_json(active_problem):
    # Read the tasks.json file
    with open(TASKS_FILE, "r") as f:
        tasks_data = json.load(f)

    # Replace the args section with the new exercise name
    args = [
        "-g",
        f"${{workspaceFolder}}\\exercises\\{active_problem}\\main.cpp",
        f"${{workspaceFolder}}\\exercises\\{active_problem}\\functions.cpp",
        "-o",
        f"${{workspaceFolder}}\\exercises\\{active_problem}\\${{fileBasenameNoExtension}}.exe"
    ]

    # Update args for the first task (assuming it's the build task)
    for task in tasks_data.get("tasks", []):
        if "args" in task:
            task["args"] = args

    # Write back the updated tasks.json
    with open(TASKS_FILE, "w") as f:
        json.dump(tasks_data, f, indent=4)

    print(f"Updated {TASKS_FILE} for active problem: {active_problem}")

def main():
    # Base path for exercises
    base_path = os.path.join(os.getcwd(), "exercises")

    # Get exercise name from the user
    if len(sys.argv) != 2:
        print("Usage: python create_exercise.py <active_problem>")
        sys.exit(1)

    active_problem = sys.argv[1]

    # Create exercise folder and files
    exercise_path = create_exercise_folder(base_path, active_problem)

    # Update CMakeLists.txt
    update_cmake(active_problem)

    # Update tasks.json
    update_tasks_json(active_problem)

if __name__ == "__main__":
    main()