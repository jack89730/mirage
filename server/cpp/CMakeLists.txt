project(fmmw)

# 版本检查
cmake_minimum_required(VERSION 2.6)

# 设置Debug版的编译参数，Windows下只支持Debug版
set(CMAKE_CXX_FLAGS				"-DWIN32 /MT /EHsc /wd\"4819\"")
set(CMAKE_CXX_FLAGS_DEBUG		"/MTd -DDEBUG /ZI /Od")

# 设置Link参数
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /SAFESEH:NO")

# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# FMMW部分的代码
set(fmmw_src
	src/fmmw/main.cpp
)
link_directories(${PROJECT_SOURCE_DIR}/lib ${PROJECT_BINARY_DIR}/bin)
add_executable(fmmw ${fmmw_src})	

# 测试项目
set(test_src
	src/test/main.cpp
)
link_directories(${PROJECT_SOURCE_DIR}/deps/x64/lib/debug ${PROJECT_BINARY_DIR}/../bin)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/deps/x64/include)
add_executable(mirage_test ${test_src})
target_link_libraries(mirage_test
	winmm.lib
	gtest.lib
)


