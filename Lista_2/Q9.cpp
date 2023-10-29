#include <iostream>

using namespace std;

void print_count_down(int num){
	if(num < 0) num *= -1;
	if(num==1) cout << num;
	else{
		cout << num << " ";
		print_count_down(num-1);
	}
}

int main(){
	int num = -5;

	print_count_down(num);	

	return 0;
}
