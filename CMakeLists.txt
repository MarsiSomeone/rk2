cmake_minimum_required(VERSION 3.14)
project(MonsterPetAdapter VERSION 1.0.0)

set(PRINT_VERSION_MAJOR 0)
set(PRINT_VERSION_MINOR 1)
set(PRINT_VERSION_PATCH 0)
set(PRINT_VERSION_TWEAK 0)
set(PRINT_VERSION "${PRINT_VERSION_MAJOR}.${PRINT_VERSION_MINOR}.${PRINT_VERSION_PATCH}.${PRINT_VERSION_TWEAK}")
set(PRINT_VERSION_STRING "v${PRINT_VERSION}")

set(PROJECT_VERSION ${PRINT_VERSION})
set(CMAKE_CXX_STANDARD 17)


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(monster_pet monster_and_pet.cpp)
target_include_directories(monster_pet PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTS)
    enable_testing()
    add_executable(a_test tests/a_test.cpp)
    target_link_libraries(a_test gtest_main)
    target_include_directories(a_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    add_test(NAME Test COMMAND a_test)
endif()


include(CPackConfig.cmake)
