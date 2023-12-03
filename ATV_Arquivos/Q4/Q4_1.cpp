#include <fstream> 
#include <iostream>
#include <cstdlib>

using namespace std;

class Aluno { 
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
	return (n1+n2)/2;
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
    Aluno al[9];
	
    char nomes[9][20] = {'aluno1\0', 'aluno2\0', 'aluno3\0', 'aluno4\0', 'aluno5\0', 'aluno6\0', 'aluno7\0', 'aluno8\0', 'aluno9\0'};
    float notas_1[9] = {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 1.0, 2.0};
    float notas_2[9] = {5.0, 6.0, 8.0, 7.0, 8.0, 2.0, 8.0, 4.0, 8.0};

	fstream arq("alunos.txt", ios::out);	
	if(!arq){
		cout << "\n\n\t<! Erro de abertura !>";
		exit(1);
	}
	
	for(int ind=0, ind){  
		arq.write((char*)&al,sizeof(Aluno)); 
		al.print();
	}
	
	arq.close();
	return 0;	
}
