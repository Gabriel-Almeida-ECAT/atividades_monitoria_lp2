/* 2.	Escreva um programa em C, que lê a partir de um arquivo de entrada, 
duas matrizes descritas da seguinte forma: Os dois primeiros valores, para 
cada matriz, identificam respectivamente o número de linhas e colunas, e os 
demais elementos são os valores a serem inseridos na matriz, sendo que a 
mesma deve ser preenchida no sentido das linhas. A partir da leitura das 
matrizes, o programa deverá ler uma operação matemática básica (+ - ou *) e 
verificar se a operação poderá ser realizada, de acordo com as dimensões das 
matrizes lidas. Se a operação puder ser realizada, todos os elementos 
correspondentes nas matrizes devem ser operados e as matrizes originais e a 
matriz resultado devem ser impressas na tela */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class matrizes{
	public:
		int rows_1, cols_1, rows_2, cols_2;
        int *mat_1, *mat_2;
        char operation;

		void read_file(string file_name){
			fstream file(file_name, ios::in);
		    if(!file){
		        cout << "\n\t<! Erro de abertura !>\n";
		        exit(1);
		    }

		    file >> rows_1;
		    file >> cols_1;
		    //cout << "rows 1: " << rows_1 << " | cols 1: " << cols_1;
		    mat_1 = new int[rows_1*cols_1];

            int row, col, num;
		    for(row=0; row<rows_1; row++){
		    	for(col=0; col<cols_1; col++){
		    		file >> num;
                    *(mat_1 + (rows_1*row) + col) = num;
		    	}
		    }

		    file >> rows_2;
		    file >> cols_2;
            mat_2 = new int[rows_2*cols_2];
		    //cout << "rows 2: " << rows_2 << " | cols 2: " << cols_2;

		    for(row=0; row<rows_2; row++){
		    	for(col=0; col<cols_2; col++){
		    		file >> num;
		    		*(mat_2 + (rows_1*row) + col) = num;
		    	}
		    }

		    file.seekg(-1, std::ios::end);
		    file >> operation;

		    file.close();
		}

		void print_mats(){
            cout << "\nMat1: \n";
            for(int row=0; row<rows_1; row++){
                for(int col=0; col<cols_1; col++){
                    cout << " " << *(mat_2 + (rows_1*row) + col) << " ";
                }
                cout << "\n";
            }

            cout << "\n\nMat2: \n";
            for(int row=0; row<rows_2; row++){
                for(int col=0; col<cols_2; col++){
                    cout << " " << *(mat_2 + (rows_2*row) + col) << " ";
                }
                cout << "\n";
            }

            cout << "\nOperation: " << operation;
		}

        ~matrizes(){
            free(mat_1);
            free(mat_2);
        }
};


int main(){
	matrizes mat;

	mat.read_file("matfile.txt");
    mat.print_mats();

	return 0;
}



/*
{1 2 3 4 5 6 7 8 9}
mat[1][ind2]
2[ind2]


{{1 2 3} {4 5 6} {7 8 9}}
mat[ind1][ind2]
{4 5 6}[ind2]
*/