Installation de OpenCV et configuration de VSC :

Installer OpenCV dans le répertoire "C:\"

Sur VSC, dans Projet,
-> "Propriété de [Projet]"
  -> "Propriétés de configuration" > "Répertoires VC++"
  	-> Répertoire Include : "C:\opencv\build\include"
		-> Répertoires de bibliothèques : "C:\opencv\build\x64\vc15\lib"
	-> "Editeur de liens" -> entrée
		-> Dépendances supplémentaires : "C:\opencv\build\x64\vc15\lib\opencv_world460d.lib"
