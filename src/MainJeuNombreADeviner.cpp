/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    TJoueur baptiste; int nbreParties;
    InitJoueur(baptiste,"Baptiste");
    cout<<"Combien de partie veux tu jouer ?"<<endl;
    cin>>nbreParties;

    while(nbreParties != 0){
        cout<<"-----------------------------------------------------------------------------------";
        cout<<endl<<endl<<"Nouvelle partie !"<<endl<<endl;
        int nbreAdeviner = TirerNombreMystere();
        JouerPartie(baptiste,nbreAdeviner);
        nbreParties--;
    }

    return 0;
}

