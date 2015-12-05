# Mirage的编译脚本
# 支持的两个版本为：Windows下32位Debug版、Linux下64位GCC编译版
project(mirage)

# 版本检查
cmake_minimum_required(VERSION 2.6)

if(WIN32)
	# 设置Debug版的编译参数，Windows下只支持Debug版
	set(CMAKE_CXX_FLAGS				"-DWIN32 /MT /EHsc /wd\"4819\"")
	set(CMAKE_CXX_FLAGS_DEBUG		"/MTd -DDEBUG /ZI /Od")
	set(type win32)
else()
	set(CMAKE_CXX_FLAGS				"-DLINUX -fPIC -std=c++0x -g -O2 -Wall -pipe")
	set(CMAKE_CXX_FLAGS_DEBUG		"-fPIC -std=c++0x -DDEBUG")
	set(type linux)
endif()

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
include_directories(${PROJECT_SOURCE_DIR}/deps/${type}/include)
add_library(mirage STATIC ${mirage_src})	

# 测试项目
set(test_src
	src/test/main.cpp
	src/test/utils.h
	src/test/utils.cpp
)
link_directories(${PROJECT_SOURCE_DIR}/deps/${type}/lib ${PROJECT_BINARY_DIR}/../bin)
include_directories(
	${PROJECT_SOURCE_DIR} 
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/deps/${type}/include
)
add_executable(mirage_test ${test_src})
target_link_libraries(mirage_test
	winmm.lib
	ws2_32.lib
	IPHLPAPI.lib
	Psapi.lib
	UserEnv.Lib
	gtest.lib
	pthreadVC2.lib
	libuv.lib
	glib-2.0.lib
	zlib.lib
	mono-2.0
	vld.lib
)


