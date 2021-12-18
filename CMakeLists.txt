cmake_minimum_required(VERSION 3.14)

# entry name
project(cmake-gtest)

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if (ENABLE_UNIT_TESTS)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(a1_test  tests/test.cpp tests/main.cpp)

target_link_libraries(a1_test
  	PRIVATE
    	gtest

)

enable_testing()
add_test(
  	NAME google_test
  	COMMAND $<TARGET_FILE:a1_test>
 )