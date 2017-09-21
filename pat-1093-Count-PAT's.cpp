#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    long long p = 0;
    long long pa = 0;
    long long pat = 0;
    for(auto i : s){
        switch(i){
            case 'P':
                ++p;
                break;
            case 'A':
                pa += p;
                break;
            case 'T':
                pat += pa;
                break;
            default: break;
        }
    }
    cout<<pat%1000000007<<endl;
    return 0;
}
