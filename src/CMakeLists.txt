cmake_minimum_required(VERSION 3.12)
project(MyChessBot VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files here
set(SOURCES
main.cpp
Board/Board.cpp
Board/generateLegalMoves.cpp
Board/initDefaultBoard.cpp
Board/initFenBoard.cpp
Board/printBoard.cpp
Board/resetBoard.cpp
Uci/Uci.cpp
# Add more source files as needed
)

# Add your header files here
set(HEADERS
Board/Board.h
Uci/Uci.h
Board/chessLookUp.hpp
    # Add more header files as needed
)

# Add any additional dependencies here
set(DEPENDENCIES
# Add your dependencies here
)

# Set the executable name and link the dependencies
add_executable(MyChessBot ${SOURCES} ${HEADERS})
target_link_libraries(MyChessBot ${DEPENDENCIES})


