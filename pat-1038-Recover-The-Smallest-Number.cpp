#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(string a, string b){
    return a+b < b+a;
}
int main(){
    int n;
    cin>>n;
    vector<string> xs;
    for(int i = 0; i < n; ++i){
        string s;
        cin>>s;
        xs.push_back(s);
    }
    sort(xs.begin(),xs.end(),cmp);
    bool sign = false;
    for(int i = 0; i < xs.size(); ++i){
        int j = 0;
        if(!sign){
            for(; j < xs[i].size(); ++j){
                if(xs[i][j] != '0'){
                    sign = true;
                    break;
                }
            }
        }
        if(sign){
            cout<<xs[i].substr(j);
        }
    }
    if(!sign) cout<<0;
    cout<<endl;
    return 0;
}
