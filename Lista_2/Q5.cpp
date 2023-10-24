#include <iostream>
#include "Q5.h"

using std::cout;
using std::endl;

int main(){
	Ponto3d P1(2, -1,0), P2(1,4,-2), P3;

    cout << P1;
    cout << P2;
	cout << P3;

 
	P3 = P1 + P2;
    cout << P3;

    P3 = P1 - P2;
    cout << P3;

	if(P1 == P2) cout << "\npontos iguais";
    else cout << "\npontos diferentes" ;
    
    cout << "\nDistancia entre P1 e P2 = "<< distancia (P1,P2);

	return 0;
}
