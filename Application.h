#ifndef APPLICATION_H
#define APPLICATION_H

#include "Parking.h"

class Application
{
    public:
        Application();
        virtual ~Application();
        Application(const Application&);
        Application& operator=(const Application&);
        void ajouterParking(const Parking);
        bool rechercherCarte(int);
        void ajouterCarte(const Carte&);
        void ajouterCarte(const Abonnement&);
        void autoriserCarte(Carte,int);
        void ajouterCarteParking(Carte,int);
        Parking rechercheParking();
        void supprimerCarte(int);
        void afficher();

    protected:
        list<Parking> parkings;
        list<Carte*> cartes;
};

#endif // APPLICATION_H
