set(PREPROCESSING_FILES
    src/datasethandler.cpp
    src/preprocessing.cpp
)

set(PREPROCESSING_HEADER_FILES
    include/real.h
    include/datasethandler.h
    include/preprocessing.h
)

add_library(preprocessing ${PREPROCESSING_FILES})

target_include_directories(preprocessing
    PUBLIC include
)

target_include_directories(preprocessing
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)