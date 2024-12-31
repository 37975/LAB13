#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N, double B[6]){
    double sum = 0,sum_2 = 0,sum_3 = 0,geo = 1,max = A[0],min = A[0];
    for(int i=0;i < N; i++){
        sum += A[i];
    }
    
    B[0] = sum/N;
    
    for(int i=0;i < N; i++){
        if (A[i] > max){
            max = A[i];
        }
        
        if (A[i] < min){
            min = A[i];
        }
        
        sum_2 += pow((A[i]-B[0]),2);
        sum_3 += 1/A[i];
        geo *= A[i];
    }
    B[1] = sqrt(sum_2/N);
    B[2] = pow(geo,(1.0/6.0));
    B[3] = N/sum_3;
    B[4] = max;
    B[5] = min;
}