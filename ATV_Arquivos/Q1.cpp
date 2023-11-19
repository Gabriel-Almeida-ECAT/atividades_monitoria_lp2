//string encriptografada teste
//testar com 144
#include <iostream>
#include <fstream>
#include <cstring>
#define size_message 250

using namespace std;


void encripStr2File(){
	fstream file;
	char str[size_message];

	fflush(stdin);
	cout << "Entre com a string para encriptografia: ";
	gets(str);

	int k = -1;
	while(k < 1 || k > 255){
		cout << "entre o valor para encriptografia [1/255]: ";
		fflush(stdin);
		cin >> k;
		if(k < 1 || k > 255) cout << "\n\tvalor invalido.\n";
	}

	file.open("encfile.txt", ios::out);
	if(!file){
		cout << "\n\t<! Erro de abertura !>\n";
		exit(1);
	}
	
	cout << endl;

	char enc_char;
	int enc_int;
	bool overpass;
	for(int ind=0; ind < strlen(str); ind++){
		overpass=false;

		enc_int = (int)str[ind] + k;
		if(enc_int > 255){
			enc_int = enc_int - 255;
			overpass = true;
		}

		enc_char = (char)enc_int;

		//if(overpass) cout << str[ind] << " -> " << enc_char << (char)191 << " | ";
		if(overpass) cout << str[ind] << " -> " << enc_char << "(overpass)" << " | ";
		else cout << str[ind] << " -> " << enc_char << " | ";

		file << enc_char;
		if(overpass) file << (char)64; //simbolo de interrogação invertido
	}


	file.close();
}

int decriptFile(char* file_name){
	fstream file;

	file.open(file_name, ios::in);
	if(!file){
		cout << "\n\t<! Erro de abertura !>\n";
		exit(1);	
	}

	int k = -1;
	while(k < 1 || k > 255){
		cout << "entre o valor de encriptografia [1/255] := ";
		fflush(stdin);
		cin >> k;
		if(k < 1 || k > 255) cout << "\n\tvalor invalido.\n";
	}

	int ind=0;
	char enc_str[size_message];
	while(!file.eof()){
		file >> enc_str[ind++];
	}
	enc_str[ind] = '\0';
	cout << "texto original lido =: " << enc_str << endl << endl;

	int enc_num, enc_num2, ind_atribution=0;
	bool skip = false;
	char dec_str[size_message];
	for(int ind=0; ind < strlen(enc_str)-1 ; ind++){
		if(skip){
			skip = false;
			continue;
		}

		enc_num = (int)enc_str[ind];
		enc_num2 = (int)enc_str[ind+1];
		//cout << "\nenc_num2: " << enc_num2 << endl;

		if(enc_num2 == 64){
			cout << char(enc_num + 255 - k)<< " <-(op) " << (char)enc_num << " | ";
			enc_num = enc_num + 255 - k;
			dec_str[ind_atribution++] = (char)enc_num;
			skip = true;
		}
		else{
			cout << char(enc_num - k)<< " <- " << (char)enc_num << " | ";
			enc_num = enc_num - k;
			dec_str[ind_atribution++] = (char)enc_num;
		}

	}
	dec_str[ind-1] = '\0';
	cout << "\n\ntexto decriptografado =: " << dec_str;	

	file.close();
}


int main(void){
	int choice=0;
	while(choice != 3){
		cout << "\n\n-----------------------------\n";
		cout << "# escolha a opcao: \n";
        cout << "[1] Encriptar uma string para arquivo.\n";
        cout << "[2] Desencriptar uma string de um arquivo.\n";
        cout << "[3] Sair.\n";
        cout << "Escolha := ";
        cin >> choice;

        switch(choice){
        	case 1:
        		encripStr2File();
        		break;

        	case 2:
        		char str[size_message];
        		cout << "\nEntre com o nome do arquivo := ";
        		fflush(stdin);
        		gets(str);
        		decriptFile(str);
        		break;

        	case 3:
        		break;
        }
	}

	return 0;
}