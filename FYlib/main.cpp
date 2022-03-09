#include <iostream>
#include "smartpoint.h"
#include "Object.h"
#include "Sort.h"
#include "Exception.h"
#include "StaticList.h"

using namespace std;
using namespace FYLib;




int main()
{
	StaticList<int, 5> l;
	for (int i = 0; i < 5; i++)
	{
		l.insert(0, i);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << l[i] << endl;
	}

	return 0;
}