#ifndef __String_H__
#define __String_H__

#include <wtypes.h>
#include <iostream>

class String{

public:


	int size;
	char* str;

	String()
	{
		size = 1;
		str = new char[size];
		str[0] = '\0';
	}

	String(const char *format, ...)
	{
		size = 0;
		if (format != NULL)
		{
			static char tmp[4096];
			static va_list af;
			va_start(af, format);
			int res = vsprintf_s(tmp, 4096, format, af);
			va_end(af);
			if (res > 0)
			{
				Alloc(res + 1);
				strcpy_s(str, size, tmp);
			}
		}

		if (size == 0)
		{
			Alloc(1);
			Clear();
		}
	}

	String(const String& chain)
	{
		if (chain != NULL)
		{
			Alloc(chain.len() + 1);
			strcpy_s(str, size, chain.GetString());
		}
		else
		{
			Alloc(1);
			Clear();
		}
	}

	~String();

	bool operator== (const String& string) const
	{

		return strcmp(string.str, str) == 0;
	}

	bool operator== (const char* string) const
	{
		if (string != NULL)

			return strcmp(string, str) == 0;

		return false;
	}

	bool operator!= (const String& string) const
	{
		return strcmp(string.str, str) != 0;

	}

	bool operator!= (const char* string) const
	{
		if (string != NULL)
			return strcmp(string, str) != 0;
		return true;
	}

	const String& operator= (const String& string)
	{
		if (string.len() + 1 > size)
		{
			delete[] str;
			Alloc(string.len() + 1);
		}
		else
			Clear();


		strcpy_s(str, size, string.str);

		return *(this);
	}

	const String& operator= (const char* string)
	{
		if (string != NULL)
		{
			if (strlen(string) + 1 > size)
			{
				delete[] str;
				Alloc(strlen(string) + 1);
			}
			else
				Clear();

			strcpy_s(str, size, string);
		}
		return *(this);
	}

	const String& operator+= (const String& string)
	{
		String tmp0;
		String& tmp = tmp0;
		tmp.Alloc(strlen(str) + 1);
		strcpy_s(tmp.str, strlen(str) + 1, str);
		Alloc(strlen(string.str) + size + 1);
		strcpy_s(str, strlen(tmp.str) + 1, tmp.str);
		strcat_s(str, strlen(string.str) + size + 1, string.str);
		printf("%s", str);

		return *this;


	}

	const String& operator+= (const char* string)
	{
		if (string != NULL)
		{
			strcat_s(str, strlen(string), string);
			return (*this);
		}
		return (*this);
	}

	const int len() const
	{
		return strlen(str);
	}

	void Alloc(unsigned int required_memory)
	{
		size = required_memory;
		str = new char[size];
	}

	void Clear()
	{
		delete[] str;

		str = new char[1];

		str[0] = '\0';
	}

	const int Capacity()
	{
		return(size + 1);
	}

	const char* GetString()const
	{
		return str;
	}


};
#endif