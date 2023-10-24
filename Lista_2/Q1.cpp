#include <iostream>

using namespace std;

int main(){
	int x = 10;	
	int var[] = {30, 10, 20, 40, -10, 0, 10, -20, 40, 30};
	char str[20] = {"Minha string"};
	int numero1 = 10, numero2 = 20;
	

	/*Letra A)*/
	cout << "\n\n|Letra A |\n";
	int *ptr = &x;
	cout << "Valor de =: " << *ptr;
	

	/*Letra B)*/
	cout << "\n\n|Letra B |\n";
	cout << "Endereço x =: " << ptr;
	

	/*Letra C*/
	cout << "\n\n|Letra C |\n";
	int *ptr_i, num=0;
	ptr_i = &num;
	cout << "Valor de ptr_i =: " << *ptr_i;
	
	int size_var = sizeof(var)/sizeof(var[0]);
	cout << "\nValor de size_var =: " << size_var;
	
	for(int ind=0; ind<size_var; ind++){
		*ptr_i += var[ind];
		cout << "\n" << ind << " - " << *ptr_i;
	}
	
	cout << "\nValor da soma de var =: " << *ptr_i;


	/*Letra D*/
	cout << "\n\n| Letra D |\n";
	char *ptr_ch = &str[0];
	cout << "String str =: ";
	puts(ptr_ch);
	
	
	/*Letra E*/
	cout << "\n| Letra E |\n";
	int *ptr1, *ptr2, *ptr3;
	int holder;
	
	cout << "numero1 =: " << numero1 << " | numero2 =: " << numero2;
	ptr1 = &numero1;
	ptr2 = &numero2;
	ptr3 = &holder;
	
	*ptr3 = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *ptr3;
	
	cout << "\nnumero1 =: " << numero1 << " | numero2 =: " << numero2;
	
	
	return 1;
}
