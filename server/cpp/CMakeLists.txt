project(mirage)

# 版本检查
cmake_minimum_required(VERSION 2.6)

# 设置Debug版的编译参数，Windows下只支持Debug版
set(CMAKE_CXX_FLAGS				"-DWIN32 -DX64 -DWIN64 /MT /EHsc /wd\"4819\"")
set(CMAKE_CXX_FLAGS_DEBUG		"/MTd -DDEBUG /ZI /Od")

# 设置Link参数
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /SAFESEH:NO")

# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Mirage部分的代码
set(mirage_src
	src/mirage/const.h
	src/mirage/const.cpp
)
link_directories(${PROJECT_SOURCE_DIR}/lib ${PROJECT_BINARY_DIR}/bin)
include_directories(${PROJECT_SOURCE_DIR}/deps/x64/include)
add_library(mirage STATIC ${mirage_src})	

# 测试项目
set(test_src
	src/test/main.cpp
	src/test/utils.h
	src/test/utils.cpp
)
link_directories(${PROJECT_SOURCE_DIR}/deps/x64/lib/debug ${PROJECT_BINARY_DIR}/../bin)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/deps/x64/include)
add_executable(mirage_test ${test_src})
target_link_libraries(mirage_test
	winmm.lib
	gtest.lib
	pthreadVC2.lib
)


