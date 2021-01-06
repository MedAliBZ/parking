#ifndef ABONNEMENT_H
#define ABONNEMENT_H

#include "Carte.h"


class Abonnement : public Carte
{
    public:
        Abonnement();
        virtual ~Abonnement();
        Abonnement(int,int,double,int);
        void afficher();

    protected:
        int dateExp;
        int gratuit;
};

#endif // ABONNEMENT_H
