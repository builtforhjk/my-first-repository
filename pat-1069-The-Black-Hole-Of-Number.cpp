#include <iostream>
#include <algorithm>
using namespace std;
int func(int a){
    if(a==0) return 1;
    else return func(a-1)*10;
}
int sortInt(int a, bool type){
    int val[4];
    for(int i = 0; i < 4; ++i){
        val[i] = a/func(i)%10;
    }
    sort(val,val+4);
    if(type) return val[0]*1000+val[1]*100+val[2]*10+val[3];
    else return val[3]*1000+val[2]*100+val[1]*10+val[0];
}
int main(){
    int n;
    cin>>n;
    int prior = sortInt(n,false);
    int minor = sortInt(n,true);
    while(1){
        int diff = prior - minor;
        if(prior == minor){
            printf("%04d - %04d = 0000\n",n,n);
            break;
        }
        else{
            printf("%04d - %04d = %04d\n",prior, minor, diff);
            if(diff == 6174) break;
        }
        prior = sortInt(diff,false);
        minor = sortInt(diff,true);
    }
    return 0;
}
