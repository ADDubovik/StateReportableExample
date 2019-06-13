
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/StateReportable.config" "report.txt")

set(SRC
	main.cpp
	SomethingAsynchronous.cpp
	SomethingAsynchronous.h
	SomethingAsynchronousReportable.cpp
	SomethingAsynchronousReportable.h
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/3rdparty/StateReportable/src
)

set(STATE_REPORTABLE_LIB
	optimized ${STATE_REPORTABLE_LIB_RELEASE}
	debug     ${STATE_REPORTABLE_LIB_DEBUG}
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
	${STATE_REPORTABLE_LIB}
)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION .)
INSTALL(FILES StateReportable.config DESTINATION .)
