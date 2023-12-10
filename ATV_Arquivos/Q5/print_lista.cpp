#include <iostream>
#include <fstream>
#include <cstring>
#include "contas.h"

using std::cout;
using std::cin;

int main(){
	std::ifstream arq_le;
	arq_le.open("contas.dat", std::ios::in | std::ios::binary);
	
	if(!arq_le.is_open()){
		puts("\n\n\tErro abertura arquivo.");
		exit(1);
	}
	
	
	arq_le.seekg(0, std::ios::beg);
	for(int i=0; i<50 && !arq_le.eof(); i++){
		conta obj;
		arq_le.read(reinterpret_cast<char*>(&obj), sizeof(conta));
		obj.print();
	}

	arq_le.close();
	char ch;
	ch = getchar();
	return 0;
}