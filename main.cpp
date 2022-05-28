#include "Library.h"
#include "Prototipai.h"
#include "MainPrototipai.h"
#include "Studentai.h"


int main(){

  Vector <Studentai> student;
  Vector <Studentai> kietekai;

  char tikrinimas{};
  cout<<"Ar studentai bus rasomi ranka ar skaitomi is failo ? Iveskite: (i-ivedami, s-skaitomi is failo )"<<endl;
  char raide = RaidesTikrinimas('i','s');
if(raide == 'i'){
  while(tikrinimas != 'n'){
  Ivedimas(student);
  cout<<"Ar dar bus studentu ? Iveskite: (t-taip, n-ne)"<<endl;
  tikrinimas = RaidesTikrinimas('t','n');
  if(tikrinimas == 'n')
  break;
    }
  }
  else if(raide == 's'){
      cout<<"Ar norite, kad studentu failas butu sugeneruotas. Iveskite: (t-taip, n-ne)"<<endl;
      raide = RaidesTikrinimas('t','n');
      if(raide == 'n'){
        SkaitymasIsFailo(student);
      } else{

            cout<<"Iveskite studentu skaiciu"<<endl;
            int sk = SkaiciausTikrinimams();
            AtsitiktinisFailas(sk); 
            SkaitymasIsFailo(student);
      }
};



    auto st3 = std::chrono::high_resolution_clock::now();
    Paskirstymas(student,kietekai);
    std::chrono::duration<double> df3 = std::chrono::high_resolution_clock::now()-st3; // Skirtumas (s)
     std::cout << "Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: "<< df3.count() << " s\n";

    IsvedimasIFaila(kietekai,"kietekai");
    IsvedimasIFaila(student,"nelaimingieji");

    //std::cout << "Studentu rykiavimas uztruko: "<< RykiavimoLaikas << " s\n";
    std::cout << "Studentu isvedimas i faila uztruko: "<< IsvedimoLaikas<< " s\n";



}