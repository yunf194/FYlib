#include "Object.h"
#include <cstdlib>

namespace FYLib
{

	void* Object::operator new (unsigned int size) throw()
	{
		return malloc(size);
	}

	void Object::operator delete (void* p)
	{
		free (p);
	}

	void* Object::operator new[](unsigned int size) throw()
	{
		return malloc(size);
	}

	void Object::operator delete[](void* p)
	{
		free(p);
	}

	Object::~Object()//����汾Ҳ��Ҫ�ṩ������
	{

	}

}