#include "Studentai.h"
#include "Library.h"
#include "Prototipai.h"

Studentai::~Studentai() = default;

Studentai::Studentai(const Studentai& studentai){
    vardas_=studentai.vardas_;
    pavarde_=studentai.pavarde_;
    vidurkis_=studentai.vidurkis_;
    egzaminas_=studentai.egzaminas_;
    mediana_=studentai.mediana_;
    pazymiai_=studentai.pazymiai_;
}

Studentai& Studentai::operator=(const Studentai& studentai){
    if(&studentai == this) return *this;

    vardas_ = studentai.vardas_;
    pavarde_ = studentai.pavarde_;
    pazymiai_ = studentai.pazymiai_;
    egzaminas_ = studentai.egzaminas_;
    vidurkis_ = studentai.vidurkis_;
    mediana_ = studentai.mediana_;
    
    return *this;
}

const string &Studentai::vardas() const {return vardas_;}
const string &Studentai::pavarde() const {return pavarde_;}


void Studentai::IrasytiPazymius(int pazymys){
    pazymiai_.push_back(pazymys);
}

void Studentai::IstrintiEgzaminoPazymiIsGalo(){
    pazymiai_.pop_back();
}

void Studentai::EgzaminoPaz(int pazymys){
    egzaminas_=pazymys;
}

void Studentai::ApskaiciuotiVidurki(){
    vidurkis_=Vidurkis(pazymiai_, egzaminas_);
}

void Studentai::ApskaiciuotiMediana(){
    mediana_=Mediana(pazymiai_, egzaminas_);
}