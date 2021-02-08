/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
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

#include "../include/JeuNombreADeviner.h"

int main()
{


    //test pour 1 joueur

   /* TJoueur baptiste; int nbreParties;
    InitJoueur(baptiste,"Baptiste");
    cout<<"Combien de partie veux tu jouer ?"<<endl;
    cin>>nbreParties;

    while(nbreParties != 0){
        cout<<endl<<"-----------------------------------------------------------------------------------";
        cout<<endl<<endl<<"Nouvelle partie !"<<endl<<endl;
        int nbreAdeviner = TirerNombreMystere();
        JouerPartie(baptiste,nbreAdeviner);
        nbreParties--;
    }*/


    //test pour plusieurs joueurs

    int nbreJoueur,nbreParties,caractereSortie;
    cout<<"Combien il y a t il de joueurs : "; cin>>nbreJoueur;
    cout<<"Combien de parties voulez vous jouer : "; cin>>nbreParties;
    JouerPartieaPlusieurs(nbreJoueur, nbreParties);
    cout<<endl<<"Saisir un caractere pour quitter :";
    cin>>caractereSortie;
}


