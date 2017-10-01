#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node{
    int val;
    int address;
    int nextAddr;
    Node(int x, int a,int nd):val(x),address(a),nextAddr(nd){}
    Node(){}
};
bool compare(Node p, Node q){
    return p.val < q.val;
}
int main(){
    int n;
    int rootAddr;
    scanf("%d %d",&n,&rootAddr);
    vector <Node> nodes;
    unordered_map<int, Node>memory;
    for(int i = 0; i < n; ++i){
      int addr, val, next;
      scanf("%d %d %d",&addr,&val,&next);
      memory[addr] = Node(val, addr, next);
    }
    while(rootAddr != -1){
      nodes.push_back(memory[rootAddr]);
      rootAddr = memory[rootAddr].nextAddr;
    }
    if(nodes.size() == 0){
        printf("0 -1\n");
        return 0;
    }
    sort(nodes.begin(), nodes.end(), compare);
    printf("%d %05d\n",(int)nodes.size(), nodes[0].address);
    for(int i = 0; i < nodes.size(); ++i){
        printf("%05d %d ",nodes[i].address, nodes[i].val);
        if(i+1 == nodes.size()) printf("-1\n");
        else printf("%05d\n",nodes[i+1].address);
    }
    return 0;
}
