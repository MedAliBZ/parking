#include "Abonnement.h"

using namespace std;

Abonnement::Abonnement()
{
    dateExp=0;
    gratuit=10;
}

Abonnement::~Abonnement()
{
    //dtor
}


Abonnement::Abonnement(int i,int h,double p,int d):Carte(i,h,p)
{
    dateExp=d;
    gratuit=10;
}


void Abonnement::afficher(){
    Carte::afficher();
    cout << "date Exp: " << dateExp << " gratuit: " << gratuit << endl;
}
