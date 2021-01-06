#ifndef PARKING_H
#define PARKING_H

#include "Abonnement.h"
#include <list>

using namespace std;

class Parking
{
    public:
        Parking();
        virtual ~Parking();
        Parking(int,int);
        void afficher();
        bool rechercheAuto(int);
        void ajouterCarteAuto(int);
        int getPlaces(){return nbPlaces;}
        bool rechercheUti(int);
        void ajouterCarteUti(int);
        int placesUti(){return idUti.size();}
        void supprimerCarteTous(int);
        int getRef(){return refer;}

    protected:
        int refer;
        int nbPlaces;
        list<int> idAuto;
        list<int> idUti;

};

#endif // PARKING_H
