cmake_minimum_required(VERSION 3.15)
project(M2OEP)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        Deck.cpp
        Deck.h
        Card.cpp
        Card.h
        main.cpp
)

add_executable(test
        Deck.cpp
        Deck.h
        Card.h
        Card.cpp
        testing.cpp
)
