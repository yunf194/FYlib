#include "Exception.h"
#include <cstring>
#include <cstdlib>

using namespace std;

namespace FYLib
{
	void Exception::init(const char* messeage, const char* file, int line)
	{
		m_message = strdup(messeage);//����һ���ַ������ѿռ䣬m_messageָ��ѿռ��ϵ��ַ���

		if (file != NULL)
		{
			char sl[16] = { 0 };

			itoa(line, sl, 10);// ȡ��������ֵ��������ת��Ϊ��Ӧ�������ֵ� �ַ���
			
			m_location = (char *)malloc(strlen(file) + strlen(sl) + 2);
			if (m_location != NULL)
			{
				m_location = strcpy(m_location, file);
				m_location = strcat(m_location, ":");
				m_location = strcat(m_location, sl);
			}
		}
		else
		{
			m_location = NULL;
		}
	}

	Exception::Exception(const char* message)
	{
		init(message, NULL, 0);
	}
	Exception::Exception(const char* file, int line)
	{
		init(NULL, file, line);
	}
	Exception::Exception(const char* message, const char* file, int line)
	{
		init(message, file, line);
	}
	Exception::Exception(const Exception& e)
	{
		m_message = strdup(e.m_message);
		m_location = strdup(e.m_location);
	}
	Exception & Exception::operator= (const Exception& e)
	{
		if (this != &e)
		{
			free(m_message);
			free(m_location);

			m_message = strdup(e.m_message);
			m_location = strdup(e.m_location);
		}

		return *this;
	}

	const char* Exception::message() const
	{
		return m_message;
	}
	const char* Exception::location() const
	{
		return m_location;
	}
	Exception::~Exception()//��ʹ�Ǵ��麯������������ҲӦ��ʵ��
	{
		free(m_message);
		free(m_location);
	}

}

