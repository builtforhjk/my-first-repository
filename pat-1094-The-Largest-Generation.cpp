#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, vector<int> > family;
map<int,int> stat;
void levelTraversal(int root,int level){
    for(auto child : family[root]){
        if(stat.find(level) == stat.end()) stat[level] = 1;
        else ++stat[level];
        levelTraversal(child, level+1);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; ++i){
        int p,k;
        cin>>p>>k;
        for(int j = 0; j < k; ++j){
            int ch;
            cin>>ch;
            family[p].push_back(ch);
        }
    }
    levelTraversal(1, 2);
    stat[1] = 1;
    int res = 0, pos;
    for(auto item : stat){
        if(item.second > res){
            pos = item.first;
            res = item.second;
        }
    }
    cout<<res<<" "<<pos<<endl;
    return 0;
}