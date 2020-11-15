include(CTest)

# Add gtest/gmock support
include(${cmakeAddonsDir}/addgtestsupport.cmake)

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

set(TESTCTGT testltemplate)

add_executable(${TESTCTGT}
    soundextest.cpp
)

# includes the base project includes
target_include_directories(${TESTCTGT}
    PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Add the dependency to the target under test
target_link_libraries(${TESTCTGT} PRIVATE ${CTGT})

target_compile_options(${TESTCTGT} PRIVATE -Werror)
target_compile_features(${TESTCTGT} PRIVATE cxx_std_11)

# Trivial example using gtest and gmock
target_link_libraries(${TESTCTGT} PRIVATE gtest gmock_main)
add_test(NAME example_test COMMAND ${TESTCTGT})

