#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Pràctica1\Point2d.h"

#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPoint2d
{
	TEST_CLASS(UnitTest1)
	{

	public:



		TEST_METHOD(OperationPlus)
		{
			Point2d P_1;
			Point2d P_2;
			Point2d P_3;
			P_1.x = 22;
			P_1.y = 22;
			P_2.x = 11;
			P_2.y = 11;
			P_1 = P_1 + P_2;


			Assert::IsTrue(P_3.x == 33 && P_3.y == 33);
		}

		TEST_METHOD(OperationMinus)
		{
			Point2d P_1;
			Point2d P_2;
			Point2d P_3;
			P_1.x = 6;
			P_1.x = 6;
			P_2.x = 2;
			P_2.y = 2;
			P_3 = P_1 - P_2;


			Assert::IsTrue(P_3.x == 4 && P_3.y == 4);
		}

		TEST_METHOD(OperationPlusEqual)
		{
			Point2d P_1;
			Point2d P_2;
			P_1.x = 3;
			P_1.y = 3;
			P_2.x = 4;
			P_2.y = 4;
			P_1 += P_2;


			Assert::IsTrue(P_1.x == 7 && P_1.y == 7);

		}

		TEST_METHOD(OperationMinusEqual)
		{
			Point2d P_1;
			Point2d P_2;
			P_1.x = 33;
			P_1.y = 33;
			P_2.x = 34;
			P_2.y = 34;
			P_1 -= P_2;


			Assert::IsTrue(P_1.x == -1 && P_1.y == -1);

		}

		TEST_METHOD(OperationEqualEqual)
		{
			Point2d P_1;
			Point2d P_2;
			P_1.x = 3;
			P_1.y = 3;
			P_2.x = 3;
			P_2.y = 3;


			Assert::IsTrue(P_1.operator== (P_2));

		}

		TEST_METHOD(OperationDifferent)
		{
			Point2d P_1;
			Point2d P_2;
			P_1.x = 1;
			P_1.y = 1;
			P_2.x = 2;
			P_2.y = 2;


			Assert::IsTrue(P_1.operator!= (P_2));
		}

		TEST_METHOD(IsZero)
		{
			Point2d P_1;
			P_1.x = 2;
			P_1.y = 2;


			Assert::IsFalse(P_1.IsZero());

		}

		TEST_METHOD(SetZero)
		{
			Point2d P_1;
			P_1.x = 46;
			P_1.y = 46;
			P_1.SetZero();


			Assert::IsTrue(P_1.x == 0 && P_1.y == 0);
		}

		TEST_METHOD(DistanceTo)
		{
			Point2d P_1;
			Point2d P_2;
			float Distance;
			P_1.x = 0;
			P_1.y = 0;
			P_2.x = 2;
			P_2.y = 2;
			Distance = P_1.DistanceTo(P_2);


			Assert::IsTrue(Distance == 2);
		}
	};



}
