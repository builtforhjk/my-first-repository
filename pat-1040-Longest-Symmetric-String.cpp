#include <iostream>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int count = 0;
    for(int i = 0; i < (s.size()-count); ++i){
        int curCount = 0;
        bool flag = false;
        int i_c = i;
        int j_c;
        for(int j = s.size()-1; j >= 0; --j){
            if(flag && (i_c >= s.size() || s[i_c] != s[j])){
                i_c = i;
                if(curCount > count) count = curCount;
                curCount = 0;
                flag = false;
                j = j_c;
                continue;
            }
            else if(flag){
                ++i_c;
                ++curCount;
            }
            else if(!flag && s[i_c] == s[j]){
                ++curCount;
                ++i_c;
                j_c = j;
                flag = true;
            }
        }
        if(curCount > count) count = curCount;
    }
    cout<<count<<endl;
    return 0;
}
