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
			// Appeler la fonction à tester
			dessinerLigne(0, 0, 5, 0);

			// TODO: Ajouter des assertions pour vérifier la sortie graphique
			// Exemple : vérifier les pixels de la fenêtre ou comparer des captures d'écran
			Assert::Fail(L"Not implemented");
		}

		TEST_METHOD(TestDessinerLigne_Longueur10)
		{
			// Appeler la fonction à tester
			dessinerLigne(0, 0, 10, 0);

			// TODO: Ajouter des assertions pour vérifier la sortie graphique
			// Exemple : vérifier les pixels de la fenêtre ou comparer des captures d'écran
			Assert::Fail(L"Not implemented");
		}
	};
}
