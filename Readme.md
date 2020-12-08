# HATS - ML Module

This project is part of the HATS Android App project. This project contains the implementation of:
1. Fasttext word embedding generation
2. Multinomial Logistic Regression
3. Data Preprocessing

## Project Structure
The project structure is as follows:
```
    - bin
    - build
    - doc
        - dataset
    - src
        - ft
            - include
            - src
            CMakeLists.txt
        - preprocessing
            - include
            - src
            CMakeLists.txt
    CMakeLists.txt
    build.sh
    Readme.md
    .gitignore
```

The `bin` and `build` folders should be created separately.

To build the project, one needs to install `cmake` and `g++` in linux. Then, one can run the `build.sh` file to build the file.
The output file will be present in the build directory with the name `Hats_ML`.