#include "../include/CJoueur.h"

    CJoueur::CJoueur(string prenom, string nom)
    {
        this->nom=nom;
        this->prenom=prenom;
        this->nbPartiesGagnees = 0;
        this->nbPartiesJouees=0;
        this->nbTentatives=0;
    }

    void CJoueur::MajResultats(int nbEssais, bool gagne)
    {
       this->nbTentatives= this->nbTentatives + nbEssais;

       if (gagne == true)
            this->nbPartiesGagnees ++;

       this->nbPartiesJouees++;
    }

    void CJoueur::Resultats(int& nbsucces, int& nbechec, int& nbessais)
    {
        nbsucces = this->nbPartiesGagnees;
        nbechec = this->nbPartiesJouees - this->nbPartiesGagnees;
        nbessais = this->nbTentatives;
    }


    string CJoueur::Identite()
    {
        return ((this->prenom)+" "+(this->nom));
    }

