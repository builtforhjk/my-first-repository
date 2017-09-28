#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int chip;
    int t = s.size()/3;
    if(s.size()%3 == 0) chip = t+2;
    else chip = t + s.size() - 3*t;
    int i = 0, j = s.size()-1;
    string b;
    for(int k = 0; k < (chip-2); ++k){
        b += ' ';
    }
    while(j - i + 1 != chip){
        cout<<s[i]<<b<<s[j]<<endl;
        ++i;
        --j;
    }
    for(int k = i; k <= j; ++k){
        cout<<s[k];
    }
    cout<<endl;
    return 0;
}
