#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.4Rec/Lab_06_4_Rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT64Rec
{
	TEST_CLASS(UT64Rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int n = 2;
			int p[n] = { 1,2 };
			int A = 2;
			int B = 3;
			t = Kil(p, n, A, B, 0);
			Assert::AreEqual(t, 1);
		}
	};
}
