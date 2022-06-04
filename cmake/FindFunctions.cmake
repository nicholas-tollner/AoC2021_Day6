set(CMAKE_PREFIX_PATH $ENV{LIB}/functions)

find_path(FUNCTIONS_INCLUDE_DIR strings.h file.h
        PATH SUFFIXES include
        PATHS ${CMAKE_PREFIX_PATH})

find_library(FUNCTIONS_LIBRARY
        NAMES functions
        HINTS ${CMAKE_PREFIX_PATH}/lib)