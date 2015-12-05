#ifndef MIRAGE_TEST_UTILES
#define MIRAGE_TEST_UTILES

#ifdef WIN32
#define HAVE_STRUCT_TIMESPEC
#include <vld.h>
#endif

#include <iostream>
#include <gtest/gtest.h>
#include <pthread.h>
#include <uv.h>
#include <glib.h>
#include <zlib.h>

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

class UtilsTest : public testing::Test
{
public:
	static void* thread1(void *Param);
	static void* thread2(void *Param);
};

#endif
