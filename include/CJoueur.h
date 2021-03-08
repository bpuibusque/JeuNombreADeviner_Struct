#ifndef CJOUEUR_H
#define CJOUEUR_H

#include <iostream>
using namespace std;

class CJoueur
{
    public:

        // Nom :CJoueur  Constructeur
        // R�le : Initialise toutes les informations du joueur.
        //        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
        // Param�tre d'entr�e : prenom le prenom du joueur, nom le nom du joueur
        // Sortie : le joueur cr��
        CJoueur(string prenom, string nom);

        // Nom : MajResultats
        // R�le : met � jour les informations d'un joueur
        // Param�tres d'entr�e:
        //                  - le nombre d'essais
        //                  - gagne qui vaut true si le joueur a gagn�, false sinon
        // Entr�e/sortie :
        //                  le joueur dont on met � jour les r�sultat
        void MajResultats(int nbEssais, bool gagne);


        // Nom : Resultats
        // R�le : indique les r�sultats d'un joueur
        //        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
        //        La fonction N'affiche PAS les informations � l'�cran
        // Param�tres de sortie:
        //                      - le nombre de succ�s,
        //                      - le nombre d'�checs
        //                      - le nombre total d'essais
        // Entr�e :
        //            -le joueur dont on veut les r�sultats
        void Resultats(int &nbsucces, int &nbechec, int & nbessais);


        // Nom :Identite
        // R�le : retourne le nom et le prenom d'un joueur
        // Entr�e: le joueur dont on veut le nom et le prenom
        // Valeur de retour : idetite du joueur
        // Entr�e : le joueur dont on veut le nom et le prenom
        string Identite();


    private:
        string nom;  // nom du joueur
        string prenom; // prenom du joueur
        int nbPartiesJouees;
        int nbPartiesGagnees;
        int nbTentatives;

};

#endif // CJOUEUR_H
