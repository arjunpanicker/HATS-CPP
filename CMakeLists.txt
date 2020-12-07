cmake_minimum_required(VERSION 3.10)

project(Hats_ML VERSION 1.0 DESCRIPTION "ML Module for HATS")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CXXFLAGS "-lthread -pthread -lm")

set(HEADER_FILES
    include/args.h
    include/autotune.h
    include/config.h
    include/datasethandler.h
    include/densematrix.h
    include/dictionary.h
    include/Fasttext.h
    include/loss.h
    include/matrix.h
    include/meter.h
    include/model.h
    include/pch.h
    include/preprocessing.h
    include/productquantizer.h
    include/quantmatrix.h
    include/real.h
    include/utils.h
    include/vector.h
)

set(SOURCE_FILES
    src/args.cpp
    src/autotune.cpp
    src/datasethandler.cpp
    src/densematrix.cpp
    src/dictionary.cpp
    src/Fasttext.cpp
    src/loss.cpp
    src/matrix.cpp
    src/meter.cpp
    src/model.cpp
    src/preprocessing.cpp
    src/productquantizer.cpp
    src/quantmatrix.cpp
    src/utils.cpp
    src/vector.cpp
)

add_library(Hats_ML SHARED ${SOURCE_FILES})

target_include_directories(Hats_ML PUBLIC "${PROJECT_SOURCE_DIR}/include")

set_target_properties(Hats_ML PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS Hats_ML
    LIBRARY DESTINATION "${PROJECT_SOURCE_DIR}/bin"
    PUBLIC_HEADER DESTINATION "${PROJECT_SOURCE_DIR}/bin/include"
)
