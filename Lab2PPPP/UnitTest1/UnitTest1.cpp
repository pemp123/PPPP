#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab2PPPP\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			std::ostringstream oss;
			systemOfLinearEquations(0,0,0,0,0,0, oss);
			Assert::IsTrue(oss && oss.str() == "5");
		}
		TEST_METHOD(TestMethod2)
		{

			std::ostringstream oss;
			systemOfLinearEquations(1,2,3,4,5,6, oss);
			Assert::IsTrue(oss && oss.str() == "2 -4 4.5");
		}
		TEST_METHOD(TestMethod3)
		{
			std::ostringstream oss;
			systemOfLinearEquations(0,0,0,4,0,6, oss);
			Assert::IsTrue(oss && oss.str() == "4 1.5");
		}
		TEST_METHOD(TestMethod4)
		{
			std::ostringstream oss;
			systemOfLinearEquations(0, 2, 0, 0, 6, 0, oss);
			Assert::IsTrue(oss && oss.str() == "4 3");
		}

		TEST_METHOD(TestMethod5)
		{
			std::ostringstream oss;
			systemOfLinearEquations(0, 0, 0, 2, 0, 0, oss);
			Assert::IsTrue(oss && oss.str() == "4 0");
		}
		TEST_METHOD(TestMethod6)
		{
			std::ostringstream oss;
			systemOfLinearEquations(0,0,3,0,0,6, oss);
			Assert::IsTrue(oss && oss.str() == "3 2");
		}
		TEST_METHOD(TestMethod7)
		{
			std::ostringstream oss;
			systemOfLinearEquations(1,0,0,0,5,0, oss);
			Assert::IsTrue(oss && oss.str() == "3 5");
		}

		TEST_METHOD(TestMethod8)
		{
			std::ostringstream oss;
			systemOfLinearEquations(1, 0, 0, 0, 0, 0, oss);
			Assert::IsTrue(oss && oss.str() == "3 0");
		}

		TEST_METHOD(TestMethod9)
		{
			std::ostringstream oss;
			systemOfLinearEquations(0, 0, 3, 4, 0, 6, oss);
			Assert::IsTrue(oss && oss.str() == "1 -0.75 1.5");
		}

		TEST_METHOD(TestMethod10)
		{
			std::ostringstream oss;
			systemOfLinearEquations(1, 2, 0, 0, 5, 0, oss);
			Assert::IsTrue(oss && oss.str() == "1 -0.5 2.5");
		}
		TEST_METHOD(TestMethod11)
		{
			std::ostringstream oss;
			systemOfLinearEquations(0, 2, 3, 4, 0, 0, oss);
			Assert::IsTrue(oss && oss.str() == "1 -1.33333 0");
		}
		TEST_METHOD(TestMethod12)
		{
			std::ostringstream oss;
			systemOfLinearEquations(1, 2, 0, 4, 0, 0, oss);
			Assert::IsTrue(oss && oss.str() == "1 -2 0");
		}
		TEST_METHOD(TestMethod13)
		{
			std::ostringstream oss;
			systemOfLinearEquations(2, 2, 3, 3, 5, 6, oss);
			Assert::IsTrue(oss && oss.str() == "0");
		}
		TEST_METHOD(TestMethod14)
		{
			std::ostringstream oss;
			systemOfLinearEquations(4, 2, 6, 3, 0, 0, oss);
			Assert::IsTrue(oss && oss.str() == "1 -2 0");
		}
	};
}
