#include "utils.h"

TEST_F(UtilsTest, test)
{
	std::cout << "This is UtilsTest.test()" << std::endl;

	pthread_t pid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&pid, &attr, UtilsTest::thread1, NULL);
	printf("======================================== ");
	getchar();
	pthread_attr_destroy(&attr);
}


void* UtilsTest::thread1(void* Param)
{
	printf("我是线程！ ");
	pthread_t myid = pthread_self();
	printf("线程ID=%d ", myid);
	return NULL;
}
