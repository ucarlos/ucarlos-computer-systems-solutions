cmake_minimum_required(VERSION 3.8)
project(Bryant_Operating_Systems_Assignments)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    "Chapter 2/Byte Representation.c"
    "Chapter 2/Chapter2_Functions.c"
    "Chapter 2/Example2_14.c"
    "Chapter 2/Example2_15.c"
    "Chapter 2/Example2_2.c"
    "Chapter 2/Fast_InverseSqrt.c"
    "Chapter 2/Float_to_Binary.c"
    "Chapter 2/Inttobin.c"
    "Chapter 2/main.c"
    "Chapter 2/Problem2_13.c"
    "Chapter 2/Problem2_23.c"
    "Chapter 2/Problem2_25.c"
    "Chapter 2/Problem2_26.c"
    "Chapter 2/Problem2_30.c"
    "Chapter 2/Problem2_32.c"
    "Chapter 2/Problem2_36.c"
    "Chapter 2/Problem2_42.c"
    "Chapter 2/Problem2_43.c"
    "Chapter 2/Problem2_74.c"
    "Midterm Files/Midterm_2_Test.c"
    "Midterm Files/Midterm_3.c"
    "Midterm Files/Midterm_4.c"
    common_header.h
    Test.c)

add_executable(Bryant_Operating_Systems_Assignments ${SOURCE_FILES})