project(software-engineering)
cmake_minimum_required(VERSION 3.14.5)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# normal assert testing examples
add_executable(testing ./testing/diceTest.cpp) # same as g++ diceTest.cpp -o testing

#the below are for google testing only
add_executable(testing2 ./testing/googleTests.cpp)
target_link_libraries(testing2 gtest_main)
