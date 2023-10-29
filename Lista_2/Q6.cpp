#include <iostream>
#include <string>

using namespace std;

int main(){


	string holder_str, str_1, str_2;
	cout << "\nentre com a string 1: ";
	cin >> str_1;
	cout << "entre com a string 2: ";
	cin >> str_2;
	
	int pos;
	while(true){
		cout << "\nentre com a posicao para inserir a string 2: ";
		cin >> pos;
		if(pos <= str_1.size() && pos >= 0) break;
		else cout << "\n\nescolha uma posicao menor que o tamanho de str_1!\n\n";
	}

	int str1_size, str2_size;
	str1_size = str_1.size();
	str2_size = str_2.size();
	
	holder_str = str_1.substr(pos, str1_size);;
	str_1 = str_1.substr(0,pos);
	str_1 += str_2;
	str_1 += holder_str;
		
	cout << "\n=> str_1 apos insercao =: '" << str_1 << "'\n";
	return 0;
}
