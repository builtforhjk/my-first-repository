#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tree[1001],levelTree[1001];
int n;
void dfs(int root, int & pos){
    if(root > n) return;
    dfs(root*2, pos);
    levelTree[root] = tree[pos++];
    dfs(root*2+1,pos);
}
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) scanf("%d",tree+i);
    sort(tree+1,tree+1+n);
    int pos = 1;
    dfs(1,pos);
    for(int i = 1; i <= n; ++i){
        if(i == n) printf("%d\n",levelTree[i]);
        else printf("%d ",levelTree[i]);
    }
    return 0;
}