#ifndef OBJECT_H
#define OBJECT_H

namespace FYLib
{

/*
* ���㸸��
* 1.��ѭ�������׼���������ݽṹ���̳��� Object ��
* 2.���嶯̬�ڴ��������Ϊ����ߴ������ֲ��
* 3.Object ������ͳһ��̬�ڴ��������Ϊ
* 4.�ڶ��д��� Object ����Ķ��� �� ʧ��ʱ���� NULL ֵ
* 5.Object ��Ϊ���鸸�� �� �������඼�ܽ��ж�̬����ʶ��
*/
class Object
{
public:
	void* operator new (size_t size) throw();
	void operator delete (void* p);
	void* operator new[](size_t size) throw();
	void operator delete[](void* p);
	virtual ~Object() = 0;//��̬����ʶ��
};

}

#endif // !OBJECT_H


