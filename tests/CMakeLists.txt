# Glob test source files
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Create a single test executable
add_executable(FFT_tests ${TEST_FILES})

target_include_directories(FFT_tests
    PRIVATE ${CMAKE_SOURCE_DIR}/include
    PRIVATE ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(FFT_tests PRIVATE FFTLib)

# Register with CTest
add_test(NAME FFT_tests COMMAND FFT_tests)
