project(cori_cli)

add_executable(cori_cli main.cpp
        Option.cpp
        Option.h
        OptionManager.cpp
        OptionManager.h)

target_link_libraries(cori_cli PRIVATE cori_lib)
