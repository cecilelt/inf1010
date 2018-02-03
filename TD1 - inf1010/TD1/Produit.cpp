/************************************************************
* Fichier: Produit.cpp
* Auteures: C�cile Leung-Tack et Camille Bourbonnais
* Date: 25 janvier 2018
* Description: Impl�mentation de la classe Produit
***********************************************************/

#include "Produit.h"

Produit::Produit()
{
	nom_ = "outil";
	reference_ = 0;
	prix_ = 0.0;
}

Produit::Produit(string nom, int reference, double prix)
{
	nom_ = nom;
	reference_ = reference;
	prix_ = prix;
}

//m�thode d'acc�s
string Produit::obtenirNom()
{
	return nom_;
}

int Produit::obtenirReference()
{
	return reference_;
}

double Produit::obtenirPrix()
{
	return prix_;
}

//m�thode de modification

void Produit::modifierNom(string nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

void Produit::afficher()
{
	cout << "Nom: " << nom_ << endl
		<< "Reference: " << reference_ << endl
		<< "Prix: " << prix_ << endl;
}