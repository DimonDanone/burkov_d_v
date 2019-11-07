add_executable(test_rational test.cpp)

project(test_rational)

target_link_libraries(test_rational rational)

set_property(TARGET test_rational PROPERTY CXX_STANDARD 17)
