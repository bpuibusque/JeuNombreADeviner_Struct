/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
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
    int nbreJoueur,nbreParties;
    cout<<"Combien il y a t il de joueurs : "; cin>>nbreJoueur;
    cout<<"Combien de parties voulez vous jouer : "; cin>>nbreParties;
    JouerPartieaPlusieurs(nbreJoueur, nbreParties);

    return 0;
}

