#include "pch.h"
#include "CppUnitTest.h"
#include "../ЛР 6.2 рек/ЛР 6.2 рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test62rec
{
	TEST_CLASS(test62rec)
	{
	public:

		TEST_METHOD(TestMaxOddIndex)
		{
			int a[7] = { 4, 7, 2, 9, 6, 3, 8 };
			int result = MaxOddIndex(a, 7, 0, -1);
			Assert::AreEqual(3, result);
		}

		TEST_METHOD(TestMaxOddIndex_NoOdd)
		{
			int a[3] = { 2, 4, 6 };
			int result = MaxOddIndex(a, 3, 0, -1);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(TestSwap)
		{
			int a[7] = { 4, 7, 2, 9, 6, 3, 8 };
			int expected[7] = { 4, 7, 2, 8, 6, 3, 9 };
			bool result = SwapLastWithMaxOdd(a, 7);
			Assert::IsTrue(result);
			for (int i = 0; i < 7; i++)
				Assert::AreEqual(expected[i], a[i]);
		}

		TEST_METHOD(TestSwap_Negative)
		{
			int a[3] = { -5, -3, 4 };
			int expected[3] = { -5, 4, -3 };
			bool result = SwapLastWithMaxOdd(a, 3);
			Assert::IsTrue(result);
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(expected[i], a[i]);
		}

		TEST_METHOD(TestSwap_NoOdd)
		{
			int a[3] = { 2, 4, 6 };
			bool result = SwapLastWithMaxOdd(a, 3);
			Assert::IsFalse(result);
			Assert::AreEqual(2, a[0]);
			Assert::AreEqual(4, a[1]);
			Assert::AreEqual(6, a[2]);
		}
	};
}