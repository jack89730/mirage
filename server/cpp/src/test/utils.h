#ifndef MIRAGE_TEST_UTILES
#define MIRAGE_TEST_UTILES

#ifdef WIN64
#define HAVE_STRUCT_TIMESPEC
#endif

#include <iostream>
#include <gtest/gtest.h>
#include <pthread.h>
#include <uv.h>

class UtilsTest : public testing::Test
{
public:
	static void* thread1(void* Param);
};

#endif
