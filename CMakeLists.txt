CMAKE_MINIMUM_REQUIRED(VERSION 3.29)

PROJECT(nowire
        LANGUAGES C
        VERSION 0.1
        DESCRIPTION "Sistema de Navigação Inercial")


INCLUDE_DIRECTORIES(includes)

ADD_EXECUTABLE(nowire src/main.c)

