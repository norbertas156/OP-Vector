#ifndef MainPrototipai_H_INCLUDED
#define MainPrototipai_H_INCLUDED

#include "Studentai.h"
#include "Library.h"
#include "Ivedimai.cpp"
#include "Isvedimas.cpp"


void SkaitymasIsFailo(Vector<Studentai> &stud);
void AtsitiktinisFailas(int sk);
void Isvedimas(Vector<Studentai> & stud);
void IsvedimasIFaila(Vector<Studentai> & stud, string FileName);


#endif