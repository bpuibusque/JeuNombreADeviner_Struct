#ifndef CJOUEUR_H
#define CJOUEUR_H

#include <iostream>
using namespace std;

class CJoueur
{
    public:

        // Nom :CJoueur  Constructeur
        // Rôle : Initialise toutes les informations du joueur.
        //        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
        // Paramètre d'entrée : prenom le prenom du joueur, nom le nom du joueur
        // Sortie : le joueur créé
        CJoueur(string prenom, string nom);

        // Nom : MajResultats
        // Rôle : met à jour les informations d'un joueur
        // Paramètres d'entrée:
        //                  - le nombre d'essais
        //                  - gagne qui vaut true si le joueur a gagné, false sinon
        // Entrée/sortie :
        //                  le joueur dont on met à jour les résultat
        void MajResultats(int nbEssais, bool gagne);


        // Nom : Resultats
        // Rôle : indique les résultats d'un joueur
        //        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
        //        La fonction N'affiche PAS les informations à l'écran
        // Paramètres de sortie:
        //                      - le nombre de succès,
        //                      - le nombre d'échecs
        //                      - le nombre total d'essais
        // Entrée :
        //            -le joueur dont on veut les résultats
        void Resultats(int &nbsucces, int &nbechec, int & nbessais);


        // Nom :Identite
        // Rôle : retourne le nom et le prenom d'un joueur
        // Entrée: le joueur dont on veut le nom et le prenom
        // Valeur de retour : idetite du joueur
        // Entrée : le joueur dont on veut le nom et le prenom
        string Identite();


    private:
        string nom;  // nom du joueur
        string prenom; // prenom du joueur
        int nbPartiesJouees;
        int nbPartiesGagnees;
        int nbTentatives;

};

#endif // CJOUEUR_H
