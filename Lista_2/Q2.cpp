#include <iostream>

using namespace std;


class estudante {
	protected:
	    int matricula, N1, N2;
	    
	public:
		estudante(){
			matricula = 0;
			N1 = 0; N2 = 0;
		}

	    void get() {
	        cout << "Entre Matricula :";
	        cin>> matricula;
	        cout << "Entre notas   :";
	        cin >> N1 >> N2;
    	}
    	
    	void print_data(){
    		cout << "\n# Dados: ";
    		cout << "\nMatricula =: " << matricula;
    		cout << "\nN1 =:  " << N1 << " | N2 =: " << N2 << endl;
		}
    
    
};


int main(){
	/*Letra A e B)*/
	cout << "\n\n|Letra A e B|\n";
	estudante stud_obj1;
	estudante *stud_ptr1 = &stud_obj1;
	
	std::flush(std::cout);
	stud_ptr1->get();
	stud_obj1.print_data();
	
	/*Letra C)*/
	cout << "\n\n|Letra C|\n";
	estudante *stud_ptr2 = new estudante();
	stud_ptr2->get();
	cout << "\n=> objeto dinamicamente alocado:\n";
	stud_ptr2->print_data();

	delete stud_ptr2;

	
	return 1;
}
