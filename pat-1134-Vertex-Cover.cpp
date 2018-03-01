#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;
typedef struct Node{
  int head;
  int tail;
  Node(){}
  Node(int x, int y):head(x),tail(y){}
}Edge;
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  vector<Edge> graph;
  for(int i = 0; i < m; ++i){
    int h,t;
    scanf("%d%d",&h,&t);
    graph.push_back(Edge(h,t));
  }
  int k;
  scanf("%d",&k);
  for(int i = 0; i < k; ++i){
    int Nv;
    scanf("%d",&Nv);
    unordered_set<int> vertex;
    for(int j = 0; j < Nv; ++j){
      int tmp;
      scanf("%d",&tmp);
      vertex.insert(tmp);
    }
    bool flag = true;
    for(int j = 0; j < m; ++j){
      if(vertex.find(graph[j].head) == vertex.end() && vertex.find(graph[j].tail) == vertex.end()){
        flag = false;
        printf("No\n");
        break;
      }
    }
    if(flag) printf("Yes\n");
  }
  return 0;
}
