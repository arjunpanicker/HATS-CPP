cmake_minimum_required(VERSION 3.10)

project(Hats_ML VERSION 1.0 DESCRIPTION "ML Module for HATS")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CXXFLAGS "-lpthread -pthread -lm")

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
    include/preprocessing.h
    include/productquantizer.h
    include/quantmatrix.h
    include/real.h
    include/utils.h
    include/vector.h
)

set(SOURCE_FILES
    src/ft/src/args.cpp
    src/ft/src/autotune.cpp
    src/preprocessing/src/datasethandler.cpp
    src/ft/src/densematrix.cpp
    src/ft/src/dictionary.cpp
    src/ft/src/Fasttext.cpp
    src/ft/src/loss.cpp
    src/ft/src/matrix.cpp
    src/ft/src/meter.cpp
    src/ft/src/model.cpp
    src/preprocessing/src/preprocessing.cpp
    src/ft/src/productquantizer.cpp
    src/ft/src/quantmatrix.cpp
    src/ft/src/utils.cpp
    src/ft/src/vector.cpp
)

find_package (Threads)

if(GEN_SHARED_LIB)
    add_library(Hats_ML SHARED ${SOURCE_FILES})
    target_include_directories(Hats_ML PUBLIC 
        "${PROJECT_SOURCE_DIR}/src/ft/include"
        "${PROJECT_SOURCE_DIR}/src/preprocessing/include"
    )
    message("Creating shared library")
else()
    add_subdirectory(src/ft)
    add_subdirectory(src/preprocessing)

    add_executable(Hats_ML "${PROJECT_SOURCE_DIR}/src/main.cpp")

    target_link_libraries(Hats_ML PUBLIC preprocessing)
    target_link_libraries(Hats_ML PUBLIC ft)

    message("creating executable")
endif()

target_link_libraries (Hats_ML PUBLIC ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(Hats_ML PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(Hats_ML PROPERTIES LINKER_LANGUAGE CXX)

if(GEN_SHARED_LIB)
    install(TARGETS Hats_ML
        LIBRARY DESTINATION "${PROJECT_SOURCE_DIR}/bin"
        PUBLIC_HEADER DESTINATION "${PROJECT_SOURCE_DIR}/bin/include"
    )
endif()
