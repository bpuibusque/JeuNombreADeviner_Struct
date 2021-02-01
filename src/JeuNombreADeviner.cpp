/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
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
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : nom du joueur
// Param�tres de sortie : aucun
// Param�tres d'entr�e/sortie : joueur creer

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbTentatives = 0;
}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
    int nombreAdeviner;
    srand (time(NULL));
    nombreAdeviner = rand() % 10 + 1;
        return nombreAdeviner;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: nombre � deviner
// Param�tres de sortie: aucun
// Param�tres d'entr�e/sortie : joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int nombreEntree, cpt=1, nbreEssais=1; bool etat = false;
    cout<<endl<<"Entrez un nombre : " ;
    cin>>nombreEntree;
    while(cpt != 4){
        if(nombreEntree < nombreADeviner){
            cpt++;
            cout<<"C'est plus !"<<endl<<endl ;
            cout<<"Entrez un nouveau nombre : " ;
            cin>>nombreEntree;
            nbreEssais++;
        }else if(nombreEntree > nombreADeviner){
            cpt++;
            cout<<endl<<"C'est moins !"<<endl<<endl ;
            cout<<"Entrez un nouveau nombre : " ;
            cin>>nombreEntree;
            nbreEssais++;
        }else{
            cpt =4;
            etat = true;
        }
        //nbreEssais++;
    }
    if(nombreEntree == nombreADeviner){
        cout<<endl<<"C'est gagne ! En "<< nbreEssais<<" essais "<<endl;
        MajResultatsJoueur(un_joueur,nbreEssais,etat);
    }else{
        cout<<endl<<"C'est perdu la reponse etait : "<<nombreADeviner;
        MajResultatsJoueur(un_joueur,nbreEssais,etat);
    }
}


// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: joueur, nombre d'essais, bool�en gagner ou perdu
// Param�tres de sortie: aucun
// Param�tres d'entr�e/sortie : aucun

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
    joueur.nbTentatives +=  nbEssais;
    if(gagne){
        joueur.nbPartiesGagnees++;
    }
    joueur.nbPartiesJouees++;
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: le joueur
// Param�tres de sortie: aucun
// Param�tres d'entr�e/sortie : le nombre de succ�s, le nombre d'�checs, le nombre d'essais
void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees;
    nbessais = joueur.nbTentatives;
    nbechec = joueur.nbPartiesJouees - nbsucces;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

// Nom :afficherResultats
// R�le : retourne le tableau des r�sultats des parties
// Param�tres d'entr�e: le ou les joueurs, et le nombre
// Valeur de retour : rien
void afficherResultats(TJoueur tab[], int nbrejoueur){


}

// Nom :JouerPartie�Plusieurs
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, affiche les r�sultats ainsi que le/les gagnants
// Param�tres d'entr�e: le nombre de joueurs et de parties souhait�e
// Param�tres de sortie: aucuns

void JouerPartieaPlusieurs(int nbreJoueurs,int nbrePartie){
    int compteur = nbreJoueurs;
    int i =0;
    string nomJoueur;
    TJoueur tabJoueur[nbreJoueurs];

    while(compteur>0){
        cout<<"Entrez nom du joueur "<<++i<<" : "<<endl;
        cin>>nomJoueur;
        InitJoueur(tabJoueur[i],nomJoueur);
        compteur --;
    }
    int compteurJoueur = 0;
    int cptJoueur = 1;
    while(nbreJoueurs>0){
        int nombrePartie = nbrePartie;
        int compteurPartie =1;
        while(nombrePartie>0){
            cout<<endl<<"-----------------------------------------------------------------------------------";
            cout<<endl<<endl<<"Partie numero "<<compteurPartie<<", Joueur "<<cptJoueur<<endl;
            JouerPartie(tabJoueur[compteurJoueur],TirerNombreMystere());
            nombrePartie --;
            compteurPartie++;
        }
        nbreJoueurs--;
        cptJoueur++;
    }

}
