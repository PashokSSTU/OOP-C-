#include <iostream>
#include "Calculate.h"

int main()
{
	Calculate<int, int> obj1(0,0);
	Calculate<int, int> obj2(0,0);
	Calculate<int, int> obj3(0,0);

	obj1.setValues(6,1);
	obj2.setValues(34,3623);


	return 0;
}