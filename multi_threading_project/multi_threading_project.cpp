#include <iostream>
#include "multi_thread_manager.h"

//using namespace thread;
int global_int = 0;

void Test()
{
	std::cout << "Hello From Thread!\n";
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Hello\n";
	}
	global_int += 1;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	T_INIT(T_REC, thread::ThreadType::POOL_FIFO);

	for (int i = 0; i < 1000; i++)
	{
		T_FJOB(Test);
	}

	while (thread::MultiThreader::GetAmountOfJobs() > 0);
	T_DESTROY();

	std::cout << "Global INT is: " << global_int << "\n";
}
