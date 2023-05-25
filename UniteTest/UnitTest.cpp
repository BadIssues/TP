#include "pch.h"
#include "CppUnitTest.h"
#include "Parseur.h"
#include "../TP/Forme.h"
#include "../TP/Cercle.h"
#include "../TP/Ligne.h"
#include "../TP/Rectangle.h"
#include "../TP/Triangle.h"
#include "../TP/Forme.cpp"
#include "../TP/Cercle.cpp"
#include "../TP/Ligne.cpp"
#include "../TP/Rectangle.cpp"
#include "../TP/Triangle.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(FormeTest)
{
public:
    TEST_METHOD(TestCercle)
    {
        Parseur p;
        Forme* f = p.parse("cercle"); 

        // Vérifier si la forme retournée par le parseur est un Cercle
        Cercle* cercle = dynamic_cast<Cercle*>(f);
        Assert::IsNotNull(cercle);
    }

    TEST_METHOD(TestLigne)
    {
        Parseur p;
        Forme* f = p.parse("ligne");  

        // Vérifier si la forme retournée par le parseur est une Ligne
        Ligne* ligne = dynamic_cast<Ligne*>(f);
        Assert::IsNotNull(ligne);
    }

    TEST_METHOD(TestRectangle)
    {
        Parseur p;
        Forme* f = p.parse("rectangle"); 

        // Vérifier si la forme retournée par le parseur est un Rectangle
        Rectangle* rectangle = dynamic_cast<Rectangle*>(f);
        Assert::IsNotNull(rectangle);
    }

    TEST_METHOD(TestTriangle)
    {
        Parseur p;
        Forme* f = p.parse("triangle");  

        // Vérifier si la forme retournée par le parseur est un Triangle
        Triangle* triangle = dynamic_cast<Triangle*>(f);
        Assert::IsNotNull(triangle);
    }
};
