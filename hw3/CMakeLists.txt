project(hw3)


add_executable(qft qft.cpp)
target_link_libraries(qft ${QPANDA_LIBRARIES})
target_include_directories(qft PUBLIC ${QPANDA_INCLUDE_DIR})

add_executable(DJAlg DJ_Algorithm.cpp)
target_link_libraries(DJAlg ${QPANDA_LIBRARIES})
target_include_directories(DJAlg PUBLIC ${QPANDA_INCLUDE_DIR})

add_executable(GroverAlg Grover_Algorithm.cpp)
target_link_libraries(GroverAlg ${QPANDA_LIBRARIES})
target_include_directories(GroverAlg PUBLIC ${QPANDA_INCLUDE_DIR})

add_executable(HHLAlg HHL_Algorithm.cpp)
target_link_libraries(HHLAlg ${QPANDA_LIBRARIES})
target_include_directories(HHLAlg PUBLIC ${QPANDA_INCLUDE_DIR})
