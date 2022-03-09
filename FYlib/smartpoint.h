#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Object.h"

namespace FYLib
{

/*
**智能指针要求：
**1.指针生命周期结束时主动释放堆空间
**2.一片堆空间最多只能由一个指针标识
**3.杜绝指针运算和指针比较
*/
template <typename T>
class SmartPointer : public Object
{
protected:
	T* m_pointer;

public:
	SmartPointer(T* p = nullptr)
	{
		m_pointer = p;
	}

	SmartPointer(const SmartPointer<T>& obj)
	{
		m_pointer = obj.m_pointer;

		const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
	}

	SmartPointer<T>& operator = (const SmartPointer<T>& obj)
	{
		if (this != &obj)//不能自赋值
		{
			delete m_pointer;//赋值不是构造，对于已经存在的内存要释放掉哦
			m_pointer = obj.m_pointer;
			const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
		}
		return *this;
	}

	T* operator ->()
	{
		return m_pointer;
	}

	T& operator* ()
	{
		return *m_pointer;
	}

	bool isNull()
	{
		return (m_pointer == nullptr);
	}

	T* get()
	{
		return m_pointer;
	}

	~SmartPointer()
	{
		delete m_pointer;
	}


};
}




#endif SMARTPOINTER_H
