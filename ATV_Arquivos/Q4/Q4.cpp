#include <fstream> 
#include <iostream>
#include <cstring>

using namespace std;

 class Aluno{ 
	char nome[50]; 
	float n1;
	float n2;

	public :
		Aluno(char* nome_aluno, float nota1, float nota2) {
	        strncpy(nome, nome_aluno, sizeof(nome) - 1);
	        nome[sizeof(nome)-1] = '\0';

	        n1 = nota1;
	        n2 = nota2;
    	}

		float media();
		void print();
};

float Aluno::media(){
	float med = (n1+n2)/2;
	return med;
}
 
void Aluno::print(){
	cout << "[" << nome << "]";
	cout << "[" << n1 << "]";
	cout << "[" << n2 << "]";
	cout << "[" << media() << "]";
	if(media() >= 6.0) cout << "[Aprovado]\n";
	else cout << "[Reprovado]\n";
} 

   
int main() {
	ifstream arq("alunos.txt", ios::in);
	
	if(!arq){
		cout << "\n\n\t<! Erro de abertura !>";
		exit(1);
	}

	char nome[50];
	float nota_1, nota_2;
	int ind=0;

	while(arq >> nome >> nota_1 >> nota_2){  
		cout << "\ndados lidos -> nome: " << nome << " | nota1: " << nota_1 << " | nota2: " << nota_2 << endl;
		Aluno al(nome,nota_1,nota_2);
		al.print();
	}
	
	arq.close();
	return 0;	
}
