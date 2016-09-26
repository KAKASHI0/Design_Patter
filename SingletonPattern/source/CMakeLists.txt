cmake_minimum_required (VERSION 2.6)

PROJECT (SingletonPattern)

MESSAGE(STATUS ¡°This is BINARY dir¡± ${PROJECT_BINARY_DIR})
MESSAGE(STATUS ¡°This is SOURCE dir¡± ${PROJECT_SOURCE_DIR})
		
SET (SRC_LIST SingletonPattern.cpp ChocolateBoiler.cpp)


add_executable (SingletonPattern ${SRC_LIST})