#include <iostream>
#include <vector>

using namespace std;

vector<int> factorization(int n);

int main(){
    int n = 12;
    vector<int> factors = factorization(n);
    
    cout << "Prime factors of " << n << " are: ";
    for(int i = 0; i < factors.size(); i++){
        cout << factors[i] << " ";
    }
    cout << endl;
    return 0;
}

vector<int> factorization(int n){
    vector<int> factors;
    
    while(n % 2 == 0){
        factors.push_back(2);
        n /= 2;
    }
    
    int divisor = 3;
    while(divisor * divisor <= n){
        while(n % divisor == 0){
            factors.push_back(divisor);
            n /= divisor;
        }
        divisor += 2;
    }
    if(n > 1){
        factors.push_back(n);
    }
    
    return factors;
}