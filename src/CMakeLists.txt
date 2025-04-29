# Glob all source and private header files
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/include/*.h
)

add_library(FFTLib STATIC ${SRC_FILES} ${HEADER_FILES})

source_group("Header Files" FILES ${HEADER_FILES})

# Include both public and private headers
target_include_directories(FFTLib 
    PUBLIC ${CMAKE_SOURCE_DIR}/include       # Headers for users of the library
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}      # Internal/private headers
)
