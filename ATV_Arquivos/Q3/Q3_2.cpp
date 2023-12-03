#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int get_number_lines(string file_name){
	ifstream arq(file_name);
	if(!arq){
		cout << "\n\n\t<! Erro de abertura !>";
		exit(1);
	}

	int num_lines = 0;
    string line;
    while(getline(arq, line)){
        num_lines++;
    }

    arq.close();
    return num_lines;
}

bool is_new_string(string test_string, string list_strings[], int current_size){
	for(int ind=0; ind<current_size; ind++){
		if(test_string == list_strings[ind]){
			return false;
		}
	}

	return true;
}	

int main(){
	int str_max_size = 200;
	string name_arq1 = "arq11.txt";
	string name_arq2 = "arq21.txt";

	int num_lines_1;
	num_lines_1 = get_number_lines(name_arq1);

	int num_lines_2;
	num_lines_2 = get_number_lines(name_arq2);

	int most_lines, smaler_file;
	//int most_lines = (num_lines_1 > num_lines_2)*num_lines_1 + (num_lines_1 < num_lines_2)*num_lines_2;
	if(num_lines_1>num_lines_2){
		most_lines = num_lines_1;
		smaler_file = 2;
	}else{
		most_lines = num_lines_2;
		smaler_file = 1;
	}
	string strs_arq_1[num_lines_1], strs_arq_2[num_lines_2], comon_strs[most_lines];


	ifstream arq1(name_arq1);
	if(!arq1){
		cout << "\n\n\t<! Erro de abertura !>";
		exit(1);
	}

	string str_holder;
	int current_size=0;
	for(int ind=0; ind<num_lines_1; ind++){
		getline(arq1, str_holder); //é orbrigatorio eu passar o tamanho máximo da string
		if(is_new_string(str_holder, strs_arq_1, current_size)){
			strs_arq_1[current_size] = str_holder;
			current_size++;
		}
	}


	ifstream arq2(name_arq2);
	if(!arq2){
		cout << "\n\n\t<! Erro de abertura !>";
		exit(1);
	}

	current_size=0;
	for(int ind=0; ind<num_lines_2; ind++){
		getline(arq2, str_holder); //é orbrigatorio eu passar o tamanho máximo da string
		if(is_new_string(str_holder, strs_arq_2, current_size)){
			strs_arq_2[current_size] = str_holder;
			current_size++;
		}
	}

	arq1.close();
	arq2.close();

	int curr_ind=0;
	if(smaler_file==1){
		for(int ind1=0; ind1<num_lines_1; ind1++){
			for(int ind2=0; ind2<num_lines_2; ind2++){
				if(strs_arq_1[ind1] == strs_arq_2[ind2]){
					comon_strs[curr_ind++] = strs_arq_1[ind1];
				}
			}	
		}
	}else{
		for(int ind1=0; ind1<num_lines_2; ind1++){
			for(int ind2=0; ind2<num_lines_1; ind2++){
				if(strs_arq_2[ind1] == strs_arq_1[ind2]){
					comon_strs[curr_ind++] = strs_arq_2[ind1];
				}
			}	
		}	
	}

	for(int ind=0; ind<curr_ind; ind++){
		cout << comon_strs[ind] << endl;
	}

	return 0;
}
