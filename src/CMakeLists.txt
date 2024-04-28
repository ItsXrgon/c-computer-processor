cmake_minimum_required(VERSION 3.12)
project(c-computer-processor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add source files
set(SOURCES
    src/Main.c
    src/ALU/ALU.c
    src/DataMemory/DataMemory.c
    src/InstructionMemory/InstructionMemory.c
    src/Registers/Registers.c
    # Add more source files here if needed
)

# Add executable target
add_executable(computer_processor ${SOURCES})

# Add include directories
target_include_directories(computer_processor PRIVATE include)