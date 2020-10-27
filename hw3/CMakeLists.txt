project(hw3)


add_executable(qft qft.cpp)
target_link_libraries(qft ${QPANDA_LIBRARIES})
target_include_directories(qft PUBLIC ${QPANDA_INCLUDE_DIR})
