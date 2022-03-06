#ifndef SORT_H
#define SORT_H
#include "Object.h"

namespace FYLib
{

class Sort : public Object
{
private:
	Sort();
	Sort(const Sort&);
	Sort& operator = (const Sort&);

	template <typename T>
	static void Swap(T& a, T& b) //��̬��Ա����Ϊ������๲ͬʹ��
	{
		T tmp(a);
		a = b;
		b = tmp;
	}

	template <typename T>
	static void Merge(T src[], T helper[], int begin, int mid, int end, bool min2max = true)
	{
		int i = begin;
		int j = mid + 1;
		int k = begin;
		
		while ((i <= mid) && (j <= end))
		{
			if (min2max ? (src[i] < src[j]) : (src[i] > src[j]))
			{
				helper[k++] = src[i++];
			}
			else
			{
				helper[k++] = src[j++];
			}
		}

		while (i <= mid) helper[k++] = src[i++];
		while (j <= end) helper[k++] = src[j++];

		for (int i = 0; i <= end; i++) {
			src[i] = helper[i];
		}
	}

	template <typename T>
	static void Merge(T src[], T helper[], int begin, int end, bool min2max = true)
	{
		if (begin == end)return;
		else {
			int mid = (begin + end) / 2;

			Merge(src, helper, begin, mid, min2max);
			Merge(src, helper, mid + 1, end, min2max);
			Merge(src, helper, begin, mid, end, min2max);
		}
	}


	template < typename T >
	static void Quick(T array[], int begin, int end, bool min2max)
	{
		
		if (begin < end) {
			T key = array[begin];
			int lo = begin, hi = end;

			while (lo < hi) {
				while (lo < hi && min2max?(key < array[hi]):(key > array[hi])) {
					hi--;
				}
				while (lo < hi && min2max?(key > array[lo]):(key < array[lo])) {
					lo++;
				}
				Swap(array[lo], array[hi]);

			}
			array[lo] = key;
			Quick(array, begin, lo - 1,min2max);
			Quick(array, lo + 1, end,min2max);
		}
	}

public:
	template <typename T>
	static void Select(T array[], int len, bool min2max = true)//����ѡ���С�����Ӵ�С
	{
		for (int i = 0; i < len; i++) {

			int min = i;
			for (int j = i+1; j < len; j++)//����˼�룺��i����Ѱ����С��Ԫ���±�
			{
				if (min2max ? (array[min] > array[j]) : (array[min] < array[j]) ) {
					min = j;
				}
			}

			if(min != i)Swap(array[i], array[min]);//�Ƚ�
		}

	}

	template <typename T>
	static void Insert(T array[], int len, bool min2max = true)//����ѡ���С�����Ӵ�С
	{
		for (int i = 1; i < len; i++)
		{
			int k = i;
			T e = array[i];

			for (int j = i - 1; (j >= 0)&&(min2max ? (array[j] > e):(array[j] < e)); j--) {
	
				array[j + 1] = array[j]; //�����ƶ�һλ
				k = j;		//��¼�����п��ܲ��뵽�ĵط�

			}

			if (k != i)array[k] = e;

		}
	}

	template <typename T>
	static void Bubble(T array[], int len, bool min2max = true)//����ѡ���С�����Ӵ�С
	{
		
		bool exchange = true;

		for (int i = 0; (i < len) && exchange; i++)
		{
			exchange = false;
			for (int j = len - 1; j > i; j--) {
				if (min2max?(array[j] < array[j - 1]):(array[j] > array[j - 1])) {
					Swap(array[j], array[j - 1]);
					exchange = true;
				}
			}
		}
	}

	template <typename T>
	static void Shell(T array[], int len, bool min2max = true)//����ѡ���С�����Ӵ�С
	{
		int d = len;
		do {
			d = d / 3 + 1;//�����ʽ��죬��ѧ�Ͽ���֤��
			for (int i = d; i < len; i+=d)
			{
				int k = i;
				T e = array[i];

				for (int j = i - d; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j-=d) {

					array[j + d] = array[j]; //�����ƶ�һλ
					k = j;		//��¼�����п��ܲ��뵽�ĵط�

				}

				if (k != i)array[k] = e;
			}
		} while (d > 1);

	}

	template <typename T>
	static void Merge(T array[], int len, bool min2max = true)//����ѡ���С�����Ӵ�С
	{
		T* helper = new T[len];

		Merge(array, helper, 0, len - 1, min2max);

		delete[] helper;
	}

	template <typename T>
	static void Quick(T array[], int len, bool min2max = true)//����ѡ���С�����Ӵ�С
	{
		Quick(array, 0, len - 1, min2max);
	}
};

}

#endif // !SORT_H


