#include "../include/CPartie.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
using namespace std;

CPartie::CPartie(int nbmin, int nbmax, int nbessaismax)
{
    this->nbEssaisMax = nbessaismax;
    this->nbMax = nbmax;
    this->nbMin = nbmin;
}

 void CPartie::Jouer (CJoueur &un_joueur)
    {
         int nombre_propose; // nombre saisi par l'utilisateur

         int nombreADeviner= this->TirerNombreMystere(); // nombre à deviner

        int i; //  nombre de tentatives effectuées par le joueur

        i = 0;
        bool gagne = false;

        cout << "-------------"<< endl;
        cout << un_joueur.Identite() << " joue" <<endl;
        cout << "-------------"<< endl;

        while (i < 4 && gagne == false)
        {
            i++; // on incrémente le nombre de tentative
            cout << "Choisir un nombre entre " << this->nbMin << " et " << this->nbMax << endl;

            cin >> nombre_propose;
            if (nombre_propose <  this->nbMin || nombre_propose > this->nbMax)
            {
                cout << "Le nombre doit etre compris entre " << this->nbMin << " et " << this->nbMax<<endl;
                i--;
            }
            else if (nombre_propose == nombreADeviner)
                {
                    gagne = true;
                }
                else if (nombre_propose > nombreADeviner)
                    {
                        cout << "C'est trop grand" <<endl;

                    }
                    else if (nombre_propose < nombreADeviner)
                        {
                            cout << "C'est trop petit" << endl;
                        }
        }

        un_joueur.MajResultats(i, gagne);

        if (gagne)
            cout << "Bravo, vous avez gagne !"<<endl;
        else
            cout << "Le nombre d'essais est epuise. La partie est perdue."<< endl;
    }


int CPartie::TirerNombreMystere()
    {
        srand((int)time(0));
        int nombreADeviner = rand() % (this->nbMax - this->nbMin +1) + this->nbMin;
        return nombreADeviner;
    }
