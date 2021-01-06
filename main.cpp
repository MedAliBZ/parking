#include <iostream>
#include "Abonnement.h"
#include "Application.h"

using namespace std;

int main()
{
    Application AA;
    Abonnement A(1,2,5.6,2100);
    Carte C(2,3,41.5);

    Parking P(1,3);
    Parking P1(2,3);
    AA.ajouterParking(P);
    AA.ajouterParking(P1);
    AA.ajouterCarte(A);
    AA.ajouterCarte(C);

    AA.autoriserCarte(A,1);
    AA.autoriserCarte(C,1);
    AA.ajouterCarteParking(A,1);

    cout << "--------------------------" << endl;
    AA.afficher();
    cout << "--------------------------" << endl;
    AA.rechercheParking().afficher();
    AA.supprimerCarte(1);
    cout << "--------------------------" << endl;
    AA.afficher();

    return 0;
}
