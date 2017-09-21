#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n%i == 0) return false;
    }
    return true;
}
int mHash(int key, int n,int *hashTable){
    int delta = 0;
    while(hashTable[(key+delta*delta)%n] >= 0){
        ++delta;
        if(delta > (n-1)/2) return -1;
    }
    hashTable[(key+delta*delta)%n] = key;
    return (key+delta*delta)%n;
}
int main(){
    int n,m;
    cin>>n>>m;
    while(!isPrime(n)) ++n;
    int * key = new int[m];
    for(int i = 0; i < m; ++i){
        cin>>key[i];
    }
    int * hashTable = new int[n];
    for(int i = 0; i < n; ++i){
        hashTable[i] = -9999;
    }
    for(int i = 0; i < m; ++i){
        int index = mHash(key[i],n, hashTable);
        if(index < 0) cout<<"-";
        else cout<<index;
        if(i == m-1) cout<<endl;
        else cout<<" ";
    }
    return 0;
}