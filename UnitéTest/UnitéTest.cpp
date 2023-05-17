#include "pch.h"
#include "CppUnitTest.h"
#include "../TP/main.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitéTest
{
	TEST_CLASS(UnitéTest)
	{
	public:
		TEST_METHOD(TestDessinerLigne_Longueur5)
		{
			std::stringstream output;
			std::streambuf* oldCoutBuffer = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			dessinerLigne(5);

			std::cout.rdbuf(oldCoutBuffer);

			Assert::AreEqual(output.str(), std::string("-----\n"));
		}

		TEST_METHOD(TestDessinerLigne_Longueur10)
		{
			std::stringstream output;
			std::streambuf* oldCoutBuffer = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			dessinerLigne(10);

			std::cout.rdbuf(oldCoutBuffer);

			Assert::AreEqual(output.str(), std::string("----------\n"));
		}
	};
}
