#include <iostream>
#include <cstring>
#include <ctype.h>
#include <conio.h>
#include <fstream>
#include "contas.h"

using namespace std;

int main(){
	ofstream arq_contas("contas.dat", ios::out | ios::binary);
	
	if(!arq_contas){
		puts("\n\n\tErro criação arquivo.");
		exit(1);
	}
	
	arq_contas.seekp(0, ios::beg);
	char str[30] = "sem nome";
	for(int ind=0; ind<50; ind++){
		conta emp((ind+1), str, 0.0);
		if(arq_contas.write(reinterpret_cast<char*>(&emp), sizeof(conta)))
			cout << "Registro " << ind << " criado.\n";
		else{
			puts("\n\n\tErro Escrita.");
			exit(1);		
		}
	}

	puts("Escrita bem sucedida.");
	
	arq_contas.close();	
	return 0;
}
