#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  map<int, set<int> >graph;
  for(int i = 0; i < m; ++i){
    int h,t;
    scanf("%d%d",&h,&t);
    graph[h].insert(t);
    graph[t].insert(h);
  }
  int k;
  scanf("%d",&k);
  for(int i = 0; i < k; ++i){
    int nv;
    scanf("%d",&nv);
    int seq[202];
    int visited[202];
    for(int j = 1; j <= n; ++j) visited[j] = 0;
    for(int j = 0; j < nv; ++j){
      scanf("%d",seq+j);
      visited[seq[j]] = 1;
    }
    bool sign = true;
    for(int j = 0; j < nv; ++j){
      for(int jj = j+1; jj < nv; ++jj){
        if(graph[seq[j]].find(seq[jj]) == graph[seq[j]].end()){
          sign = false;
          break;
        }
      }
      if(!sign) break;
    }
    if(!sign) printf("Not a Clique\n");
    else{
      bool exchanged = true;
      for(int j = 1; j <= n; ++j){
        if(visited[j] == 1) continue;
        int cnt = 0;
        for(int jj = 0; jj < nv; ++jj){
          if(graph[seq[jj]].find(j) != graph[seq[jj]].end()) ++ cnt;
        }
        if(cnt == nv){
          exchanged = false;
          break;
        }
      }
      if(!exchanged) printf("Not Maximal\n");
      else printf("Yes\n");
    }
  }
  return 0;
}
