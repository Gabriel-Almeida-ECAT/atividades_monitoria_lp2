#include <iostream>
#include <cstring>
#include <ctype.h>
#include <conio.h>
#include <fstream>

using namespace std;

class conta{
	public:
		int numconta;
		char nome[30];
		double saldo;
		
		conta(){};
		conta(int n, char* name, float sa){
			numconta = n;
			strcpy(nome, name);
			saldo = sa;
		}
		
		void print(){
			cout << "\nNumero Conta: " << numconta << '\n';
			cout << "Nome: " << nome << '\n';
			printf("Saldo: %.2lf\n", saldo);
		}
		
		char* getNome(){
			return nome;
		}
};