#include <iostream>
#include "multi_thread_manager.h"

int global_int = 0;

void Test()
{
	std::cout << "Hello From Thread!\n";
	global_int += 10;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	T_INIT(availableCores - 1, ThreadType::POOL_FIFO);

	T_FJOB(Test);

	T_DESTROY();

	std::cout << "Global INT is: " << global_int << "\n";
}
