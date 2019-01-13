cmake_minimum_required(VERSION 3.13)

#set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

#message("CXX Standard: ${CMAKE_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

project(MyTestProject)

set (
    SOURCES src/vector.cpp
)

# or use MATCHES to see if actual system name 
# Darwin is Apple's system name
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    message("This is a Windows System")
endif()

add_executable (${PROJECT_NAME} ${SOURCES})