#include "pch.h"
#include "CppUnitTest.h"
#include <opencv2/opencv.hpp>
#include "dessinerligne.cpp"
void dessinerLigne(cv::Mat& image, int x1, int y1, int x2, int y2);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UniteTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestDessinerLigne_Longueur5)
		{
			cv::Mat image(300, 400, CV_8UC3, cv::Scalar(0, 0, 0));  // Image noire de taille 400x300

			// Appeler la fonction � tester
			dessinerLigne(image, 0, 0, 5, 0);

			// TODO: Ajouter des assertions pour v�rifier l'image r�sultante
			// Exemple : v�rifier les pixels de l'image ou comparer avec une image de r�f�rence
			Assert::Fail(L"Not implemented");
		}


		TEST_METHOD(TestDessinerLigne_Longueur10)
		{
			cv::Mat image(300, 400, CV_8UC3, cv::Scalar(0, 0, 0));  // Image noire de taille 400x300

			// Appeler la fonction � tester
			dessinerLigne(image, 0, 0, 10, 0);

			// TODO: Ajouter des assertions pour v�rifier l'image r�sultante
			// Exemple : v�rifier les pixels de l'image ou comparer avec une image de r�f�rence
			Assert::Fail(L"Not implemented");
		}
	};
}