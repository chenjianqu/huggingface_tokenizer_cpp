cmake_minimum_required(VERSION 3.20)
project(huggingface_tokenizer_cpp)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


find_package(Eigen3)
include_directories(
        ${EIGEN3_INCLUDE_DIR}
)

add_executable(main src/main.cpp src/tokenizer.cpp)
target_link_libraries(main -licuuc)
