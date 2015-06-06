#include "stdafx.h"
#include "CppUnitTest.h"
#include <time.h>
#include "../Point2d.h"
#include "../String.h"
#include "../String.cpp"
#include "../DList.h"
#include "../DynArray.h"

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
			String a1(11);
			a1 = "1234567890";
			String b(5);
			String b1(50);
			b = "hola";
			b1 = "buenas";

			a.prefix(b);
			a1.prefix(b);
			b.prefix("1234567890");
			b1.prefix("1234567890");

			Assert::AreEqual(strcmp(a.getString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(a1.getString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.getString(), "1234567890hola"), 0);
			Assert::AreEqual(strcmp(b1.getString(), "1234567890buenas"), 0);
		}
		TEST_METHOD(StringTrim)
		{
			String s1("   Hello World     ");
			s1.trim();
			Assert::IsTrue(s1 == "Hello World");
		}
		TEST_METHOD(StringFind)
		{
			String s1("Hello World Hello World Hello");
			
			Assert::AreEqual((int)s1.find("Hello"), 3);
			Assert::AreEqual((int)s1.find("World"), 2);
			Assert::AreEqual((int)s1.find("Error"), 0);
			Assert::AreEqual((int)s1.find(" "), 4);
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

		// ---------------------------------------------------
		// --------------------- DList -----------------------
		// ---------------------------------------------------

		TEST_METHOD(DListConstructor)
		{
			DList<int> dl1;

			Assert::IsTrue(dl1.count() == 0);
			Assert::IsFalse(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsNull(dl1.getNodeAtPos(3));

			DList<float> dl2;

			Assert::IsTrue(dl2.count() == 0);
			Assert::IsFalse(dl2.del(dl2.getNodeAtPos(0)) == true);
			Assert::IsNull(dl2.getNodeAtPos(3));
		}
		TEST_METHOD(DListConcatenateOperator)
		{
			DList<int> dl1, dl2;

			dl1.add(1);
			dl1.add(2);
			dl2.add(3);
			dl2.add(4);

			dl1 += dl2;

			Assert::IsTrue(dl1.count() == 4);
			Assert::IsTrue(dl1.getNodeAtPos(0)->data == 1);
			Assert::IsTrue(dl1.getNodeAtPos(1)->data == 2);
			Assert::IsTrue(dl1.getNodeAtPos(2)->data == 3);
			Assert::IsTrue(dl1.getNodeAtPos(3)->data == 4);

		}
		TEST_METHOD(DListCount)
		{
			DList<int> dl1;

			dl1.add(45);
			dl1.add(2);

			Assert::IsTrue(dl1.count() == 2);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
		}
		TEST_METHOD(DListGetNodeAtPos)
		{
			DList<int> dl1;

			dl1.add(45);

			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(dl1.count() == 0);
		}
		TEST_METHOD(DListDel)
		{
			DList<float> dl1;

			dl1.add(45.3f);

			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(dl1.count() == 0);

			dl1.add(5.0f);
			dl1.add(-36.87f);
			dl1.add(0.0f);

			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(-1)) == false);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(3)) == false);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(2)) == true);
			Assert::IsTrue(dl1.count() == 2);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(1)) == true);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(dl1.count() == 0);

		}
		TEST_METHOD(DListDelAll)
		{
			DList<float> dl1;

			dl1.add(45.3f);
			dl1.add(5.0f);
			dl1.add(-36.87f);
			dl1.add(0.0f);

			Assert::IsTrue(dl1.count() == 4);
			dl1.clear();
			Assert::IsTrue(dl1.count() == 0);
		}
		TEST_METHOD(DListGetFirst)
		{
			DList<float> dl1;
			Assert::IsNull(dl1.getFirst());
			Assert::IsTrue(dl1.getNodeAtPos(0) == dl1.getFirst());

			dl1.add(2.0f);
			dl1.add(3.0f);

			Assert::IsNotNull(dl1.getFirst());
			Assert::IsTrue(dl1.getNodeAtPos(0) == dl1.getFirst());
		}
		TEST_METHOD(DListGetLast)
		{
			DList<float> dl1;
			Assert::IsNull(dl1.getLast());
			Assert::IsTrue(dl1.getNodeAtPos(0) == dl1.getLast());

			dl1.add(2.0f);
			dl1.add(3.0f);

			Assert::IsNotNull(dl1.getLast());
			Assert::IsTrue(dl1.getNodeAtPos(1) == dl1.getLast());
		}
		TEST_METHOD(DListOperatorSquareBrackets)
		{
			DList<float> dl1;
			dl1.add(2.0f);
			dl1.add(3.0f);

			Assert::AreEqual(dl1[0], 2.0f);
			Assert::AreEqual(dl1[1], 3.0f);
		}

		TEST_METHOD(DListSortingCopy)
		{
			DList<int> d;

			d.add(5);
			d.add(4);
			d.add(10);
			d.add(8);
			d.add(3);
			d.add(3);
			d.add(-63);
			d.add(22);
			d.add(0);
			d.add(16);
			d.add(-9);
			d.add(-6);
			d.add(15);
			d.add(1);
			d.add(0);

			d.sort_copy();

			for (unsigned int i = 0; i < d.count() - 1; i++)
				Assert::IsTrue(d[i] <= d[i + 1]);
		}

		/*TEST_METHOD(DListSortingReference)
		{
		DList<int> d;

		d.add(5);
		d.add(4);
		d.add(10);
		d.add(8);
		d.add(3);
		d.add(3);
		d.add(-63);
		d.add(22);
		d.add(0);
		d.add(16);
		d.add(-9);
		d.add(-6);
		d.add(15);
		d.add(1);
		d.add(0);

		d.sort_reference();

		for (unsigned int i = 0; i < d.count() - 1; i++)
		Assert::IsTrue(d[i] <= d[i + 1]);
		}*/

		// ---------------------------------------------
		// ---------------- DynArray--------------------
		// ---------------------------------------------
		TEST_METHOD(DynArrayConstruct1)
		{
			DynArray<int> dyn1;

			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 0);
		}
		TEST_METHOD(DynArrayConstruct2)
		{
			DynArray<int> dyn1(5);

			Assert::IsTrue(dyn1.getMemory() == 5);
			Assert::IsTrue(dyn1.getNumElements() == 0);
		}
		TEST_METHOD(DynArrayPushBack)
		{
			DynArray<int> dyn1;
			dyn1.pushBack(13);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 1);

			DynArray<double> dyn2(1);
			dyn2.pushBack(13.99823);
			dyn2.pushBack(13.29234);
			Assert::IsTrue(dyn2.getMemory() == 2);
			Assert::IsTrue(dyn2.getNumElements() == 2);

			DynArray<double> dyn3(4);
			dyn3.pushBack(13.99823);
			dyn3.pushBack(13.29234);
			Assert::IsTrue(dyn3.getMemory() == 4);
			Assert::IsTrue(dyn3.getNumElements() == 2);
		}
		TEST_METHOD(DynArrayPop)
		{
			int a;
			DynArray<int> dyn1;
			dyn1.pushBack(13);
			dyn1.pop(a);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 0);
			dyn1.pop(a);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 0);

			float b;
			DynArray<float> dyn2;
			Assert::IsFalse(dyn2.pop(b));
			Assert::IsTrue(dyn2.getMemory() == 16);
			Assert::IsTrue(dyn2.getNumElements() == 0);

			DynArray<float> dyn3(6);
			dyn3.pushBack(3);
			dyn3.pushBack(4);
			dyn3.pushBack(5);
			Assert::IsTrue(dyn3.pop(b));
			Assert::IsTrue(dyn3.getMemory() == 6);
			Assert::IsTrue(dyn3.getNumElements() == 2);
		}
		TEST_METHOD(DynArrayInsert)
		{
			DynArray<int> dyn1;
			Assert::IsTrue(dyn1.insert(13, 1) == false);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 0);
			Assert::IsTrue(dyn1.insert(12, 0) == true);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 1);
			dyn1.pushBack(11);
			dyn1.pushBack(12);
			dyn1.pushBack(13);
			Assert::IsTrue(dyn1.insert(12, 0) == true);
			Assert::IsTrue(dyn1.insert(12, 2) == true);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 6);
		}

		TEST_METHOD(DynArrayInsertAray)
		{
			DynArray<int> dyn1;
			 
			dyn1.pushBack(1);
			dyn1.pushBack(2);
			dyn1.pushBack(3);
			dyn1.pushBack(4);
			dyn1.pushBack(5);

			DynArray<int> dyn2;

			dyn2.pushBack(991);
			dyn2.pushBack(992);
			dyn2.pushBack(993);
			dyn2.pushBack(994);
			dyn2.pushBack(995);
			
			dyn1.insert(dyn2, 2);
			
			Assert::AreEqual((int)dyn1[0], 1);
			Assert::AreEqual((int)dyn1[1], 2);
			Assert::AreEqual((int)dyn1[2], 991);
			Assert::AreEqual((int)dyn1[3], 992);
			Assert::AreEqual((int)dyn1[4], 993);
			Assert::AreEqual((int)dyn1[5], 994);
			Assert::AreEqual((int)dyn1[6], 995);
			Assert::AreEqual((int)dyn1[7], 3);
			Assert::AreEqual((int)dyn1[8], 4);
			Assert::AreEqual((int)dyn1[9], 5);
		}
		TEST_METHOD(DynArrayOperatorClaudator)
		{
			DynArray<int> dyn1;
			dyn1.pushBack(8);
			Assert::IsTrue(dyn1[0] == 8);
		}

		TEST_METHOD(DynArrayFlip)
		{
			DynArray<unsigned int> dyn1;
			dyn1.pushBack(1);
			dyn1.pushBack(2);
			dyn1.pushBack(3);
			dyn1.pushBack(4);
			dyn1.pushBack(5);
			dyn1.pushBack(6);
			dyn1.pushBack(7);

			dyn1.flip();

			for (unsigned int i = 0, j = 7; i < dyn1.getNumElements(); i++, j--)
				Assert::AreEqual(dyn1[i], j);
		}

		TEST_METHOD(TestSorting)
		{
			DynArray<int> test(5);
			DynArray<int> solution(5);

			test.pushBack(5);
			test.pushBack(4);
			test.pushBack(10);
			test.pushBack(8);
			test.pushBack(3);

			solution.pushBack(3);
			solution.pushBack(4);
			solution.pushBack(5);
			solution.pushBack(8);
			solution.pushBack(10);

			test.sort();

			for (unsigned int i = 0; i < test.getNumElements(); i++)
				Assert::AreEqual(test[i], solution[i]);

			DynArray<int> d;

			d.pushBack(5);
			d.pushBack(4);
			d.pushBack(10);
			d.pushBack(8);
			d.pushBack(3);
			d.pushBack(3);
			d.pushBack(-63);
			d.pushBack(22);
			d.pushBack(0);
			d.pushBack(16);
			d.pushBack(-9);
			d.pushBack(-6);
			d.pushBack(15);
			d.pushBack(1);
			d.pushBack(0);

			d.sort();

			for (unsigned int i = 0; i < d.getNumElements() - 1; i++)
				Assert::IsTrue(d[i] <= d[i + 1]);

			// ---- Bubble optimized ----

			DynArray<int> d_opt;
			srand(time(NULL));

			for (unsigned int i = 0; i < 10000; i++)
				d_opt.pushBack(rand());

			d_opt.sort_opt();

			for (unsigned int i = 0; i < d_opt.getNumElements() - 1; i++)
				Assert::IsTrue(d_opt[i] <= d_opt[i + 1]);
		}
	};
}