#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
	ifstream arq1("arq11.txt");
	ifstream arq2("arq21.txt");
	char str1[80], str2[80];
	
	if(!arq1 && !arq2){
		cout << "\n\n\t<! Erro de abertura !>";
		exit(1);
	}

	while(arq1){
		arq1.getline(str1,80); //é orbrigatorio eu passar o tamanho máximo da string
		arq2.getline(str2,80);		
		if (arq1) if(!strcmp(str1,str2)) cout << str1 << endl;
	}
	
	arq1.close();
	arq2.close();
	return 0;
}
