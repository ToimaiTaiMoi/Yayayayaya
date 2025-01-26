#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
void showMatrix(const bool x[][N]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << x[i][j];
            cout << " ";
        }
        cout << "\n";
    }
}
void inputMatrix(double x[][N]){
    for(int i = 0 ; i < N; i++){
        cout << "Row "<< i+1 <<": ";
        for(int j = 0; j < N;j++){
            cin >> x[i][j];
        }
    }
}
void findLocalMax(const double a[][N], bool b[][N]){
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            if (i == 0 || j == 0 || i == N - 1 || j == N - 1){
                b[i][j] = false;
                continue;
            }
            double current = a[i][j];
            bool isLocalMax = current >= a[i - 1][j] &&
                              current >= a[i + 1][j] &&
                              current >= a[i][j - 1] &&
                              current >= a[i][j + 1];

            b[i][j] = isLocalMax;
        }
    }
}