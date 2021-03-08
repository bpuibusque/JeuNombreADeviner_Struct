#ifndef CPARTIE_H
#define CPARTIE_H
#include "CJoueur.h"

class CPartie
{
    public:

        // Nom :CPartie (constructeur)
        // R�le : initialise la partie avec le nombre d'essais max, les nombres minimal et maximal � trouver
        // Param�tres d'entr�e:
        //              le nombre d'essais max,
        //              le nombre minimal,
        //              le nombre maximal
        // Sortie : la partie qui est cr��e
        CPartie ( int nbmin = 0, int nbmax = 10, int nbessaismax = 4);


        // Nom :JouerPartie
        // R�le : Tire un nombre al�atoire et d�marre la partie
        //        A la fin, met � jour les informations du joueur
        // Parametre d'entr�e/sortie : le joueur
        // Entr�e : la partie qui va se jouer
        void Jouer (CJoueur &joueur);

    private:

        // Nom :TirerNombreMystere
        // R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
        // Valeur de retour : nombre � deviner
        // Entr�e : la partie pour laquelle est tir�e le nombre myst�re
        int TirerNombreMystere();


        int nbEssaisMax; // nombre d'essais max
        int nbMin; // nombre minimal � trouver
        int nbMax; // nombre maximal � trouver
};

#endif // CPARTIE_H
