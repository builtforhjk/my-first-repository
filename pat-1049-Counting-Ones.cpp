#include <iostream>
#include <math.h>
using namespace std;
long long getDecimal(int n){
    if(n == 1) return 1;
    else return getDecimal(n-1)*10+pow(10,n-1);
}
long long getOnes(string s){
    if(s.size() == 0) return 0;
    else if(s.size() == 1){
        if(s[0] == '0') return 0;
        else return 1;
    }
    else if(s[0] == '0') return getOnes(s.substr(1));
    else if(s[0] == '1') return getDecimal(s.size()-1)+stoll(s.substr(1))+1+getOnes(s.substr(1));
    else{
        return getDecimal(s.size()-1)*(s[0]-'0')+pow(10,s.size()-1)+getOnes(s.substr(1));
    }
}
int main(){
    string s;
    cin>>s;
    cout<<getOnes(s)<<endl;
    return 0;
}
