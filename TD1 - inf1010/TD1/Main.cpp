/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	//C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments

	//1-  Creez 15 objets du classe produit
	Produit** listeDeCremeGlacee = new Produit*[15];

	listeDeCremeGlacee[0]= new Produit("Creme glacee au chocolat", 1, 1.0);
	listeDeCremeGlacee[1] = new Produit("Creme glacee a la vanille", 2, 2.0);
	listeDeCremeGlacee[2] = new Produit("Creme glacee aux pistaches", 3, 3.0);
	listeDeCremeGlacee[3] = new Produit("Creme glacee aux noisettes", 4, 2.5);
	listeDeCremeGlacee[4] = new Produit("Creme glacee aux fraises", 5, 1.5);
	listeDeCremeGlacee[5] = new Produit("Creme glacee a la pate a biscuit", 6, 2.55);
	listeDeCremeGlacee[6] = new Produit("Creme glacee menthe-chocolat", 7, 3.5);
	listeDeCremeGlacee[7] = new Produit("Creme glacee aux arachides", 8, 0.5);
	listeDeCremeGlacee[8] = new Produit("Creme glacee au caramel", 9, 2.65);
	listeDeCremeGlacee[9] = new Produit("Creme glacee aux pacanes", 10, 3.75);
	listeDeCremeGlacee[10] = new Produit("Creme glacee choco-banane", 11, 2.45);
	listeDeCremeGlacee[11] = new Produit("Creme glacee a lerable", 12, 1.58);
	listeDeCremeGlacee[12] = new Produit("Creme glacee au matcha", 13, 3.87);
	listeDeCremeGlacee[13] = new Produit("Creme glacee au sesame", 14, 2.63);
	listeDeCremeGlacee[14] = new Produit("Creme glacee au cafe", 15, 1.78);
	
	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit
	listeDeCremeGlacee[2]->modifierNom("Creme glacee biscuit et creme");
	listeDeCremeGlacee[2]->modifierReference(16);
	listeDeCremeGlacee[2]->modifierPrix(3.37);
 
	//3-  Creez un objet de classe rayon à l'aide du constructeur par défaut
	Rayon* rayon1  = new Rayon();

	//4-  Modifiez la catégorie  du rayon
	rayon1->modifierCategorie("congele");

    // 5- Ajouter 6 produits de  votre choix dans le rayon créé
	rayon1->ajouterProduit(listeDeCremeGlacee[1]);
	rayon1->ajouterProduit(listeDeCremeGlacee[4]);
	rayon1->ajouterProduit(listeDeCremeGlacee[5]);
	rayon1->ajouterProduit(listeDeCremeGlacee[10]);
	rayon1->ajouterProduit(listeDeCremeGlacee[14]);
	rayon1->ajouterProduit(listeDeCremeGlacee[12]);

    // 6- afficher le contenu du rayon
	rayon1->afficher();
  
	//7-  Creez un objet de classe client à l'aide du constructeur
   Client* client1 = new Client("Chomi", "Ftephane", 1, "J8V 3T8", 980730);

	//8-  afficher l'etat des attributs du client
   cout << "Nom: " << client1->obtenirNom() << endl
	   << "Prenom: " << client1->obtenirPrenom() << endl
	   << "Identifiant: " << client1->obtenirIdentifiant() << endl
	   << "Code postal: " << client1->obtenirCodePostal() << endl
	   << "Date de naissance: " << client1->obtenirDateNaissance() << endl;
   
	//9-   Le client achete 9 produits
   Panier panierDuClient= Panier(15);
   client1->acheter(listeDeCremeGlacee[0]);
   client1->acheter(listeDeCremeGlacee[2]);
   client1->acheter(listeDeCremeGlacee[5]);
   client1->acheter(listeDeCremeGlacee[6]);
   client1->acheter(listeDeCremeGlacee[7]);
   client1->acheter(listeDeCremeGlacee[8]);
   client1->acheter(listeDeCremeGlacee[9]);
   client1->acheter(listeDeCremeGlacee[11]);
   client1->acheter(listeDeCremeGlacee[13]);

	//10- Afficher le contenu du panier du client
   cout << "Le panier contient:" << endl;
   client1->afficherPanier();

    //11- livrer le panier du client
   cout << "Le panier est livre." << endl;
   client1->livrerPanier();
    
	//12- afficher le contenu du panier du client
   cout << "Il n'y a donc plus rien dans le panier." << endl;
   client1->afficherPanier();

	//13-  terminer le programme correctement
   delete[] listeDeCremeGlacee;
   delete client1;
   delete rayon1;

   cin.get(), cin.get();
   return 0;
}
/***********************************************************************************************
QUESTIONS

1. Quel est le lien (agrégation ou composition) entre la classe Client et la classe Panier ?
Justifiez.

2. Quel est le lien (agrégation ou composition) entre un Produit et un Rayon ? Justifiez.


***********************************************************************************************/