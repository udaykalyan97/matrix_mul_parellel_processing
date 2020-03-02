/*This program creates a random matrix, calculates its transpose and
outputs multiplication of this matrix and its transpose
A - matrix of size mxn
B - transpose of A nxm
C - resultant multiplication of A x B
*/
//standard header files
#include <iostream>
#include <stdlib.h>
using namespace std;

// maximum number of threads
#define MAX_THREAD 4
#define MAX 4 //max size of matrix

int rowsA, rowsB, colsA, colsB;

int step_i = 0;

struct Mat {
    int** A;
    int** B;
    int** C;
};

struct Mat_long {
    long** A;
    long** B;
    long** C;
};

void* multi(void* arguments)
{
	 Mat *args = (Mat*)arguments;
	int core = step_i++;

	// Each thread computes 1/4th of matrix multiplication
	for (int i = core * MAX / 4; i < (core + 1) *  MAX/ 4; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				(args->C)[i][j] += (args->A)[i][k] * (args->B)[k][j];
			}
		}
	}
}

void* multi_long(void* arguments)
{
	 Mat_long *args = (Mat_long*)arguments;
	int core = step_i++;

	// Each thread computes 1/4th of matrix multiplication
	for (int i = core * MAX / 4; i < (core + 1) *  MAX/ 4; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				(args->C)[i][j] += (args->A)[i][k] * (args->B)[k][j];
			}
		}
	}
}

// Integer matrix multiplication
int** multMatrix(int** A, int** B, int rA, int cA, int rB, int cB)
{
	try{
		rowsA=rA;
		colsA=cA;
		rowsB=rB;
		colsB=cB;

		if(colsA != rowsB) {
			throw 1;
		}

		int** C = new int*[rowsA];
		for(int i = 0; i <rowsA; i++)
   			C[i] = new int[colsB];

   		for(int i=0; i<rowsA; i++) {
   			for(int j=0; j<colsB; j++) {
   				C[i][j]=0;
   			}
   		}

   		Mat *args = new Mat;
   		args->A=A;
   		args->B=B;
   		args->C=C;

		// declaring four threads
		pthread_t threads[MAX_THREAD];

		// Creating four threads, each evaluating its own part

		for (int i = 0; i < MAX_THREAD; i++) {
			pthread_create(&threads[i], NULL, multi, (void*)(args));
		}

		// joining and waiting for all threads to complete
		for (int i = 0; i < MAX_THREAD; i++)
			pthread_join(threads[i], NULL);

		// Displaying the result matrix
		cout << endl << "Multiplication of A and B" << endl;
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < colsB; j++){
				cout << args->C[i][j] << "\t";
			}
			cout << endl;
		}
		return args->C;
	}
	catch(int e){
		if(e==1) {
			cout<<"Multiplication can't be performed as dimensions does not match"<<endl;
		}
		else {
			cout<<"Error occured"<<endl;
		}
    }
}

//Transpose of a matrix
int** transpose(int** A, int rows, int cols) {
	int** B = new int*[rows];
	for(int i = 0; i <rows; i++)
		B[i] = new int[cols];
	for (int i=0;i<cols;i++){
		for(int j=0;j<rows;j++){
			B[i][j]=A[i][j];
		}
	}
	return B;
}

//Long matrix multiplication
long** multMatrix(long** A, long** B, int rA, int cA, int rB, int cB) {
	try{
		rowsA=rA;
		colsA=cA;
		rowsB=rB;
		colsB=cB;

		if(colsA != rowsB) {
			throw 1;
		}

		long** C = new long*[rowsA];
		for(int i = 0; i <rowsA; i++)
   			C[i] = new long[colsB];

   		Mat_long *args = new Mat_long;
   		args->A=A;
   		args->B=B;
   		args->C=C;

		// declaring four threads
		pthread_t threads[MAX_THREAD];

		// Creating four threads, each evaluating its own part

		for (int i = 0; i < MAX_THREAD; i++) {
			pthread_create(&threads[i], NULL, multi_long, (void*)(args));
		}

		// joining and waiting for all threads to complete
		for (int i = 0; i < MAX_THREAD; i++)
			pthread_join(threads[i], NULL);

		// Displaying the result matrix
		cout << endl << "Multiplication of A and B" << endl;
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < colsB; j++){
				cout << args->C[i][j] << "\t";
			}
			cout << endl;
		}
		return args->C;
	}
	catch(int e){
		if(e==1) {
			cout<<"Multiplication can't be performed as dimensions does not match"<<endl;
		}
		else {
			cout<<"Error occured"<<endl;
		}
    }
}