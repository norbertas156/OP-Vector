#include "Library.h"
#include "Vector.h"

using namespace std;

void iprastoVectorTestas(){
vector<int> iprastasVector;
cout<<"Iprasto vector results:"<<endl;

iprastasVector.assign(3, 10);
cout<<"Iprasto vector assign ";
for(int i=0; i<iprastasVector.size(); i++){
    cout<<iprastasVector[i]<<" ";
}
iprastasVector.pop_back();
cout<<"\nIprasto vector pop_back ";
for(int i=0; i<iprastasVector.size(); i++){
    cout<<iprastasVector[i]<<" ";
}
iprastasVector.push_back(4);
cout<<"\nIprasto vector push_back ";
for(int i=0; i<iprastasVector.size(); i++){
    cout<<iprastasVector[i]<<" ";
}
cout<<"\nIprasto vector before reserve "<<iprastasVector.capacity()<<endl;
iprastasVector.reserve(20);
cout<<"Iprasto vector after reserve "<<iprastasVector.capacity()<<endl;
cout<<"Iprasto vector before erase "<<iprastasVector.size()<<endl;
iprastasVector.erase(iprastasVector.begin(), iprastasVector.end());
cout<<"Iprasto vector after erase "<<iprastasVector.size()<<endl;
}
void sukurtoVectorTest(){
    Vector<int> sukurtasVector;
cout<<"Sukuro vector results:"<<endl;

sukurtasVector.assign(3, 10);
cout<<"Sukuro vector assign ";
for(int i=0; i<sukurtasVector.size(); i++){
    cout<<sukurtasVector[i]<<" ";
}
sukurtasVector.pop_back();
cout<<"\nSukuro vector pop_back ";
for(int i=0; i<sukurtasVector.size(); i++){
    cout<<sukurtasVector[i]<<" ";
}
sukurtasVector.push_back(4);
cout<<"\nSukuro vector push_back ";
for(int i=0; i<sukurtasVector.size(); i++){
    cout<<sukurtasVector[i]<<" ";
}
cout<<"\nSukuro vector before reserve "<<sukurtasVector.capacity()<<endl;
sukurtasVector.reserve(20);
cout<<"Sukuro vector after reserve "<<sukurtasVector.capacity()<<endl;
cout<<"Sukuro vector before erase "<<sukurtasVector.size()<<endl;
sukurtasVector.erase(sukurtasVector.begin(), sukurtasVector.end());
cout<<"Sukuro vector after erase "<<sukurtasVector.size()<<endl;
}

void iprastoVectorEfektyvumoAnalize(){
    vector<int> normal;
    int sz=10000;
    int count=0;
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
for(int i=0; i<sz; i++){
    normal.push_back(i);
        if(normal.size()==normal.capacity()){
        count++;
    }
}
std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
cout <<"spartos analize std::vector "<<sz<<" dydzio sekundemis: "<<diff.count()<<endl;
cout<<"perskirstymai "<<count<<endl;

}
void sukurtoVectorEfektyvumoAnalize(){
        Vector<int> experimental;
    int sz=10000;
    int count=0;
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
for(int i=0; i<sz; i++){
    experimental.push_back(i);
    if(experimental.size()==experimental.capacity()){
        count++;
    }
}
std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
cout <<"spartos analize sukurto Vector "<<sz<<" dydzio sekundemis: "<<diff.count()<<endl;
cout<<"perskirstymai "<<count<<endl;

}




int main(){
    iprastoVectorTestas();
    sukurtoVectorTest();
    iprastoVectorEfektyvumoAnalize();
    sukurtoVectorEfektyvumoAnalize();

    return 0;    
}