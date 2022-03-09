#ifndef ARRAY_H
#define ARRAY_H

#include "Object.h"
#include "Exception.h"

namespace FYLib
{
	template <typename T>
	class Array : public Object
	{
	protected:
		T* array;
	public:
        virtual bool set(int i, const T& e) // O(1)
        {
            bool ret = ((0 <= i) && (i < length()));

            if (ret)
            {
                m_array[i] = e;
            }

            return ret;
        }

        virtual bool get(int i, T& e) const   // O(1)
        {
            bool ret = ((0 <= i) && (i < length()));

            if (ret)
            {
                e = m_array[i];
            }

            return ret;
        }

        virtual T& operator[] (int i)   // O(1) 
        {
            if ((0 <= i) && (i < length()))
            {
                return m_array[i];
            }
            else
            {
                THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid ...");
            }
        }

        virtual T operator[] (int i) const  // O(1) 常量对象使用
        {
            return (const_cast<Array<T>&>(*this))[i];
        }


	};



}
#endif // !ARRAY_H



