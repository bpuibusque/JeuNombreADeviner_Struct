/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.1
// Nom du programmeur: Baptiste Puibusque MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
#include <windows.h>
using namespace std;


#include "../include/CPartie.h"

int main()
{
    int nbJoueurs, nbParties;
    cout<<"____________JEUX DU NOMBRE A DEVINER____________"<<endl<<endl;
    cout<<"______________Combien de Joueurs ?______________"<<endl;
    cin>>nbJoueurs;
    cout<<"______________Combien de Parties ?______________"<<endl;
    cin>>nbParties;
    cout<<"------------------------------------------------"<< endl;

    CJoueur *tabJoueur[nbJoueurs]; //initialisation du tableau des joueurs

    int i; //compteur pour les manipulations avec les joueurs

    for(i=0;i<nbJoueurs;i++){
        cout<<"Entrez prenom et nom du joueur "<<(i+1)<<" : ";
        string prenom;
        cin>>prenom;
        string nom;
        cin>>nom;

        tabJoueur[i] = new CJoueur(prenom,nom);
    }

    for(i=0;i<nbJoueurs;i++){
        for(int j=0;j<nbParties;j++){
            CPartie partie (0,10,4);
            partie.Jouer(*tabJoueur[i]);
        }
    }

    for(i=0;i<nbJoueurs;i++){
        int nbsucces, nbechecs, nbessais;
        tabJoueur[i]->Resultats(nbsucces,nbechecs,nbessais);// Récupération des résultats du joueur

        cout << "----------------------------------------------"<< endl;
        cout << "Affichage des resultats de "<< tabJoueur[i]->Identite() << endl;
        cout << "----------------------------------------------"<< endl;

        cout << "Nombre de parties gagnees : " << nbsucces << endl;
        cout << "Nombre de parties perdues : " << nbechecs << endl;
        cout << "Nombre de tentatives totales : " << nbessais << endl;

        cout << "----------------------------------------------"<< endl;
    }



}


