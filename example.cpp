#include "./lib.h"



using namespace std; 



int main() {



	int** matA = new int*[4];

	for(int i = 0; i <4; i++)

		matA[i] = new int[4];



	int** matB = new int*[4];

	for(int i = 0; i <4; i++)

			matB[i] = new int[4];



	for (int i = 0; i < 4; i++) { 

		for (int j = 0; j < 4; j++) { 

			matA[i][j] = rand() % 10; 

		} 

	} 



	for (int i = 0; i < 4; i++) { 

		for (int j = 0; j < 4; j++) { 

			matB[i][j] = rand() % 10; 

		} 

	}

	

	// Displaying matrix A 

	cout << endl 

		<< "Matrix A" << endl; 

	for (int i = 0; i < 4; i++) { 

		for (int j = 0; j < 4; j++) {

			cout << matA[i][j] << "\t"; 

		}

		cout << endl; 

	}

	// Displaying matrix B 

	cout<<endl<<"Matrix B"<<endl;

	for (int i=0;i<4;i++){

		for(int j=0;j<4;j++){

			cout<<matB[i][j]<<"\t";

		}

		cout << endl; 

	}

	// Transpose of Matrix A

	cout<<endl<<"Transpose of Matrix A"<<endl;

	int** D  = transpose(matA, 4, 4);



	for (int i = 0; i < 4; i++) { 

		for (int j = 0; j < 4; j++){ 

			cout << D[j][i] << "\t";

		}

		cout << endl; 

	}

	// Transpose of Matrix B

	cout<<endl<<"Transpose of Matrix B"<<endl;

	int** E  = transpose(matA, 4, 4);



	for (int i = 0; i < 4; i++) { 

		for (int j = 0; j < 4; j++){ 

			cout << E[j][i] << "\t";

		}

		cout << endl; 

	}

	int** matC = multMatrix(matA, matB, 4, 4, 4, 4);



	for (int i = 0; i < 4; i++) { 

		for (int j = 0; j < 4; j++){ 

			cout << matC[i][j] << "\t";

		}

		cout << endl; 

	}



	

	return 0; 

}

