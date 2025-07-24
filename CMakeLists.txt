cmake_minimum_required(VERSION 3.10)

project(ChessGame)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCES "src/Board.cpp" 
            "src/Pawn.cpp"
            "src/Main.cpp")

add_executable(ChessGame ${SOURCES})