cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Stack VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)

file(GLOB stack "*.h" "*.c")

add_executable(Entrypoint ${stack})