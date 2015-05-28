#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Point2d.h"
#include "../String.h"
#include "../String.cpp"

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
			Point2d<float> p1, p3;
			p1.x = 1.f;
			p1.y = 2.f;
			Point2d<float> p2(p1);

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

		// ---------------------------------------------
		// ---------------- String ---------------------
		// ---------------------------------------------

		TEST_METHOD(StringConstrEmpty)
		{
			String s1;

			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(StringConstrChar)
		{
			String s1("Hello");
			char *p2 = "Dog";
			String s2 = p2;
			char *p3 = NULL;
			String s3 = p3;
			String s4("%s %d %s", "I am", 27, "years old");

			Assert::IsTrue(s1 == "Hello");
			Assert::IsTrue(s2 == "Dog");
			Assert::IsTrue(s3 == "");
			Assert::IsTrue(s4 == "I am 27 years old");
		}
		TEST_METHOD(StringConstrString)
		{
			String s1;
			String s2(s1);
			String s3("Hello");
			String s4(s3);

			Assert::IsTrue(s1 == "");
			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(s3 == "Hello");
			Assert::IsTrue(s3 == s4);
		}
		TEST_METHOD(StringEqualityChar)
		{
			String s1("Hello");
			char *p1 = NULL;
			char *p2 = "Hello";

			Assert::IsTrue(s1 == "Hello");
			Assert::IsFalse(s1 == p1);
			Assert::IsTrue(s1 == p2);
		}
		TEST_METHOD(StringInequalityChar)
		{
			String s1("Hello");
			char *p1 = NULL;
			char *p2 = "Hello, darling";

			Assert::IsTrue(s1 != "Hello, darling");
			Assert::IsTrue(s1 != p1);
			Assert::IsTrue(s1 != p2);
		}
		TEST_METHOD(StringEqualityString)
		{
			String s1("Hello");
			String s2("Hello");

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(StringInequalityString)
		{
			String s1("Hello");
			String s2("Hello, darling...");

			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(StringAssignChar)
		{
			String s1("Hello");
			String s2 = "Hello, darling...";
			char *p = NULL;
			String s3 = p;
			String s4 = "Hello";

			Assert::IsTrue(s1 != s2);
			Assert::IsTrue(s1 != s2);
			Assert::IsTrue(s1 != s3);
			Assert::IsTrue(s1 == s4);
		}
		TEST_METHOD(StringAssignString)
		{
			String s1("Hello");
			String s2 = s1;
			String s3("Hello, darling...");
			String s4 = s3;

			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(s1 != s4);
		}
		TEST_METHOD(StringConcatChar)
		{
			String s1("Hello");
			s1 += "world";
			Assert::IsTrue(s1 == "Helloworld");
			char *p = NULL;
			s1 += p;
			Assert::IsTrue(s1 == "Helloworld");
		}
		TEST_METHOD(StringConcatString)
		{
			String s1("Hello");
			String s2("world");
			s1 += s2;
			Assert::IsTrue(s1 == "Helloworld");
		}
		TEST_METHOD(StringPrefix)
		{
			String a("1234567890");
			String b(50);
			b = "hola";

			a.prefix(b);
			b.prefix("1234567890");

			Assert::AreEqual(strcmp(a.getString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.getString(), "1234567890hola"), 0);
		}
		TEST_METHOD(StringTrim)
		{
			String s1("   Hello World     ");
			s1.trim();
			Assert::IsTrue(s1 == "Hello World");
		}
		TEST_METHOD(StringGetLength)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(s1.getLength() == 5);
			Assert::IsTrue(s2.getLength() == 0);
		}
		TEST_METHOD(StringCapacity)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(s1.capacity() == 6);
			Assert::IsTrue(s2.capacity() == 1);
		}
		TEST_METHOD(StringGetString)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(strcmp(s1.getString(), "Hello") == 0);
			Assert::IsTrue(strcmp(s2.getString(), "") == 0);
		}
		TEST_METHOD(StringClear)
		{
			String s1("Hello");
			s1.clear();

			Assert::IsTrue(strcmp(s1.getString(), "") == 0);
		}
		
	};
}