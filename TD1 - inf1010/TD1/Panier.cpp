/************************************************************
* Fichier: Panier.cpp
* Auteures: Cécile Leung-Tack et Camille Bourbonnais
* Date: 25 janvier 2018
* Description: Implémentation de la classe Panier
***********************************************************/
#include "Panier.h"

Panier::Panier(int capacite)
{
	capaciteContenu_ = 0;
	nombreContenu_ = 0;
	totalAPayer_ = 0.0;
	contenuPanier_ = new Produit*[capaciteContenu_];
}

//Méthodes d'accès

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
//Autres méthodes

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



