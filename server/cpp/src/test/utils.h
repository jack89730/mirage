#ifndef MIRAGE_TEST_UTILES
#define MIRAGE_TEST_UTILES

#ifdef WIN
#define HAVE_STRUCT_TIMESPEC
#include <vld.h>
#endif

#include <iostream>
#include <gtest/gtest.h>
#include <pthread.h>
#include <uv.h>
#include <glib.h>
#include <zlib.h>

class UtilsTest : public testing::Test
{
public:
	static void* thread1(void *Param);
	static void* thread2(void *Param);
};

#endif
