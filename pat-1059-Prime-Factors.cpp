#include <iostream>
#include <math.h>
#include <map>
using namespace std;
int isPrime(long int a){
    long int i = 2;
    while(i <= sqrt(a)){
        if(a%i == 0) return 0;
        ++i;
    }
    return 1;
}
int main(){
    map<long int, int>factor;
    long int n;
    cin>>n;
    if(isPrime(n)) cout<<n<<"="<<n<<endl;
    else{
        int m = n;
        for(long int i = 2; i <= sqrt(n);){
            if(isPrime(i) && (n%i == 0)){
                ++factor[i];
                n = n/i;
                if(isPrime(n)){
                    ++factor[n];
                    break;
                }
            }
            else ++i;
        }
        cout<<m<<"=";
        for(auto it = factor.begin(); it != factor.end(); ++it){
            if(it!=factor.begin()) cout<<"*";
            if((*it).second == 1) cout<<(*it).first;
            else cout<<(*it).first<<"^"<<(*it).second;
        }
        cout<<endl;
    }
    return 0;
}
