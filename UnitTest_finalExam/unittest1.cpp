#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Point2d.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_finalExam
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// ---------------------------------------------
		// --------------- Point2d ---------------------
		// ---------------------------------------------

		TEST_METHOD(Point2dSum)
		{
			Point2d<float> p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p3 = p1 + p2;

			Assert::IsTrue(p3.x == 2.f && p3.y == 4.f);
		}
		TEST_METHOD(Point2dDiff)
		{
			Point2d<float> p1, p2, p3;
			p1.x = p1.y = 1.f;
			p2.x = p2.y = 2.f;

			p3 = p1 - p2;
			Assert::IsTrue(p3.x == -1.f && p3.y == -1.f);
			p3 = p2 - p1;
			Assert::IsTrue(p3.x == 1.f && p3.y == 1.f);
		}
		TEST_METHOD(Point2dSumAssig)
		{
			Point2d<int> p1, p2;
			p1.x = p2.x = 1;
			p1.y = p2.y = 2;

			p1 += p2;
			Assert::IsTrue(p1.x == 2 && p1.y == 4);
			p2 += p1;
			Assert::IsTrue(p2.x == 3 && p2.y == 6);
		}
		TEST_METHOD(Point2dDiffAssig)
		{
			Point2d<float> p1, p2;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p1 -= p2;
			Assert::IsTrue(p1.x == 0.f && p1.y == 0.f);
			p2 -= p1;
			Assert::IsTrue(p2.x == 1.f && p2.y == 2.f);
		}
		TEST_METHOD(Point2dEquality)
		{
			Point2d<float> p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;
			p3.x = p3.y = 1.f;

			Assert::IsTrue(p1 == p2);
			Assert::IsFalse(p1 == p3);
		}
		TEST_METHOD(Point2dInequality)
		{
			Point2d<float> p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;
			p3.x = p3.y = 1.f;

			Assert::IsFalse(p1 != p2);
			Assert::IsTrue(p1 != p3);
		}
		TEST_METHOD(Point2dSetZero)
		{
			Point2d<int> p1;
			p1.setZero();

			Assert::IsTrue(p1.x == 0 && p1.y == 0);
			Assert::IsFalse(p1.x != 0 && p1.y != 0);
		}
		TEST_METHOD(Point2dIsBothZero)
		{
			Point2d<int> p1;
			p1.setZero();

			Assert::IsTrue(p1.isBothZero());
			p1.x = 2;
			Assert::IsFalse(p1.isBothZero());
		}
		TEST_METHOD(Point2dDistanceTo)
		{
			Point2d<double> p1, p2;
			p1.setZero();
			p2.x = 3.00f;
			p2.y = -4.00f;

			Assert::IsTrue(p1.distanceTo(p2) == 5.0f);
		}

		TEST_METHOD(Point2dIsClosedTo)
		{
			Point2d<int> p1, p2;
			p1.setZero(); 
			p2.x = 2;
			p2.y = 2;

			Assert::IsFalse(p1.isClosedTo(p2, 1.0f));
			Assert::IsTrue(p1.isClosedTo(p2, 10.0f));
		}

	};
}