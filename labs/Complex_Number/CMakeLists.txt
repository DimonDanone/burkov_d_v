add_library(complex_number_lib complex.h complex.cpp)

add_executable(complex_number main.cpp)
target_link_libraries(complex_number complex_number_lib)

set_property(TARGET complex_number PROPERTY CXX_STANDARD 17)
set_property(TARGET complex_number_lib PROPERTY CXX_STANDARD 17)
