// SingletonPattern.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include "ChocolateBoiler.h"
#include "test.h"
int _tmain(int argc, _TCHAR* argv[])
{
	ChocolateBoiler* boiler = ChocolateBoiler::getInstance();
	boiler->fill();

	ChocolateBoiler* nextBoiler = ChocolateBoiler::getInstance();
	nextBoiler->boil();
	boiler->drain();
	MyClass *test = MyClass::getInstance();
	system("PAUSE");
	return 0;
}

