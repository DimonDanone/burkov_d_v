add_executable(test_complex test.cpp)

project(test_complex)

target_link_libraries(test_complex complex_number_lib)

set_property(TARGET test_complex PROPERTY CXX_STANDARD 17)
