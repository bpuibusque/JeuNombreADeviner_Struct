/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              cstdlib
//                              ctime
// Historique du fichier:
/*************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


#include <string.h>

using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : nom du joueur
// Paramètres de sortie : aucun
// Paramètres d'entrée/sortie : joueur creer

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbTentatives = 0 ;
}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
    int nombreAdeviner;
    srand (time(NULL));
    nombreAdeviner = rand() % 10 + 1;
        return nombreAdeviner;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: nombre à deviner
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{

    int nombreEntree, nbreEssais=1; bool etat = false;
    cout<<endl<<"Entrez un nombre : " ;
    cin>>nombreEntree;

    while((nombreEntree!=nombreADeviner)&& nbreEssais <4 ){
        if(nombreEntree < nombreADeviner){
            cout<<"C'est plus !"<<endl<<endl ;
            cout<<"Entrez un nouveau nombre : " ;
            cin>>nombreEntree;
            nbreEssais++;
        }else if(nombreEntree > nombreADeviner){
            cout<<endl<<"C'est moins !"<<endl<<endl ;
            cout<<"Entrez un nouveau nombre : " ;
            cin>>nombreEntree;

            nbreEssais++;
        }else{
            etat = true;
        }
        //nbreEssais++;
    }

    if(nombreEntree == nombreADeviner){
        etat= true;
        cout<<endl<<"C'est gagne ! En "<< nbreEssais<<" essais "<<endl;

    }else{
        cout<<endl<<"C'est perdu la reponse etait : "<<nombreADeviner<<endl;
        nbreEssais=4;
    }
    MajResultatsJoueur(un_joueur,nbreEssais,etat);
}



// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: joueur, nombre d'essais, booléen gagner ou perdu
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : aucun

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
    joueur.nbTentatives = joueur.nbTentatives +  nbEssais;
    if(gagne){
        joueur.nbPartiesGagnees++;
    }
    joueur.nbPartiesJouees++;
}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: le joueur
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : le nombre de succès, le nombre d'échecs, le nombre d'essais
void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees;
    nbessais = joueur.nbTentatives;
    nbechec = joueur.nbPartiesJouees - nbsucces;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

// Nom :afficherResultats
// Rôle : retourne le tableau des résultats des parties avec le ou les meilleur joueurs
// Paramètres d'entrée: le ou les joueurs, et le nombre de joueurs
// Valeur de retour : rien
void afficherResultats(TJoueur tab[], int nbrejoueur, int nbrePartie){
    int i = nbrePartie;
    int classement = 0;
    cout<<"\n\nLe classement final est :\n";
    while(i<=(nbrePartie*4)){
        int parcoursTableau=0;
        while(parcoursTableau<nbrejoueur){
            if(tab[parcoursTableau].nbTentatives==i){
                cout<<"---------------------------------------------\n";
                cout<<"Classement : "<<classement<<"  Joueur : "<<\
                tab[parcoursTableau].nom<<"  Score : "<<tab[parcoursTableau].nbTentatives<<endl;
            }
            parcoursTableau++;
        }

        classement++;
        i++;
    }

}

// Nom :JouerPartieàPlusieurs
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, affiche les résultats ainsi que le/les gagnants
// Paramètres d'entrée: le nombre de joueurs et de parties souhaitée
// Paramètres de sortie: aucuns

void JouerPartieaPlusieurs(int nbreJoueurs,int nbrePartie){
    int compteur = nbreJoueurs;
    int nombreJoueurConstant = nbreJoueurs;
    int i = 0;
    string nomJoueur;
    TJoueur tabJoueur[nbreJoueurs];

    while(compteur>0){
        cout<<"Entrez nom du joueur "<<(i+1)<<" : "<<endl;
        cin>>nomJoueur;
        InitJoueur(tabJoueur[i],nomJoueur);
        i++;
        compteur --;
    }
    int compteurJoueur = 0;
    int cptJoueur = 1;
    while(nbreJoueurs>0){
        int nombrePartie = nbrePartie;
        int compteurPartie =1;
        while(nombrePartie>0){
            cout<<"\n-----------------------------------------------------------------------------------";
            cout<<endl<<endl<<"Partie numero "<<compteurPartie<<", Joueur "<<cptJoueur<<endl;
            cout<<"\n-----------------------------------------------------------------------------------\n";
            JouerPartie(tabJoueur[compteurJoueur],TirerNombreMystere());
            nombrePartie --;
            compteurPartie++;
        }
        nbreJoueurs--;
        cptJoueur++;
        compteurJoueur++;
    }
    afficherResultats(tabJoueur,nombreJoueurConstant,nbrePartie);
}
