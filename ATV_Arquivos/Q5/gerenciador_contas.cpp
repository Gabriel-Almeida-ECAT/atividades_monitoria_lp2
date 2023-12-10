#include <iostream>
#include <cstring>
#include <ctype.h>
#include <conio.h>
#include <fstream>
#include "contas.h"

using namespace std;

int get_n(){
	int n=0;
	while(n<1 || n>50){
		printf("Numero Conta [1-50]: ");
		fflush(stdin);
		cin >> n;
		if(n<1 || n>50) puts("Valor invalido. Digite um numero entre 1 e 50.\n");
		else return n;
	}
}

int main(){
	char ch='0', str[10], ch7='7', ch0='0';
	int key=1;
	
	conta conta_obj;
	int pos;
		
	for(;;){
		puts("-----------------------------------------------");
		puts("-=              REGISTRO CONTAS              =-");
		puts("-----------------------------------------------\n");
		puts("|| MENU SELECAO - Digite a operacao deseja ||\n");
		puts("[1] - Inserir");
		puts("[2] - Atualizar");
		puts("[3] - Consultar");
		puts("[4] - Listar");
		puts("[5] - Remover");
		puts("[6] - Sair");
		
		do{
			printf("\n= Selecao: ");
			fflush(stdin);
			ch = getchar();
			if( isdigit(ch) && ch > ch0 && ch < ch7 ){
				key = 0;
			} else printf("\n\n- Valor Invalido! - Selecione um numero de 1 a 6.\n\n");
		}while(key);
	
		switch(ch){
			case '1': /*-=| INSERIR |=-*/
			{
				printf("\n=| Inserir conta |=\n\n");
				ifstream arq_le("contas.dat", ios::in | ios::binary);
			
				if(!arq_le){
					puts("\nErro de acesso ao arquivo.");
					exit(1);
				}
				
				bool key=false;
		
				int n = get_n();
				
				if(arq_le){
					pos = (n-1)*sizeof(conta);
					arq_le.seekg(0, ios::beg);
					arq_le.seekg(pos);
					arq_le.read(reinterpret_cast<char*>(&conta_obj), sizeof(conta));
					if(strcmp(conta_obj.getNome(),"sem nome") == 0) key = true;
					else puts("\nNumero de matricula indisponivel.\n");
				}
				
				arq_le.close();
				if(key){
					fstream arq_es("contas.dat", ios::in | ios::out | ios::binary);
					
					if(!arq_es){
						puts("\nErro de acesso ao arquivo.");
						exit(1);
					}
					
					char str[30];	
					fflush(stdin);
					printf("Nome: ");
					gets(str);
					
					double sa;
					fflush(stdin);
					printf("Saldo: ");
					cin >> sa;
					
					conta conta1(n, str, sa);
					
					if(arq_es){
						pos = (n-1)*sizeof(conta);
						arq_es.seekp(0, ios::beg);
						arq_es.seekp(pos);
						arq_es.write(reinterpret_cast< char *>(&conta1), sizeof(conta));
						puts("\nConta resgistrada.");
					}
					arq_es.close();
				}
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			}
			break;
	
			case '2': /*=| ATUALIZAR |=*/
			{
				printf("\n=| Atualizar conta |=\n\n");
				ifstream arq_le("contas.dat", ios::in | ios::binary);
			
				if(!arq_le){
					puts("\nErro de acesso ao arquivo.");
					exit(1);
				}
				
				bool key=false;
		
				int n = get_n();
				if(arq_le){
					pos = (n-1)*sizeof(conta);
					arq_le.seekg(0, ios::beg);
					arq_le.seekg(pos);
					arq_le.read(reinterpret_cast<char*>(&conta_obj), sizeof(conta));
					if(strcmp(conta_obj.getNome(),"sem nome") != 0) key = true;
					else puts("\nConta inexistente.\n");
				}
				
				arq_le.close();
				
				if(key){
					fstream arq_es("contas.dat", ios::in | ios::out | ios::binary);
					
					if(!arq_es){
						puts("\nErro de acesso ao arquivo.");
						exit(1);
					}
					
					char str[30];						
					fflush(stdin);
					printf("Nome: ");
					gets(str);
					
					double sa;
					fflush(stdin);
					printf("Saldo: ");
					cin >> sa;
					
					conta conta1(n, str, sa);
					
					if(arq_es){
						pos = (n-1)*sizeof(conta);
						arq_es.seekp(0, ios::beg);
						arq_es.seekp(pos);
						arq_es.write(reinterpret_cast< char *>(&conta1), sizeof(conta));
						puts("\nConta atualizado.");
					}
					arq_es.close();
				}
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			}
			break;
	
			case'3': /*=| CONSULTAR |=*/
			{
				printf("\n=| Consultar registro |=\n\n");
				ifstream arq_le("contas.dat", ios::in | ios::binary);
		
				if(!arq_le){
					puts("\nErro de acesso ao arquivo.");
					exit(1);
				}
				
				bool key=false;
		
				int n = get_n();
				
				if(arq_le){
					pos = (n-1)*sizeof(conta);
					arq_le.seekg(0, ios::beg);
					arq_le.seekg(pos);
					arq_le.read(reinterpret_cast<char*>(&conta_obj), sizeof(conta));
					if(strcmp(conta_obj.getNome(),"sem nome") != 0) conta_obj.print();
					else puts("\nRegistro inexistente.\n");
				}

				arq_le.close();
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			}
			break;
	
			case'4': /*=| LISTAR |=*/
			{
				printf("\n=| Listar registro |=\n");
				ifstream arq_le("contas.dat", ios::in | ios::binary);
				
				if(!arq_le){
					puts("\nErro abertura arquivo.");
					exit(1);
				}
				
				arq_le.seekg(0, ios::beg);
				while(arq_le){
					arq_le.read(reinterpret_cast<char*>(&conta_obj), sizeof(conta));
					if (!arq_le.eof()) if(strcmp(conta_obj.getNome(),"sem nome") != 0) conta_obj.print();
				}
				
				arq_le.close();
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			}
			break;
	
			case'5': /*=| REMOVER |=*/
			{
				printf("\n=| Remover conta |=\n");
				
				ifstream arq_le("contas.dat", ios::in | ios::binary);
			
				if(!arq_le){
					puts("\nErro de acesso ao arquivo.");
					exit(1);
				}
				
				bool key1=false;
				bool key2=false;
		
				int n = get_n();
				
				if(arq_le){
					pos = (n-1)*sizeof(conta);
					arq_le.seekg(0, ios::beg);
					arq_le.seekg(pos);
					arq_le.read(reinterpret_cast<char*>(&conta_obj), sizeof(conta));
					if(strcmp(conta_obj.getNome(),"sem nome")!=0){
						conta_obj.print();
						key1 = true;
					} 
					else puts("\nNao cadastrada.\n");
				}
				
				arq_le.close();
				char res = 'a';
				
				if(key1){
					while(res != 'S' && res != 'N'){
						cout << "\nRemover (S/N): ";
						fflush(stdin);
						cin >> res;
						if(res != 'S' && res != 'N') puts("Entrada invalida.");
						else if(res=='S') key2 = true;
					}
				}
				
				double sa=0;
				char str[30] = "sem nome";					
				if(key1 && key2){
					fstream arq_es("contas.dat", ios::in | ios::out | ios::binary);
					
					if(!arq_es){
						puts("\nErro de acesso ao arquivo.");
						exit(1);
					}
					
					conta conta1(n, str, sa);
					
					if(arq_es){
						pos = (n-1)*sizeof(conta);
						arq_es.seekp(0, ios::beg);
						arq_es.seekp(pos);
						arq_es.write(reinterpret_cast<char*>(&conta1), sizeof(conta));
						puts("\nConta removido.");
					}
					arq_es.close();
				}
				
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			}
			break;
	
			case'6': /*-=| EXIT |=-*/
			{
				printf("Saindo.");
				exit(0);
			}
			break;
		}

		system("cls");
	}
	
	return 0;
}



