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

		//重新设置空间的大小
		void resize(int capacity)
		{
			if (capacity != m_capacity)
			{
				T* array = new T[capacity];
				if (array != nullptr)
				{
					//如果length还变小了，那么只能丢弃后面那些数据
					int length = (this->m_length < capacity ? this->m_length : capacity);

					for (int i = 0; i < length; i++)
					{
						array[i] = this->m_array[i];
					}

					T* temp = this->m_array;

					this->m_array = array;
					this->m_length = length;
					this->m_capacity = capacity;

					delete[] temp;//析构函数，如果这条语句抛了异常也无所谓了，该赋值的都赋值了
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