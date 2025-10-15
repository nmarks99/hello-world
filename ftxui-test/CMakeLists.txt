cmake_minimum_required (VERSION 3.22)

project(ftxui-test
  LANGUAGES CXX
  VERSION 1.0.0
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(ftxui REQUIRED)

add_executable(ftxui-test src/main.cpp)
target_include_directories(ftxui-test PRIVATE src)

target_link_libraries(ftxui-test
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component  # Not needed for this example.
)
