# CMakeList.txt: ShowPicture 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ShowPicture")

# OpenCV 是环境变量，指向你OpenCV的安装目录，里面包含了 OpenCVConfig.cmake
find_package(OpenCV REQUIRED)

message(STATUS "opencv header path = ${OpenCV_INCLUDE_DIRS}.")
message(STATUS "opencv libs = ${OpenCV_LIBS}.")

include_directories(${OpenCV_INCLUDE_DIRS})

# 将源代码添加到此项目的可执行文件。
add_executable (ShowPicture ShowPicture.cc)
target_link_libraries(ShowPicture ${OpenCV_LIBS})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ShowPicture PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
