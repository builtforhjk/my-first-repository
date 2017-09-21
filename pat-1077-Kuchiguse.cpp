#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
bool compare(string s1, string s2){
    return s1.size() < s2.size();
}
int main(){
    int n;
    cin>>n;
    cin.get();
    vector<string> lines;
    for(int i = 0; i < n; ++i){
        string temp;
        getline(cin,temp);
        lines.push_back(temp);
    }
    sort(lines.begin(), lines.end(),compare);
    vector<char> suffix;
    for(int i = 0; i < lines[0].size(); ++i){
        int flag = 1;
        char t = lines[0].at(lines[0].size()-1-i);
        for(int j = 1; j < lines.size(); ++j){
            if(lines[j].at(lines[j].size()-1-i) != t){
                flag = 0;
                break;
            }
        }
        if(flag) suffix.push_back(t);
        else break;
    }
    for(auto it = suffix.rbegin(); it != suffix.rend(); ++it){
        cout<<*it;
    }
    if(suffix.size() == 0){
        cout<<"nai";
    }
    cout<<endl;
    return 0;
}
