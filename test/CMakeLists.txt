cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
add_subdirectory(googletest)

add_executable(runAllTests
	CharacterTest.cpp
	Dice_class_test.cpp
	EnemyTest.cpp
	PlayerTest.cpp
	GameTest.cpp
	WeaponTest.cpp
	PointTest.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)

