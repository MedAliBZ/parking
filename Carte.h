#ifndef CARTE_H
#define CARTE_H

#include <iostream>

class Carte
{
    public:
        Carte();
        virtual ~Carte();
        Carte(int,int,double);
        virtual void afficher();
        int getId()const {return id;}

    protected:
        int id;
        int heures;
        double prix;
};

#endif // CARTE_H
