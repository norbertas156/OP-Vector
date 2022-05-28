#include "Library.h"
#include "Studentai.h"



char RezultatuTikrinimas(){
char r;
cin>>r;
  while(r!='v' || r!='m'|| r !='a'){
      if(r=='v'){
        break;
      }else if(r=='m'){
        break;
      }else if(r == 'a'){
        break;
      }else{
        cout<<"Bloga ivestis. Iveskite:(v-pagal vidurki, m-pegalmediana, a-pagal abu)"<<endl;
        cin>>r;
      }
  };
  return r;
}

char RaidesTikrinimas(char x, char y){
char raide;
cin>>raide;
  while(raide!=x || raide!=y){
      if(raide==x){
        break;
      }else if(raide==y){
        break;
      }else{
        cout<<"Bloga ivestis. Iveskite:("<<x<<" arba "<<y<<endl;
        cin>>raide;
      }
  };
  return raide;
}

int SkaiciausTikrinimams(){
  int sk;
  cin>>sk;
  while (sk < 0 || isdigit(sk)==false)
  {
    if(sk > 0 || isdigit(sk)==true){
      break;
    }else{
    cin.clear();
    cin.ignore();
    cout<<"Bloga ivestis. Iveskite skaiciu, kuris butu didesnis uz 0:"<<endl;
    cin>>sk;
    }
  };
  return sk;
}

int PazymioTikrinimas(){
  int paz;
  cin>>paz;
  while (paz < 0 || paz > 10)
  {
    if (paz > 0 && paz <= 10)
    {
      break;
    }else{
      cout<<"Iveskite skaiciu nuo 1 iki 10"<<endl;
      cin>>paz;
    }   
  }
  return paz;
}

