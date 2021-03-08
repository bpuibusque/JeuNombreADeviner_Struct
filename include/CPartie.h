#ifndef CPARTIE_H
#define CPARTIE_H
#include "CJoueur.h"

class CPartie
{
    public:

        // Nom :CPartie (constructeur)
        // Rôle : initialise la partie avec le nombre d'essais max, les nombres minimal et maximal à trouver
        // Paramètres d'entrée:
        //              le nombre d'essais max,
        //              le nombre minimal,
        //              le nombre maximal
        // Sortie : la partie qui est créée
        CPartie ( int nbmin = 0, int nbmax = 10, int nbessaismax = 4);


        // Nom :JouerPartie
        // Rôle : Tire un nombre aléatoire et démarre la partie
        //        A la fin, met à jour les informations du joueur
        // Parametre d'entrée/sortie : le joueur
        // Entrée : la partie qui va se jouer
        void Jouer (CJoueur &joueur);

    private:

        // Nom :TirerNombreMystere
        // Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
        // Valeur de retour : nombre à deviner
        // Entrée : la partie pour laquelle est tirée le nombre mystère
        int TirerNombreMystere();


        int nbEssaisMax; // nombre d'essais max
        int nbMin; // nombre minimal à trouver
        int nbMax; // nombre maximal à trouver
};

#endif // CPARTIE_H
