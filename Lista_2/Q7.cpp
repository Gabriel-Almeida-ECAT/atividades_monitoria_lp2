#include <iostream>
#include <string>

using namespace std;

int main(){
	int ind;
	string str_1;
	
	cout << "\nentre com a string: ";
	cin >> str_1;

	ind = str_1.find("ca");
	while( ind >= 0){
		str_1.erase( ind , ind+2 );
		ind = str_1.find("ca");
	}
	
	cout << str_1;
	return 0;
}
