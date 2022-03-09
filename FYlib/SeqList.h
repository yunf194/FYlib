#ifndef SEQLIST_H
#define SEQLIST_H
#include "List.h"
#include "Exception.h"

namespace FYLib
{
	template < typename T >
	class SeqList : public List<T>
	{
	protected:
		T* m_array;
		int m_length;
	public:
		bool insert(int i, const T& e)
		{
			bool ret = ((i >= 0) && (i <= m_length));//注意i可以是m_length哦
			
			ret = ret && (m_length < capacity());

			if (ret)
			{
				for (int p = m_length - 1; p >= i; p--)
				{
					m_array[p + 1] = m_array[p];
				}
				m_array[i] = e;

				m_length++;
			}

			return ret;

		}

		bool remove(int i)
		{
			bool ret = ((i >= 0) && (i < m_length));

			ret = ret && (m_length < capacity());

			if (ret)
			{
				for (int p = i; p <= m_length-1; p++)
				{
					m_array[p] = m_array[p+1];
				}
				m_length--;
			}
			return ret;
		}

		bool set(int i, const T& e)
		{
			bool ret = ((i >= 0) && (i < m_length));

			if (ret) {
				m_array[i] = e;
			}

			return ret;
		}

		bool get(int i, T& e)const
		{
			bool ret = ((i >= 0) && (i < m_length));
		
			if (ret)
			{
				e = m_array[i];
			}
			return ret;
		}

		int length()const
		{
			return m_length;
		}
		
		void clear()
		{
			m_length = 0;
		}

		T& operator[] (int i)//返回引用，编译器就不为返回值创建临时变量了。直接返回那个变量的引用。
		{
			if ((0 <= i) && (i < m_length))
			{
				return m_array[i];
			}
			else
			{
				THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid...");
			}
			
		}

		T operator[] (int i)const//const对象只能调用const函数，这个函数提供给const对象调用
		{
			return const_cast<SeqList<T>&>(*this)[i];//强制类型转换剔除当前对象的const属性
		}

		virtual int capacity() const = 0;

	};



}



#endif // !SEQLIST_H


