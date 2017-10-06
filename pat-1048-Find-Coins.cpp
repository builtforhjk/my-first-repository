#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(){
    int total, fare;
    cin>>total>>fare;
    int * coin = new int[total];
    for(int i = 0; i < total; ++i){
        cin>>coin[i];
    }
    sort(coin,coin+total);
    int flag = 0;
    for(int i = 0, j = total-1; i != j;){
        if(coin[i]+coin[j] == fare){
            flag = 1;
            cout<<coin[i]<<" "<<coin[j]<<endl;
            break;
        }
        else if(coin[i]+coin[j] > fare) --j;
        else ++i;
    }
    if(!flag) cout<<"No Solution"<<endl;
    return 0;
}
