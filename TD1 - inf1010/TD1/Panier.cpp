/************************************************************
* Fichier: Panier.cpp
* Auteures: C�cile Leung-Tack et Camille Bourbonnais
* Date: 25 janvier 2018
* Description: Impl�mentation de la classe Panier
***********************************************************/
#include "Panier.h"

Panier::Panier(int capacite)
{
	capaciteContenu_ = 0;
	nombreContenu_ = 0;
	totalAPayer_ = 0.0;
	contenuPanier_ = new Produit*[capaciteContenu_];
}

//M�thodes d'acc�s

Produit** Panier::obtenirContenuPanier()
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu()
{
	return nombreContenu_;
}

double Panier::obtenirTotalApayer()
{
	return totalAPayer_;
}
//Autres m�thodes

void Panier::ajouter(Produit* prod)
{
	if (nombreContenu_ == capaciteContenu_) {
		capaciteContenu_ *= 2;
		Produit ** temporaire = new Produit*[capaciteContenu_];
		for (int i = 0; i < capaciteContenu_; i++) {
			temporaire[i] = contenuPanier_[i];
		}
		delete[] contenuPanier_;
		contenuPanier_ = temporaire;
		contenuPanier_[nombreContenu_++] = prod;
	}
	else
		contenuPanier_[nombreContenu_++] = prod;
	
	totalAPayer_ = totalAPayer_ + prod->obtenirPrix();
	
}

void Panier::livrer()
{
	contenuPanier_ = nullptr;
	nombreContenu_= 0;
	capaciteContenu_ = 0;
	totalAPayer_ = 0;
}

void Panier::afficher()
{
	cout << "Nombre contenu: " << obtenirNombreContenu() << endl
		<< "Total a payer: " << obtenirTotalApayer() << endl;
	
	for (int i = 0; i < nombreContenu_; i++) {
		contenuPanier_[i]->afficher();
	}

}



