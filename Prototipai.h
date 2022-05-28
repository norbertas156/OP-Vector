#ifndef Prototipai_H_INCLUDED
#define Prototipai_H_INCLUDED

#include "Tikrinimai.cpp"
#include "Studentai.h"
#include "VidMed.cpp"

double Vidurkis(vector<float> &pazymiai, int egzaminas);
double Mediana(vector<float> &pazymiai, int egzaminas);
char RezultatuTikrinimas();
char RaidesTikrinimas(char x, char y);
int SkaiciausTikrinimams();
int PazymioTikrinimas();
void SkaitymasIsFailo();
void Paskirstymas (vector<Studentai> &student, vector<Studentai> &kietekai,vector<Studentai> &nelaimingieji);

#endif