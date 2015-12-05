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

TEST_F(UtilsTest, zlibTest1)
{
	//原始数据 
	unsigned char pchSrc[] = "xxx....";
	unsigned long nSrcLen = sizeof(pchSrc);

	//压缩之后的数据 
	unsigned char achComp[1024];
	unsigned long nCompLen = 1024;

	//解压缩之后的数据 
	unsigned char achUncomp[1024];
	unsigned long nUncompLen = 1024;

	//压缩 
	compress(achComp, &nCompLen, pchSrc, nSrcLen);

	//解压缩 
	uncompress(achUncomp, &nUncompLen, achComp, nCompLen);

	//显示原始数据信息 
	printf("原始数据(%d):\n%s\n\n", nSrcLen, pchSrc);

	//显示压缩之后的数据 
	printf("压缩数据(%d):\n%s\n\n", nCompLen, achComp);

	//显示解压缩之后的数据 
	printf("解压数据(%d):\n%s\n\n", nUncompLen, achUncomp);
}

TEST_F(UtilsTest, Mono1)
{
	mono_set_dirs("C:\\Program Files (x86)\\Mono-3.2.3\\lib", "C:\\Program Files (x86)\\Mono-3.2.3\\etc");
}