#include "Library.h"
#include "Prototipai.h"
#include "Studentai.h"

void PrintToFile(string file_name, std::stringstream& data)
{
    ofstream fr(file_name);
    fr << data.rdbuf();
    fr.close();
}

void IsvedimasIFaila(Vector<Studentai> &stud, string FileName){

  Vector<Studentai>::iterator it;
  // auto start1 = std::chrono::high_resolution_clock::now();

  //  sort(stud.begin(), stud.end(),[](Studentai a, Studentai b){
  //   return a.vardas() < b.vardas();
  //   });

  //   std::chrono::duration<double> df5 = std::chrono::high_resolution_clock::now()-start1; 
  // RykiavimoLaikas += df5.count();

  auto start = std::chrono::high_resolution_clock::now();

stringstream outputas;
outputas<<std::left << std::setw(20)<< "Vardas";
outputas<<std::left << std::setw(20)<< "Pavarde";
outputas<<std::left << std::setw(20)<< "Galutinis(vid.)";
outputas<<std::left << std::setw(20)<< "Galutinis(Med.)";
outputas<<endl;

for(it=stud.begin(); it!=stud.end(); ++it){
  outputas<<std::left << std::setw(20)<< it->vardas();
  outputas<<std::left << std::setw(20)<< it->pavarde();
  outputas<<std::left << std::setw(20)<< it->StudentoVidurkis();
  outputas<<std::left << std::setw(20)<< it->StudentoMediana();
  outputas<<endl;
}

PrintToFile(FileName + ".txt", outputas);

std::chrono::duration<double> df = std::chrono::high_resolution_clock::now()-start; 
  IsvedimoLaikas += df.count();
}

