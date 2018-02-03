/************************************************************
* Fichier: Rayon.cpp
* Auteures: C�cile Leung-Tack et Camille Bourbonnais
* Date: 25 janvier 2018
* Description: Impl�mentation de la classe Rayon
***********************************************************/

#include "Rayon.h"
#include "Produit.h"

/************************************************************
* Fonction: Rayon::Rayon
* Description: Constructeur par d�faut
* Param�tres: aucun
* Retour: aucun
***********************************************************/
Rayon::Rayon()
{
	categorie_ = "inconnu";
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}
/************************************************************
* Fonction: Rayon::Rayon
* Description: Constructeur par param�tres
* Param�tres: - string cat: nom de la cat�gorie (IN)
* Retour: aucun
***********************************************************/

Rayon::Rayon(string cat) 
{
	categorie_ = cat;
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}
//M�thodes d'acc�s
/************************************************************
* Fonction: Rayon::obtenirCategorie()
* Description: Pour obtenir l'attribut categorie_
* Param�tres: aucun
* Retour: categorie_
***********************************************************/
string Rayon::obtenirCategorie()
{
	return categorie_;
}

/************************************************************
* Fonction: Rayon::obtenirTousProduits()
* Description: Pour obtenir l'attribut tousProduits_
* Param�tres: aucun
* Retour: tousProduits_
***********************************************************/
Produit** Rayon::obtenirTousProduits()
{
	return tousProduits_;
}

/************************************************************
* Fonction: Rayon::obtenirCapaciteProduits()
* Description: Pour obtenir l'attribut capaciteProduits_
* Param�tres: aucun
* Retour: capaciteProduits_
***********************************************************/
int Rayon::obtenirCapaciteProduits()
{
	return capaciteProduits_;
}

/************************************************************
* Fonction: Rayon::obtenirNombreProduits()
* Description: Pour obtenir l'attribut nombreProduits_
* Param�tres: aucun
* Retour: nombreProduits_
***********************************************************/
int Rayon::obtenirNombreProduits()
{
	return nombreProduits_;
}

//M�thodes de modification
/************************************************************
* Fonction: Rayon::modifierCategorie(string cat)
* Description: Pour modifier la cat�gorie 
* Param�tres: - string cat: nom de la cat�gorie (IN)
* Retour: aucun
***********************************************************/
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}

//Autres m�thodes
/************************************************************
* Fonction: Rayon::ajouterProduit(Produit * produit)
* Description: Pour ajouter un produit dans un panier
* Param�tres: - Produit* produit: produit qu'on veut ajouter (IN)
* Retour: aucun
***********************************************************/
void Rayon::ajouterProduit(Produit * produit) 
{
	if (capaciteProduits_ = 0) 
	{
		capaciteProduits_ = 5;
		tousProduits_ = new Produit*[capaciteProduits_];
		tousProduits_[nombreProduits_++] = produit;
	}

	else if (nombreProduits_ == capaciteProduits_) 
	{
		capaciteProduits_ += 5;
		Produit** temporaire = new Produit*[capaciteProduits_];
		for (int i = 0; i < nombreProduits_; i++) 
		{
			temporaire[i] = tousProduits_[i];
		}
		delete[] tousProduits_;
		tousProduits_ = temporaire;
		tousProduits_[nombreProduits_++] = produit;
	}

	else
		tousProduits_[nombreProduits_++] = produit;
}

/************************************************************
* Fonction: Rayon::afficher()
* Description: Afficher le contenu d'un rayon
* Param�tres: aucun
* Retour: aucun
***********************************************************/
void Rayon::afficher()
{
	cout << "Nom de la categorie du rayon: " << obtenirCategorie() << endl
		<< "Capacite des produits: " << obtenirCapaciteProduits() << endl
		<< "Nombre de produits dans le rayon: " << obtenirNombreProduits() << endl;

	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
}