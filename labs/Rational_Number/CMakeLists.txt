add_library(rational_number_lib rational.h rational.cpp)

add_executable(rational_number main.cpp)
target_link_libraries(rational_number rational_number_lib)

set_property(TARGET rational_number_lib PROPERTY CXX_STANDARD 17)
set_property(TARGET rational_number PROPERTY CXX_STANDARD 17)
