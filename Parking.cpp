#include <iostream>
#include "Parking.h"


using namespace std;

Parking::Parking()
{
    refer=0;
    nbPlaces=0;
}

Parking::~Parking()
{
    //dtor
}

Parking::Parking(int r,int n){
    refer=r;
    nbPlaces=n;
}

void Parking::afficher(){
    cout << endl<< "refrence: " << refer << " nbPlaces: " << nbPlaces << endl ;
    cout << "id auto: " << endl;
    for(list<int>::iterator it=idAuto.begin();it!=idAuto.end();it++){
        cout << (*it) << endl;
    }
    cout << "id uti:" << endl;
    for(list<int>::iterator it=idUti.begin();it!=idUti.end();it++){
        cout << (*it) << endl;
    }
}

bool Parking::rechercheAuto(int i){
    for(list<int>::iterator it=idAuto.begin();it!=idAuto.end();it++){
        if((*it)==i)
            return true;
    }
    return false;
}


void Parking::ajouterCarteAuto(int i){
    idAuto.push_back(i);
    cout << "ajoutee " << endl;
    for(auto it=idAuto.begin() ; it!= idAuto.end(); it++)
        cout << (*it) << endl;
}


bool Parking::rechercheUti(int i){
    for(list<int>::iterator it=idUti.begin();it!=idUti.end();it++){
        if(*it==i)
            return true;
    }
    return false;
}


void Parking::ajouterCarteUti(int i){
    idUti.push_back(i);
}

void Parking::supprimerCarteTous(int i){
    for(list<int>::iterator it=idUti.begin();it!=idUti.end();it++){
        if(*it==i)
            it=idUti.erase(it);
    }
    for(list<int>::iterator it=idAuto.begin();it!=idAuto.end();it++){
        if(*it==i)
            it=idAuto.erase(it);
    }
}
