/************************************************************
* Fichier: client.cpp
* Auteures: Cécile Leung-Tack et Camille Bourbonnais
* Date: 25 janvier 2018
* Description: Implémentation de la classe Client
***********************************************************/
#include "client.h"
#include "Produit.h"
#include "panier.h"

/************************************************************
* Fonction: Client::Client
* Description: Constructeur par paramètres
* Paramètres: - string  nom: nom du client
*			  - string prenom: prenom du client
*			  - int identifiant: identifiant du client
*			  - string codePostal: code postal du client
*			  - long date: date de naissance du client
* Retour: aucun
***********************************************************/ 
Client::Client(string  nom, string prenom, int identifiant, string codePostal, long date)
{
	nom_ = nom;
	prenom_ = prenom;
	identifiant_ = identifiant;
	codePostal_ = codePostal;
	dateNaissance_ = date;
	monPanier_ = nullptr;
}

/************************************************************
* Fonction: Client::obtenirNom() 
* Description: Fonction qui permet de connaître le nom du
			   client
* Paramètres: aucun
* Retour: nom_
***********************************************************/
 string Client::obtenirNom() 
{
	 return nom_;
}

 /************************************************************
 * Fonction: Client::obtenirPrenom()
 * Description: Fonction qui permet de connaître le prénom du
			    client
 * Paramètres: aucun
 * Retour: prenom_
 ***********************************************************/
 string Client::obtenirPrenom() 
{
	 return prenom_;
}

 /************************************************************
 * Fonction: Client::obtenirIdentifiant()
 * Description: Fonction qui permet de connaître l'identifiant
			    du client
 * Paramètres: aucun
 * Retour: identifiant_
 ***********************************************************/
int Client::obtenirIdentifiant() 
{
	return identifiant_;
}

/************************************************************
* Fonction: Client::obtenirCodePostal()
* Description: Fonction qui permet de connaître le code 
			   postal du client
* Paramètres: aucun
* Retour: codePostal_
***********************************************************/
string Client::obtenirCodePostal()
{
	return codePostal_;
}

/************************************************************
* Fonction: Client::obtenirDateNaissance()
* Description: Fonction qui permet de connaitre la date du 
*			   naissance du client
* Paramètres: aucun
* Retour: dateNaissance_
***********************************************************/
long Client::obtenirDateNaissance() 
{
	return dateNaissance_;
}

/************************************************************
* Fonction: Client::modifierNom()
* Description: Fonction qui permet de modifier le nom du client
* Paramètres: string nom: nom qu'on veut donner au client
* Retour: aucun
***********************************************************/
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

/************************************************************
* Fonction: Client::modifierPrenom()
* Description: Fonction qui permet de modifier le prénom du
			   client
* Paramètres: string prenom: prenom qu'on veut donner au client
* Retour: aucun
***********************************************************/
void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

/************************************************************
* Fonction: Client::modifierIdentifiant()
* Description: Fonction qui permet de modifier l'identifiant
			   du client
* Paramètres: int identifiant: identifiant du client
* Retour: aucun
***********************************************************/
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

/************************************************************
* Fonction: Client::modifierCodePostal()
* Description: Fonction qui permet de modifier le code postal
		       du client
* Paramètres: string codePostal: code postal du client
* Retour: aucun
***********************************************************/
void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

/************************************************************
* Fonction: Client::modifierDateNaissance()
* Description: Fonction qui permet de modifier la date de 
			   naissance du client
* Paramètres: long date: date de naissance du client
* Retour: aucun
***********************************************************/
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

/************************************************************
* Fonction: Client::acheter()
* Description: Fonction qui permet d'acheter un produit en 
			   ajoutant un produit dans son panier
* Paramètres: Produit * prod: produit qu'on souhaite 
			  ajouter
* Retour: aucun
***********************************************************/
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
	{
		monPanier_ =  new Panier(4);
		monPanier_->ajouter(prod);
	}

	else 
		monPanier_->ajouter(prod);
	
}

/************************************************************
* Fonction: Client::afficherPanier()
* Description: Fonction qui permet d'afficher le contenu du
			   panier du client s'il n'est pas nu;
* Paramètres: aucun
* Retour: aucun
***********************************************************/
void Client::afficherPanier()
{
	if (monPanier_ != nullptr)
	{
		monPanier_->afficher();
	}
}

/***********************************************************
* Fonction: Client::livrerPanier()
* Description: Fonction qui permet de livrer le panier du 
			   client en réinitialisant ses attributs
* Paramètres: aucun
* Retour: aucun
***********************************************************/
void Client::livrerPanier()
{
	monPanier_->livrer();
}



