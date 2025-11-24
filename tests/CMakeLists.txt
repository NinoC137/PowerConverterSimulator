file(GLOB TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(sim_tests ${TEST_SRC})
target_link_libraries(sim_tests PRIVATE simcore)

add_test(NAME basic_tests COMMAND sim_tests)