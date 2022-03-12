#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "SeqList.h"
#include "Exception.h"

namespace FYLib
{

	template <typename T>
	class DynamicList : public SeqList<T>
	{
	protected:
		int m_capacity;
	public:
		DynamicList(int capacity)
		{
			this->m_array = new T[capacity];

			if (this->m_array != nullptr)
			{
				this->m_length = 0;
				this->m_capacity = capacity;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object...");
			}
		}

		int capacity() const
		{
			return m_capacity;
		}

		//�������ÿռ�Ĵ�С
		void resize(int capacity)
		{
			if (capacity != m_capacity)
			{
				T* array = new T[capacity];
				if (array != nullptr)
				{
					//���length����С�ˣ���ôֻ�ܶ���������Щ����
					int length = (this->m_length < capacity ? this->m_length : capacity);

					for (int i = 0; i < length; i++)
					{
						array[i] = this->m_array[i];
					}

					T* temp = this->m_array;

					this->m_array = array;
					this->m_length = length;
					this->m_capacity = capacity;

					delete[] temp;//�������������������������쳣Ҳ����ν�ˣ��ø�ֵ�Ķ���ֵ��
				}
				else
				{
					THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object...");
				}
			}
		}

		~DynamicList()
		{
			delete[] m_array;
		}
	};

}




#endif // !DYNAMICLIST_H