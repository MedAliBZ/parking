#include <iostream>
#include "Application.h"
#include <typeinfo>

using namespace std;

Application::Application()
{
    //ctor
}

Application::~Application()
{
    for(list<Carte*>::iterator it=cartes.begin();it!=cartes.end();it++){
        delete (*it);
    }
}


Application::Application(const Application& A){
    this->parkings=A.parkings;
    Carte* C;
    for(list<Carte*>::const_iterator it=A.cartes.begin();it!=A.cartes.end();it++){
        if(typeid(**it)==typeid(Carte)){
            C=new Carte(static_cast<const Carte&>(**it));
            this->cartes.push_back(C);
        }
        else if(typeid(**it)==typeid(Abonnement)){
            C=new Abonnement(static_cast<const Abonnement&>(**it));
            this->cartes.push_back(C);
        }
    }
}


Application& Application::operator=(const Application& A){
    if(&A!=this){
        for(list<Carte*>::iterator it=cartes.begin();it!=cartes.end();it++){
            delete (*it);
        }
        this->cartes.clear();
         this->parkings=A.parkings;
        Carte* C;
        for(list<Carte*>::const_iterator it=A.cartes.begin();it!=A.cartes.end();it++){
            if(typeid(**it)==typeid(Carte)){
                C=new Carte(static_cast<const Carte&>(**it));
                this->cartes.push_back(C);
            }
            else if(typeid(**it)==typeid(Abonnement)){
                C=new Abonnement(static_cast<const Abonnement&>(**it));
                this->cartes.push_back(C);
            }
        }
    }
    return *this;
}

void Application::ajouterParking(const Parking p){
    parkings.push_back(p);
}

bool Application::rechercherCarte(int i){
    for(list<Carte*>::iterator it=this->cartes.begin();it!=cartes.end();it++){
        if((*it)->getId()==i)
            return true;
    }
    return false;
}

void Application::ajouterCarte(const Carte& c){
    try{
        if(!rechercherCarte(c.getId())){
            Carte* ca=new Carte(static_cast<const Carte&>(c));
            cartes.push_back(ca);
        }
        else
            throw(c.getId());
    }
    catch (int id){
        cout << "La carte " << id << " existe deja!" << endl;
    }
}

void Application::ajouterCarte(const Abonnement& c){
    try{
        if(!rechercherCarte(c.getId())){
            Carte* ca=new Abonnement(static_cast<const Abonnement&>(c));
            cartes.push_back(ca);
        }
        else
            throw(c.getId());
    }
    catch (int id){
        cout << "L'abonnement " << id << " existe deja!" << endl;
    }
}

void Application::autoriserCarte(Carte c,int refe){
    for(list<Parking>::iterator it=parkings.begin();it!=parkings.end();it++){
        if(it->getRef()==refe){
            if(rechercherCarte(c.getId())){
                if(!it->rechercheAuto(c.getId())){
                    it->ajouterCarteAuto(c.getId());
                    cout<< "i am here" << endl;
                }
                else
                    cout << "carte deja autorise!" << endl;
            }
            else
                cout << "carte invalid!" << endl;
        }
    }
}

void Application::ajouterCarteParking(Carte c,int refe){

    for(list<Parking>::iterator it=parkings.begin();it!=parkings.end();it++){
        if(it->getRef()==refe){
            if(it->rechercheAuto(c.getId())){
                if((it->getPlaces()-it->placesUti())>0 && !it->rechercheUti(c.getId())){
                    it->ajouterCarteUti(c.getId());
                }
            }
            else
                cout << "erreur lors de l ajout" << endl;
        }

    }

}

Parking Application::rechercheParking(){
    list<Parking>::iterator p=parkings.begin();
    double t=(static_cast<double>(p->placesUti())/p->getPlaces());
    for(list<Parking>::iterator it=parkings.begin();it!=parkings.end();it++){
        if((static_cast<double>(p->placesUti())/p->getPlaces())>t){
            t=(static_cast<double>(p->placesUti())/p->getPlaces());
            p=it;
        }
    }
    return *p;
}

void Application::supprimerCarte(int i){
    for(list<Parking>::iterator it=parkings.begin();it!=parkings.end();it++){
        it->supprimerCarteTous(i);
    }
    for(list<Carte*>::iterator it=this->cartes.begin();it!=cartes.end();it++){
        if((*it)->getId()==i){
            delete(*it);
            it=cartes.erase(it);
        }
    }
}

void Application::afficher(){
    cout << endl << "Parking: " << endl;
    for(list<Parking>::iterator it=parkings.begin();it!=parkings.end();it++){
        it->afficher();
    }
    for(list<Carte*>::iterator it=this->cartes.begin();it!=cartes.end();it++){
        (*it)->afficher();
    }
}
