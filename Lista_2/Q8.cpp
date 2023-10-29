#include <iostream>
#include <cstring> //strcpy
#include <string>

using namespace std;

int main(){
	string str_holder, str_1 = "cacatua", str_2;
	str_2 = str_1;
	int half_ind, str_size = str_1.size();
	
	(str_size % 2) == 0 ? half_ind = str_size/2 : half_ind = (str_size-1)/2;
	cout << "\nTamnho string: " << str_size << " metade: " << half_ind << endl;

	str_holder = str_1.substr(half_ind, str_size);
	str_1 = str_1.substr(0, half_ind);
	str_1 += "@@@";
	str_1 += str_holder;

	str_2.insert(half_ind, "@@@");
	
	cout << "\n=> string 1 apos insercao =: '" << str_1 << "'\n";
	cout << "\n=> string 2 apos insercao =: '" << str_2 << "'\n";
	return 0;
}
