#include <iostream>

using namespace std;

void print_count_down(int num){
	if(num==1) cout << num;
	else{
		cout << num << " ";
		print_count_down(num-1);
	}
}

int main(){
	int num = 50;

	print_count_down(num);	

	return 0;
}
