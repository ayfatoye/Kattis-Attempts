#include <iostream>
using namespace std;

int sumOfDigits(int m){
    int totalSum = 0;
    while(m != 0){
        totalSum += (m % 10);
        m = m/10;
    }
    return totalSum;
}

int soln(int n){
    // int N;
    // cin >> N;
    
    //cout << "N is " << N << "." << "\n";

    int sumOfN = sumOfDigits(n);
    //cout << "sum of N: " << sumOfN << "\n";
    
    int p = 11;

    
    while(true){
        int m = n * p; // p increases and the program should terminate when p is what we're looking for, N is the input test integer
        //cout << "m: " << m << "\n";
        //cout << "p: " << p << "\n";
        if(sumOfN == sumOfDigits(m)){
            
            break;
        }
        p++;
        // cout << p << " ";
    }

    return p;
}
int main() {
    
    /*
    cin -> n
    while n is not 0:
        cout func(n)
    */
    // while()
    
    int N;
    cin >> N;

    while(N != 0){
        cout << soln(N) << "\n";
        cin >> N;
    }
    
    

    
}