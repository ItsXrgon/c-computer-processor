cmake_minimum_required(VERSION 3.12)
project(c-computer-processor VERSION 1.0.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 11)

# Assuming your header files are in a folder named "headers"
include_directories(Headers)


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
add_executable(c-computer-processor  ${SOURCES})

# Add include directories
target_include_directories(c-computer-processor PUBLIC include)


