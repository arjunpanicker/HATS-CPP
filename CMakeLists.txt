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

find_package (Threads)

if(GEN_SHARED_LIB)
    add_library(Hats_ML SHARED ${SOURCE_FILES})
    message("Creating shared library")
else()
    # add_library(Hats_ML STATIC ${SOURCE_FILES})
    add_subdirectory(src/ft)
    add_subdirectory(src/preprocessing)

    add_executable(Hats_ML "${PROJECT_SOURCE_DIR}/src/main.cpp")

    target_link_libraries(Hats_ML PUBLIC preprocessing)
    target_link_libraries(Hats_ML PUBLIC ft)

    message("creating executable")
endif()

target_link_libraries (Hats_ML PUBLIC ${CMAKE_THREAD_LIBS_INIT})


target_include_directories(Hats_ML PUBLIC "${PROJECT_SOURCE_DIR}/include")

set_target_properties(Hats_ML PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(Hats_ML PROPERTIES LINKER_LANGUAGE CXX)

if(GEN_SHARED_LIB)
    install(TARGETS Hats_ML
        LIBRARY DESTINATION "${PROJECT_SOURCE_DIR}/bin"
        PUBLIC_HEADER DESTINATION "${PROJECT_SOURCE_DIR}/bin/include"
    )
endif()
