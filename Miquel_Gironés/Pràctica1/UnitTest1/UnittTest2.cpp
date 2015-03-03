#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Pràctica1\String.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestString
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(EmptyConstructor)
		{
			String ab;
			Assert::IsTrue(ab.str[0] == '\0');
		}

		TEST_METHOD(Constructor1)
		{
			String a = "hola";
			Assert::IsTrue(a.size == 5);
		}

		TEST_METHOD(Constructor2)
		{
			String a = "hola";
			Assert::IsTrue(strcpy_s(a.str, a.size, a.GetString()));
		}

		TEST_METHOD(EqualEqual1)
		{
			String a = "hola";
			String b = "hola";
			Assert::IsTrue(a.operator==(b));
		}

		TEST_METHOD(EqualEqual2)
		{
			String a = "hola";
			char* b = "hola";
			Assert::IsTrue(a.operator==(b));
		}

		TEST_METHOD(Different1)
		{
			String a = "hola";
			String b = "mundo";
			Assert::IsTrue(a.operator!=(b) != 0);
		}

		TEST_METHOD(Different2)
		{
			String a = "hola";
			char* b = "mundo";
			Assert::IsTrue(a.operator!=(b) != 0);
		}

		TEST_METHOD(Equal)
		{
			String a = "hola";
			String b = "mundo";
			a = b;

		}

		TEST_METHOD(Operator2)
		{
			String a = "hola";
			char* b = "mundo";
			a = b;

		}

		TEST_METHOD(PlusEqual1)
		{
			String a = "hola";
			String b = "mundo";
			a += b;
			Assert::IsTrue(a == "holamundo");
		}

		TEST_METHOD(PlusEqual2)
		{
			String a = "hola";
			char* b = "mundo";
			a += b;
			Assert::IsTrue(a == "holamundo");
		}

		TEST_METHOD(Lenght)
		{
			String a = "hola";
			Assert::IsTrue(a.len() == 10);
		}

		TEST_METHOD(Alloc)
		{
			String a = "hola";
			String b = "mundo";
		}

		TEST_METHOD(Clear)
		{
			String a = "hola";
			a.Clear();

			Assert::IsTrue(a.str[0] = '\0');
		}



		TEST_METHOD(GetString)
		{
			String a = "hola";
			Assert::IsTrue(a.GetString() == "hola");



		}

		TEST_METHOD(Capacity)
		{
			String a = "hola";
			int cap;
			cap = a.Capacity();
			Assert::IsTrue(cap = 5);
		}
	};
}
