#include "pch.h"
#include "CppUnitTest.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Dessinateur.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



    TEST_CLASS(DessinateurTests)
    {
    public:
        TEST_METHOD(TestDessinerLigne)
        {
            // Arrange
            cv::Mat image(300, 400, CV_8UC3, cv::Scalar(0, 0, 0));  // Image noire de taille 400x300
            cv::Scalar couleur(255, 255, 255);  // Couleur blanche
            int epaisseur = 2;
            int x1 = 50, y1 = 50;
            int x2 = 200, y2 = 50;

            // Act
            DessinerLigne(image, x1, y1, x2, y2, couleur, epaisseur);

            // Assert
            cv::Scalar couleurPixel = image.at<cv::Vec3b>(y1, x1);
            std::wstring message = L"Couleur attendue : (255, 255, 255), Couleur obtenue : (" +
                std::to_wstring(couleurPixel[0]) + L", " +
                std::to_wstring(couleurPixel[1]) + L", " +
                std::to_wstring(couleurPixel[2]) + L")";
            Assert::IsTrue(couleur == couleurPixel, message.c_str());
        }
    };

