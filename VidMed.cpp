#include "Library.h"
#include "Studentai.h"



double Vidurkis(Vector<float> &pazymiai, int egzaminas){
  double vidurkis = 0;
  double galutinis;
  int pazymiuSk = pazymiai.size();
  for(int j = 0; j < pazymiuSk; j++){
    vidurkis += pazymiai[j];
  }
  vidurkis = vidurkis / (pazymiuSk);
  galutinis = 0.4*vidurkis + egzaminas * 0.6;

  return galutinis;
}

double Mediana(Vector<float> &pazymiai, int egzaminas){
double mediana;
double galutinis;
int pazymiuSk = pazymiai.size();
std::sort(pazymiai.begin(), pazymiai.end() );
if((pazymiuSk + 1 )% 2 == 0){
  mediana = pazymiai[pazymiuSk / 2];
}else{
  mediana = (pazymiai[pazymiuSk / 2 - 1] + pazymiai[(pazymiuSk / 2 ) ]) /2.0;
}
galutinis = mediana * 0.4 + egzaminas * 0.6;

return galutinis;
}


void Paskirstymas (Vector<Studentai> &student, Vector<Studentai> &kietekai){

 for(auto &temp : student){
      if(temp.StudentoVidurkis() >= 5.00)
        kietekai.push_back(temp);
  }

  student.erase(
      std::remove_if(student.begin(), student.end(), [&](Studentai const & student){
      return student.StudentoVidurkis() >= 5.00;
    }),
    student.end());

}