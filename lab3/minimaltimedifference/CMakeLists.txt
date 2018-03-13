
project(minmaltimedifference)

set(HEDEAR_FILES MinmalTimeDifference.h)
set(SOURCE_FILES MinmalTimeDifference.cpp)

add_library(libminmaltimedifference STATIC ${SOURCE_FILES})
target_include_directories(libminmaltimedifference PUBLIC .)

add_executable(minmaltimedifference ${SOURCE_FILES} main.cpp)

target_link_libraries(minmaltimedifference libminmaltimedifference)
