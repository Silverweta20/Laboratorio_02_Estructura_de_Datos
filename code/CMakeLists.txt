cmake_minimum_required(VERSION 3.31)
project(code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(code
    DataPoint.h
    DataSet.h
    DataSet.hxx
    EvaluationSystem.h
    EvaluationSystem.hxx
    LinearRegression.h
    LinearRegression.hxx
    main.cxx)
