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


int main(){
	fstream file("matfile4.txt", ios::in);
    if(!file){
        cout << "\n\t<! Erro de abertura !>\n";
        exit(1);
    }

	int rows_1, cols_1, rows_2, cols_2;
    file >> rows_1;
    file >> cols_1;
    //cout << "rows 1: " << rows_1 << " | cols 1: " << cols_1;
    int mat_1[rows_1][cols_1];

    int row, col, num;
    for(row=0; row<rows_1; row++){
    	for(col=0; col<cols_1; col++){
    		file >> num;
            mat_1[row][col] = num;
    	}
    }

    file >> rows_2;
    file >> cols_2;
    int mat_2[rows_2][cols_2];
    //cout << "rows 2: " << rows_2 << " | cols 2: " << cols_2;

    for(row=0; row<rows_2; row++){
    	for(col=0; col<cols_2; col++){
    		file >> num;
    		mat_2[row][col] = num;
    	}
    }

    file.seekg(-1, std::ios::end);
    char operation;
    file >> operation;


    cout << "\nMat1: \n";
    for(int row=0; row<rows_1; row++){
        for(int col=0; col<cols_1; col++){
            cout << " " << mat_1[row][col] << " ";
        }
        cout << "\n";
    }

    cout << "\n\nMat2: \n";
    for(int row=0; row<rows_2; row++){
        for(int col=0; col<cols_2; col++){
            cout << " " << mat_2[row][col] << " ";
        }
        cout << "\n";
    }

    cout << "\nOperation: " << operation;

    switch(operation){
    	case '+':{
    		if(rows_1 != rows_2 || cols_1 != cols_2){
    			cout << "\n\t<! Matrizes de tamanhos diferentes !>\n";
        		exit(1);
    		}

    		int mat_result[rows_1][cols_1];
		    for(int row=0; row<rows_1; row++){
		        for(int col=0; col<cols_1; col++){
		            mat_result[row][col] = mat_1[row][col] + mat_2[row][col];
		        }
		    }

	        cout << "\n\nMatriz resultado: \n";
		    for(int row=0; row<rows_2; row++){
		        for(int col=0; col<cols_2; col++){
		            cout << " " << mat_result[row][col] << " ";
		        }
		        cout << "\n";
		    }

    		break;    		
    	}
    	case '-':{
    		if(rows_1 != rows_2 || cols_1 != cols_2){
    			cout << "\n\t<! Matrizes de tamanhos diferentes !>\n";
        		exit(1);
    		}

			int mat_result[rows_1][cols_1];
			for(int row=0; row<rows_1; row++){
		        for(int col=0; col<cols_1; col++){
		            mat_result[row][col] = mat_1[row][col] - mat_2[row][col];
		        }
		    }

	        cout << "\n\nMatriz resultado: \n";
		    for(int row=0; row<rows_2; row++){
		        for(int col=0; col<cols_2; col++){
		            cout << " " << mat_result[row][col] << " ";
		        }
		        cout << "\n";
		    }

    		break;
    	}
    	case '*':{
    		if(cols_1 != rows_2){
    			cout << "\n\t<! Matrizes não podem ser multiplicadas (# colunas mat_1 != # linhas mat_2) !>\n";
        		exit(1);
    		}

    		int mat_result[rows_1][cols_2];
			for(int row=0; row<rows_1; row++){
		        for(int col=0; col<cols_2; col++){
		            
		            mat_result[row][col] = 0;
		            for(int col_intern=0; col_intern<cols_1; col_intern++){
		            	//if(col_intern == 0) mat_result[row][col] += mat_1[row][col_intern] * mat_2[col_intern][col];
		            	mat_result[row][col] += mat_1[row][col_intern] * mat_2[col_intern][col];
		            }

		            //cout << "\ni" << row << "j" << col << " - " << mat_result[row][col];
		      
		        }
		    }

	        cout << "\n\nMatriz resultado: \n";
			for(int row=0; row<rows_1; row++){
			    for(int col=0; col<cols_2; col++){
			        cout << " " << mat_result[row][col] << " ";
			    }
			    cout << "\n";
			}

    		break;    		
    	}
    }

    file.close();
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