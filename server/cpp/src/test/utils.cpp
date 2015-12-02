#include "utils.h"

TEST_F(UtilsTest, threadTest1)
{
	pthread_t pid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&pid, &attr, UtilsTest::thread1, NULL);
	pthread_create(&pid, &attr, UtilsTest::thread1, NULL);
	pthread_create(&pid, &attr, UtilsTest::thread1, NULL);

	getchar();

	pthread_attr_destroy(&attr);
}


void* UtilsTest::thread1(void* Param)
{
	pthread_t myid = pthread_self();
	std::cout << "Thread ID : " << myid.p << std::endl;
	return NULL;
}

TEST_F(UtilsTest, libuvTest1)
{
	uv_loop_t *loop = uv_loop_new();
	uv_run(loop, UV_RUN_DEFAULT);
}

TEST_F(UtilsTest, glibTest1)
{
	guint32 n = g_random_int();
	std::cout << "Random : " << n << std::endl;
}
