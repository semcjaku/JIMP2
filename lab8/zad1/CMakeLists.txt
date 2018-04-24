
project(zad1)

set(HEDEAR_FILES Zad1.h)
set(SOURCE_FILES Zad1.cpp)

add_library(libzad1 STATIC ${SOURCE_FILES})
target_include_directories(libzad1 PUBLIC .)

add_executable(zad1 ${SOURCE_FILES} main.cpp)

target_link_libraries(zad1 libzad1)
