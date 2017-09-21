#include <iostream>
#include <map>
using namespace std;
typedef struct Tuple{
    bool status;
    int count;
    Tuple(bool x, int y):status(x),count(y){}
}Tuple;
Tuple isMiss(string s1, string s2){
    map<char, int> dict1;
    map<char, int> dict2;
    int i = 0;
    while(1){
        if(i >= s1.size() && i >= s2.size()) break;
        if(i < s2.size()){
            if(dict2.find(s2[i]) == dict2.end()) dict2[s2[i]] = 1;
            else ++dict2[s2[i]];
        }
        if(i < s1.size()){
            if(dict1.find(s1[i]) == dict1.end()) dict1[s1[i]] = 1;
            else ++dict1[s1[i]];
        }
        ++i;
    }
    bool flag = true;
    int count = 0;
    for(auto item : dict2){
        if(dict1[item.first] < item.second){
            flag = false;
            count += item.second - dict1[item.first];
        }
    }
    if(flag) count = s1.size() - s2.size();
    return Tuple(flag, count);
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    Tuple res = isMiss(s1, s2);
    if(res.status) cout<<"Yes "<<res.count<<endl;
    else cout<<"No "<<res.count<<endl;
    return 0;
}
