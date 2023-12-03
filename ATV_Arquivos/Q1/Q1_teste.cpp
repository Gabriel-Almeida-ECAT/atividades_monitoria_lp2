#include <iostream>

using namespace std;

int main(void){
	char ch = 'a', ch1, ch2;
	int num;

	num = (int)ch;
	cout << endl << "num: " << num;
	ch2 = (char)num;
	cout << endl << "ch2: " << ch2;
	
	cout << "ch + 2: " << ch + 2 << endl;
	
	ch1 = ch + 3;
	printf("ch + 3: %d", ch1);
	printf("\nch + 3: %c", ch1);

	return 0;
}