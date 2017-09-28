#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
string convert(int N, int R){
    string total;
    while(N){
        total += to_string(N%R);
        N = N/R;
    }
    return total;
}
int reConvert(string N, int R){
    int base = 1;
    int sum = 0;
    for(int i = N.size(); i > 0; --i){
        sum += (N[i-1]-'0')*base;
        base *= R;
    }
    return sum;
}
bool isPrime(int total){
    if(total <= 1) return false;
    for(int i = 2; i <= sqrt(total); ++i){
        if(total%i == 0) return false;
    }
    return true;
}
bool isReversePrime(int N, int R){
    if(!isPrime(N)) return false;
    string res = convert(N,R);
    int total = reConvert(res,R);
    if(isPrime(total)) return true;
    else return false;
}
int main(){
    int N,R;
    while(1){
        cin>>N;
        if(N < 0) break;
        cin>>R;
        if(isReversePrime(N,R)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
