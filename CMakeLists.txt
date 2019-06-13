cmake_minimum_required(VERSION 3.7)
project(StateReportableExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (BRAND_FULLNAME "StateReportableExample")
set (BRAND_COMPANYNAME "ADDubovik")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_library(STATE_REPORTABLE_LIB_DEBUG   NAMES StateReportable_lib.lib)
find_library(STATE_REPORTABLE_LIB_RELEASE NAMES StateReportable_lib.lib)

add_subdirectory(src)
