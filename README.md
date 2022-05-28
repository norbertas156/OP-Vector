# OP-Vector
## Sukurto Vector klasės analizė
### Testas, tikrinantis, jog sukurta Vector klasė, veikia taip pat, kaip ir standartinis std::vector
#### std::vector
Iprasto vector results:
Iprasto vector assign 10 10 10   
Iprasto vector pop_back 10 10    
Iprasto vector push_back 10 10 4 
Iprasto vector before reserve 3  
Iprasto vector after reserve 20  
Iprasto vector before erase 3    
Iprasto vector after erase 0
#### Sukurtas Vector   
Sukuro vector results:
Sukuro vector assign 10 10 10    
Sukuro vector pop_back 10 10     
Sukuro vector push_back 10 10 4  
Sukuro vector before reserve 3   
Sukuro vector after reserve 20   
Sukuro vector before erase 3
Sukuro vector after erase 0
### Vektorių spartos analizė
|      std::vector      |     10000    |    100000   |    1000000   |  10000000  |  100000000 |
|-----------------------|--------------|-------------|--------------|------------|------------|
|        Laikas         |      0 s     | 0.0019996 s |  0.016004 s  |  0.16090 s |  1.56392 s |

|     sukurtas Vector   |     10000    |    100000   |    1000000   |  10000000  |  100000000 |
|-----------------------|--------------|-------------|--------------|------------|------------|
|        Laikas         |      0 s     | 0.0020021 s |  0.0239871 s |  0.18889 s |  1.75581 s |
### Atminties perskirstymas
Atmintis su 100000000 duomenų buvo perskirstyta:
std::vector 27 kartus
std::Vector 27 kartus
### V2.0 veikimas su sukurtu Vector
Su 100000 failu programa užtruku:
std::vector 1,0087008
Sukurtu Vector 0,8968617