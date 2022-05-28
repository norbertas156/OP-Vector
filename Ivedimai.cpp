#include "Studentai.h"
#include "Studentai.cpp"


void Ivedimas(Vector<Studentai> &stud){

  string vardas;
  string pavarde;

  unsigned seed =std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(1, 10);

  int kiekis=0;
  int pazymiuSk;
  int pazymys;
  cout<<"Iveskite studento varda"<<endl;
  cin>>vardas;
  cout<<"Iveskite studento pavarde"<<endl;
  cin>>pavarde;
  Studentai studentai(vardas, pavarde);

  cout<<"Ar studento pazymiu skaicius yra zinomas ? Iveskite:(t-taip, n-ne)"<<endl;
  char ats = RaidesTikrinimas('t','n');
      if(ats=='t'){
        cout<<"Iveskite pazymiu skaiciu"<<endl;
        pazymiuSk = SkaiciausTikrinimams();
        cout<<"Ar norite, kad pazymiai ir egzamino pazymys butu sugeneruoti ar rasomi ranka? Ivestike:(t-sugeneruoti, n-ivesti ranka)"<<endl;
        ats = RaidesTikrinimas('t','n');
        if(ats == 't'){
          for (int j = 0; j < pazymiuSk; j++)
          {
            int pazymys = distribution(generator);
            studentai.IrasytiPazymius(pazymys);
            cout<<j+1<<"-as sugeneruotas pazymys "<<pazymys<<" ; ";
          }
          cout<<endl;
          pazymys = distribution(generator);
          studentai.EgzaminoPaz(pazymys) ;
          cout<<"Egzamino sugeneruotas pazymys: "<<pazymys<<endl;
        } else if(ats == 'n'){
          for(int j = 0; j < pazymiuSk;j++){
          cout<<"Iveskite "<<j+1<< "-a(-i) pazymi:"<<endl;
            studentai.IrasytiPazymius(PazymioTikrinimas());
          }
          cout<<"Iveskite Egzamino rezultata: "<<endl;
          pazymys = PazymioTikrinimas();
          studentai.EgzaminoPaz(pazymys);
        }  
      }
      else if(ats=='n'){
          char paz = 't';
          int kiekis = 0;
        cout<<"Ar norite, kad pazymiai ir egzamino pazymys butu sugeneruoti ar rasomi ranka? Ivestike:(t-sugeneruoti, n-ivesti ranka)"<<endl;
        ats = RaidesTikrinimas('t','n');
        if(ats == 't'){
            while(paz != 'n'){
              int pazymys = distribution(generator);
              studentai.IrasytiPazymius(pazymys);
              cout<<kiekis + 1<<"-as sugeneruotas pazymys = "<<pazymys<<endl;
              kiekis++;
              cout<<"Ar norite sugeneruoti dar viena pazymi? Iveskite:(t-taip, n-ne)"<<endl;
              paz = RaidesTikrinimas('t','n');
              if(paz == 'n')
              break;
            }
            pazymys = distribution(generator);
            studentai.EgzaminoPaz(pazymys);
          cout<<"Egzamino sugeneruotas pazymys: "<<pazymys<<endl;
        }else if(ats == 'n'){
            while(paz != 'n'){
              cout<<"Ivskite "<<kiekis+1<<"-a(-i) pazymi: "<<endl;
              pazymys = PazymioTikrinimas();
            studentai.IrasytiPazymius(pazymys);
            kiekis++;
            cout<<"Ar norite dar ivesti pazymiu? Iveskite:(t-taip, n-ne)"<<endl;
            paz = RaidesTikrinimas('t','n');
            if(paz == 'n')
            break;
            }
            cout<<"Iveskite Egzamino rezultata: "<<endl;
            studentai.EgzaminoPaz(PazymioTikrinimas());
        }    
      };
       studentai.ApskaiciuotiVidurki();
       studentai.ApskaiciuotiMediana();
       stud.push_back(studentai);
}

void SkaitymasIsFailo(Vector<Studentai> &stud){
  bool good = false;

  Vector<string> splited;
  string line;
  stringstream buf;
  string vardas;
  string pavarde;

  cout<<"Iveskite failo pavadinima (be .txt)"<<endl;
  string FailoPav;
  int paz;
  cin>>FailoPav;


  while(!good){
    ifstream fs(FailoPav+".txt");
  if(fs.good()){

     buf<<fs.rdbuf();
     fs.close();

    break;
  }
    else{
      cout<<"Tokio failo nera, iveskite egzistuojanti faila"<<endl;
      cin>>FailoPav;
    }
  }
  
  getline(buf, line);


  auto start = std::chrono::high_resolution_clock::now();

  int klaida = 0;
  while(getline(buf, line)){
    bool error = false;
    istringstream sk(line);
    sk>>vardas>>pavarde;
    Studentai studentai(vardas, pavarde);
          while (sk>>paz)
          {
            klaida++;
            if(paz>=1 && paz<=10){
              studentai.IrasytiPazymius(paz);
            }else{
              error = true;
              break;
            }
          }
      if(error){
        cout<<klaida<<" eilute yra blogai suvesti pazymiai"<<endl;
      }else{
        studentai.IstrintiEgzaminoPazymiIsGalo();
        studentai.EgzaminoPaz(paz);
        
        studentai.ApskaiciuotiVidurki();
       studentai.ApskaiciuotiMediana();
        stud.push_back(studentai);
      }        
  }
         std::chrono::duration<double> df4 = std::chrono::high_resolution_clock::now()-start; 
  std::cout << "Duomenu nuskaitymas is failo: "<< df4.count() << " s\n";
}

void AtsitiktinisFailas(int sk){
    int n;
    unsigned seed =std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 10);


    if(sk >= 1000000){
       n = 5;
    }else{
       n = 15;
    }
    std::uniform_int_distribution<int> PazymiuSkdistribution(5, n);

    string studentaiFile="stud"+std::to_string(sk);
    ofstream fd (studentaiFile+".txt");

    fd<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Pavarde";
    int PazymiuSk=PazymiuSkdistribution(generator);
    for (int i=0; i<PazymiuSk; i++){
      fd<<left<<setw(15)<<"ND"+std::to_string(i+1);
    }
    fd<<left<<setw(15)<<"Egz."<<endl;

    for(int i=0; i<sk; i++){
      fd<<left<<setw(15)<<"Vardas"+std::to_string(i+1)<<left<<setw(20)<<"Pavarde"+std::to_string(i+1);
      for(int j=0; j<PazymiuSk; j++){
        fd<<left<<setw(15)<<distribution(generator);
      }
      fd<<left<<setw(15)<<distribution(generator)<<endl;
    }
    fd.close();

}
