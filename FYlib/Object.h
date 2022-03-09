#ifndef OBJECT_H
#define OBJECT_H

namespace FYLib
{

/*
* 顶层父类
* 1.遵循经典设计准则，所有数据结构都继承自 Object 类
* 2.定义动态内存申请的行为，提高代码的移植性
* 3.Object 类用于统一动态内存申请的行为
* 4.在堆中创建 Object 子类的对象 ， 失败时返回 NULL 值
* 5.Object 类为纯虚父类 ， 所有子类都能进行动态类型识别
*/
class Object
{
public:
	void* operator new (size_t size) throw();
	void operator delete (void* p);
	void* operator new[](size_t size) throw();
	void operator delete[](void* p);
	virtual ~Object() = 0;//动态类型识别
};

}

#endif // !OBJECT_H


