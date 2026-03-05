project(cori_cli)

add_executable(cori_cli main.cpp)

target_link_libraries(cori_cli PRIVATE cori_lib)
