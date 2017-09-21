#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int,int>leaf;
map <int,vector<int> > hierarchy;
void searchLeaves(int root,int level){
    if(leaf.find(level) == leaf.end()) leaf[level] = 0;
    if(hierarchy.find(root) == hierarchy.end()){
        ++leaf[level];
        return;
    }
    for(int i = 0; i < hierarchy[root].size(); ++i){
        searchLeaves(hierarchy[root].at(i),level+1);
    }
}
int main(){
    int node,nonLeaf;
    cin>>node>>nonLeaf;
    for(int i = 0; i < nonLeaf; ++i){
        int father;
        int chi;
        cin>>father>>chi;
        vector <int> children;
        for(int j = 0; j < chi; ++j){
            int child;
            cin>>child;
            children.push_back(child);
        }
        hierarchy[father] = children;
    }
    searchLeaves(01,1);
    leaf[1] = 0;
    for(auto item:leaf){
        cout<<item.second;
        if((++leaf.find(item.first)) != leaf.end()){
            cout<<" ";
        }
    }
    cout<<endl;
    return 0;
}