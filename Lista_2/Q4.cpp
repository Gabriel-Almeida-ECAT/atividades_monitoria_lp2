#include <iostream>
#include <cmath>

class conta{
	public:
		float saldo;
		
		conta(){saldo = 0;}
		
		void extrato(){
			printf("\nSaldo da conta: %.2f\n", saldo);
		}
		
		void depositar(float x){
			x < 0 ? x *= -1, saldo += x : saldo += x;
			printf("\nDepositando: %.2f", x);
			printf("\nSaldo da conta: %.2f\n", saldo);
		}
		
		void sacar(float x){
			x < 0 ? x *= -1, saldo -= x : saldo -= x;			
			printf("\nSacando: %.2f", x);
			printf("\nSaldo da conta: %.2f\n", saldo);
		}
		
		virtual void atualizarsaldo(float taxa){
			printf("\nSaldo previo: %.2f\n", saldo);
			saldo *= 1 + std::fabs(taxa)/100;
			printf("Saldo atual: %.2f\n", saldo);
		}
};

class contaCorrente: public conta{
	public:
		void atualizarsaldo(float taxa){
			taxa < 0 ? taxa *= -1, taxa = (taxa/100)*2 : taxa = (taxa/100)*2;
			taxa += 1;
			printf("\nSaldo previo: %.2f\n", saldo);
			saldo *= taxa;
			printf("Saldo atual: %.2f\n", saldo);
		}
};

class contaPoupanca: public conta{
	public:
		void atualizarsaldo(float taxa){
			printf("\nSaldo previo: %.2f\n", saldo);
			saldo *= 1 + (std::fabs(taxa)/100)*3;
			printf("Saldo atual: %.2f\n", saldo);
		}		
};

int main(){
	conta conta1, *p;
	contaCorrente contaCorrente1;
	contaPoupanca contaPoupanca1;
	
	conta1.extrato();	
	conta1.depositar(300.25);
	conta1.sacar(100.25);
	conta1.atualizarsaldo(10);
	
	p = &conta1;
	p->atualizarsaldo(10);
	
	printf("\n= contaCorrente1: ");
	contaCorrente1.depositar(100);
	p = &contaCorrente1;
	p->atualizarsaldo(10);

	printf("\n= contaPoupanca1: ");
	contaPoupanca1.depositar(100);
	p = &contaPoupanca1;
	p->atualizarsaldo(10);
	
	return 0;
}