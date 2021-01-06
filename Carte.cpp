#include "Carte.h"

using namespace std;

Carte::Carte()
{
    id=0;
    heures=0;
    prix=0;
}

Carte::~Carte()
{
    //dtor
}


Carte::Carte(int i,int h,double p){
    id=i;
    heures=h;
    prix=p;
}

void Carte::afficher(){
    cout << "id: " << id << " heures: " << heures << " prix: " << prix << endl;
}
