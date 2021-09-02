#include <iostream>
#include "multi_thread_manager.h"
#include <d3d11.h>
#include <d2d1.h>
#include <typeinfo>

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

class B
{
public:
	B() {};
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	T_INIT(T_REC, thread::ThreadType::POOL_FIFO);

	while (thread::MultiThreader::GetAmountOfJobs() > 0);
	T_DESTROY();

	int x = 0;
	std::cout << "Global INT is: " << x << "\n";
}
