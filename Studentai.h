#pragma once

#include "Library.h"
#include "Vector.h"

class Zmogus{
    protected:
    string vardas_;
    string pavarde_;
    public:
    explicit Zmogus(){
        vardas_="";
        pavarde_="";
    };
    explicit Zmogus(const string &vardas,const string &pavarde){
    vardas_=vardas;
    pavarde_=pavarde;
    };
    virtual const string &vardas() const=0;
    virtual const string &pavarde() const=0;
};

class Studentai: public Zmogus{
    private:
    float egzaminas_;
    Vector <float> pazymiai_;
    double vidurkis_;
    double mediana_;
    public:
    Studentai(): egzaminas_(0){}

    ~Studentai();
    Studentai(const Studentai& studentai);
    Studentai& operator = (const Studentai& studentai);

    explicit Studentai(const string &vardas, const string &pavarde):Zmogus(vardas, pavarde){};
    const string &vardas() const override;
    const string &pavarde() const override;
    inline Vector<float> getPazymiai() const {return pazymiai_;}
    inline double StudentoVidurkis() const {return vidurkis_;}
    inline double StudentoMediana() const {return mediana_;}
    inline int getEgzaminas() const {return egzaminas_;}

    void IrasytiPazymius(int);
    void IstrintiEgzaminoPazymiIsGalo();
    void EgzaminoPaz(int);
    void ApskaiciuotiVidurki();
    void ApskaiciuotiMediana();
};
