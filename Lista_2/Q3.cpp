#include <iostream>

using namespace std;

int main(){
	float *ptr1 = (float*)calloc(100,sizeof(float));	
	float *ptr2 = (float*)malloc(100*sizeof(float));

	if(ptr1==NULL || ptr2==NULL){
		cout << "\n\t<! fail at memory allocation !>";
		exit(0);
	}

	int ind;
	for(ind=0; ind<100; ind++){
		if(ind!=0) *(ptr1+ind) = ind*0.1;
		*(ptr2+ind) = ind*0.1;
	}

	float acm1=0, acm2=0;
	cout << " *ind | ptr1 | acm1 | *ptr2 | acm2\n";
	for(ind=0; ind<100; ind++){
		acm1 += ptr1[ind];
		acm2 += ptr2[ind];
		cout << ind+1 << " => " << ptr2[ind] << " | " << acm1 << " | " << ptr2[ind] << " | " << acm2 << endl;
	}
		

	free(ptr1);
	free(ptr2);
	return 1;
}
