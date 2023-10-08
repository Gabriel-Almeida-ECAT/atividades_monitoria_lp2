#include <stdlib.h>
#include <iostream>

using namespace std;

class pilha_int{
	private:
		int tamanho;
		int *buffer;
		int *top;
		int current_size;
	
	public:
		
		pilha_int(int tam){
			if(tam > 100){
				buffer = (int*)calloc(100, sizeof(int));
				tamanho = 100;
			} else if(tam <= 0){
				buffer = (int*)calloc(1, sizeof(int));
				tamanho = 1;
			} else{
				buffer = (int*)calloc(tam, sizeof(int));
				tamanho = tam;
			}
			top = buffer;
			
			current_size = 0;
		}
			
		~pilha_int(){
			delete buffer;
			delete top;
		}
		
		int get_tam(){
			return tamanho;
		}
		
		int get_CurSize(){
			return current_size;
		}
		
		void push(int x){ // coloca um elemento no topo da pilha
			//tratativa da pilha cheia
			if(current_size != tamanho){
				*top = x;
				top++;
				current_size++;	
			}
			else{
				cout << "\n\n\t<! erro stack overflow !>\n\n";
			}
		}
		
		int pop(){
			//tratativa da pilha vazia
			if(current_size>0){
				top--;
				current_size--;
				return *top;			
			}else{
				cout << "\n\n\t<! stack underflow !>\n\n";
			}
		}
		
		bool Pvazia(){ // verifica se pilha está vazia
			return current_size == 0 ? true : false;
		}
		
		bool Pcheia(){ // verifica se pilha está cheia
			return current_size == tamanho ?  true : false;
		}
		
		void print(){ ; // mostra a pilha
			if (current_size == 0) cout << "\t=> Pilha vazia\n";
			else{
				cout << "=| Lista |=\n";
				for(int ind=tamanho-1; ind>-1; ind--){
					if(ind+1>current_size){
						cout << ind << " - null\n";
					}
					else cout << ind << " - " << buffer[ind] << endl;
				}
			}
		}
};


int main(void){
	pilha_int pile3(250);
	cout << "Tamanho pile3: " << pile3.get_tam() << endl;
	//pile3.~pilha_int(); /*o código é interrompido ao ser executado a função delete*/
		
	
	pilha_int pile2(-10);
	cout << "\nTamanho pile2: " << pile2.get_tam() << endl;
	//pile2.~pilha_int();
	
	pilha_int pile1(6);
	
	cout << "\n# Pilha inicializada!\n";
	pile1.print();
	
	pile1.push(5);
	pile1.push(1);
	pile1.push(0);
	pile1.push(22);
	cout << "\n# Pilha depois de push\n";
	pile1.print();
	
	cout << "\n# Pilha depois do pop 1 =: " << pile1.pop() << "| current size =: " << pile1.get_CurSize() << endl;
	pile1.print();
	
	cout << "\n# Pilha depois do pop 2 =: " << pile1.pop() << "| current size =: " << pile1.get_CurSize() << endl;
	pile1.print();
	
	cout << "\n# Pilha depois do pop 3 =: " << pile1.pop() << "| current size =: ";
	cout << pile1.get_CurSize() << endl;
	pile1.print();
	
	cout << "\n# Pilha depois do pop 4 =: " << pile1.pop() << "| current size =: ";
	cout << pile1.get_CurSize() << endl;
	pile1.print();
	
	cout << "\n# tetativa de pop com a lista vazia";
	pile1.pop();
	
	
	pile1.push(1);
	pile1.push(1);
	pile1.push(1);
	pile1.push(1);
	pile1.push(1);
	pile1.push(1);
	pile1.print();
	cout << "\n# tetativa de push com a lista cheia";
	//cout << "\n\t=> current size =: " << pile1.get_CurSize() << endl;
	pile1.push(84);
	
	
	pile1.~pilha_int();
	return 0;
}



