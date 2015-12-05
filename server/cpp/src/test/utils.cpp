#include "utils.h"

TEST_F(UtilsTest, threadTest1)
{
	pthread_t pid1, pid2, pid3;
	void *r1, *r2, *r3;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	{
		pthread_create(&pid1, NULL, UtilsTest::thread1, NULL);
		pthread_create(&pid2, NULL, UtilsTest::thread1, NULL);
		pthread_create(&pid3, NULL, UtilsTest::thread1, NULL);
	}
	pthread_attr_destroy(&attr);
}


void* UtilsTest::thread1(void* Param)
{
	pthread_t myid = pthread_self();

	for (int i = 0; i < 100; ++i)
	{
		std::cout << "Thread ID : " << myid.p << std::endl;
	}
	
	return NULL;
}

void* UtilsTest::thread2(void *Param)
{
	return NULL;
}

TEST_F(UtilsTest, libuvTest1)
{
	uv_loop_t *loop = (uv_loop_t*)malloc(sizeof(uv_loop_t));
	uv_loop_init(loop);

	printf("Now quitting.\n");
	uv_run(loop, UV_RUN_DEFAULT);

	uv_loop_close(loop);
	//free(loop);
}

TEST_F(UtilsTest, glibTest1)
{
	guint32 n = g_random_int();
	std::cout << "Random : " << n << std::endl;
}

TEST_F(UtilsTest, zlibTest1)
{
	//ԭʼ���� 
	unsigned char pchSrc[] = "��С˵��д��һ�������ұ������ҵ�һ���������������죬�ͳ�����ʧ�˷���";
	unsigned long nSrcLen = sizeof(pchSrc);

	//ѹ��֮������� 
	unsigned char achComp[1024];
	unsigned long nCompLen = 1024;

	//��ѹ��֮������� 
	unsigned char achUncomp[1024];
	unsigned long nUncompLen = 1024;

	//ѹ�� 
	compress(achComp, &nCompLen, pchSrc, nSrcLen);

	//��ѹ�� 
	uncompress(achUncomp, &nUncompLen, achComp, nCompLen);

	//��ʾԭʼ������Ϣ 
	printf("ԭʼ����(%d):\n%s\n\n", nSrcLen, pchSrc);

	//��ʾѹ��֮������� 
	printf("ѹ������(%d):\n%s\n\n", nCompLen, achComp);

	//��ʾ��ѹ��֮������� 
	printf("��ѹ����(%d):\n%s\n\n", nUncompLen, achUncomp);
}

TEST_F(UtilsTest, Mono1)
{
	mono_set_dirs("C:\\Program Files (x86)\\Mono-3.2.3\\lib", "C:\\Program Files (x86)\\Mono-3.2.3\\etc");
}