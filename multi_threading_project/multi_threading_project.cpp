#include <iostream>
#include "multi_thread_manager.h"

//using namespace thread;
int global_int = 0;

void Test()
{
	std::cout << "Hello From Thread!\n";
	for (int i = 0; i < 10000; i++)
	{
		std::cout << "Hello\n";
	}
	global_int += 1;
}

class T
{
public:
	void Test()
	{
		std::cout << "Test\n";
	}

	void Thread()
	{
		T_PJOB(T, Test);
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	T_INIT(T_REC, thread::ThreadType::POOL_FIFO);
	T test;
	test.Thread();

	while (thread::MultiThreader::GetAmountOfJobs() > 0);
	T_DESTROY();

	std::cout << "Global INT is: " << global_int << "\n";
}
