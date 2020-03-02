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
			matA[i][j] = 10;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matB[i][j] = 10;
		}
	}

	// Displaying matrix A
	cout << endl
		<< "Matrix A" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matA[i][j] << " ";
		}
		cout << endl;
	}
	// Displaying matrix B
	cout<<endl<<"Matrix B"<<endl;
	for (int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<matB[i][j]<<" ";
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

	int** D  = transpose(matA, 4, 4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++){
			cout << D[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}
