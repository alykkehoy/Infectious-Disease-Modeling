#set(CMAKE_C_COMPILER gcc)
cmake_minimum_required(VERSION 3.8)
project(Infectious-Disease-Modeling)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Library/stochastic/Disease.cpp
        Library/stochastic/Map.cpp
        Library/stochastic/Model.cpp
        Library/stochastic/Person.cpp
        Library/stochastic/Compartments/Compartment.cpp
        Library/stochastic/Compartments/E.cpp
        Library/stochastic/Compartments/I.cpp
        Library/stochastic/Compartments/R.cpp
        Library/stochastic/Compartments/S.cpp)

add_library(stoch ${SOURCE_FILES})

add_executable(sample Library/stochastic/Sample.cpp)
target_link_libraries(sample stoch)