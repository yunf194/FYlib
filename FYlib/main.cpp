#include <iostream>
#include "smartpoint.h"
#include "Object.h"
#include "Sort.h"

using namespace std;
using namespace FYLib;

struct Test
{
    int key1;//high
    int key2;//low

    Test(int k1, int k2)
    {
        key1 = k1;
        key2 = k2;
    }

    bool operator == (const Test& t)
    {
        return (key1 == t.key1) && (key2 == t.key2);
    }

    bool operator != (const Test& t)
    {
        return !(*this == t);
    }

    bool operator < (const Test& t)
    {
        return (key1 < t.key1) || ((key1 == t.key1) && (key2 < t.key2));
    }

    bool operator >= (const Test& t)
    {
        return !(*this < t);
    }

    bool operator > (const Test& t)
    {
        return (key1 > t.key1) || ((key1 == t.key1) && (key2 > t.key2));
    }

    bool operator <= (const Test& t)
    {
        return !(*this > t);
    }
};



int main()
{
    int array[] =  {23, 64, 24, 12, 9, 16, 53, 57, 71, 79, 87, 97} ;

    Sort::Quick(array, 12,false);

    for (int i = 0; i < 12; i++)
    {
        cout << array[i] << endl;
    }




	return 0;
}