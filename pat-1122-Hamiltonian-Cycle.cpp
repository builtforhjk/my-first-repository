#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
map<int, set<int> > graph;
int n,m;
bool isHCycle(int *cycle, int num){
  if(num != n+1) return false;
  if(cycle[0] != cycle[num-1]) return false;
  int visited[202] = {0};
  int pre = cycle[0];
  visited[pre] = 1;
  for(int i = 1; i < (num-1); ++i){
    if(visited[cycle[i]] == 1) return false;
    else if(graph[pre].find(cycle[i]) == graph[pre].end()) return false;
    else{
      visited[cycle[i]] = 1;
      pre = cycle[i];
    }
  }
  if(graph[pre].find(cycle[num-1]) == graph[pre].end()) return false;
  return true;
}
int main(){
  scanf("%d %d",&n,&m);
  for(int i = 0; i < m; ++i){
    int h,t;
    scanf("%d %d",&h,&t);
    graph[h].insert(t);
    graph[t].insert(h);
  }
  int q;
  scanf("%d",&q);
  int cycle[10000];
  for(int i = 0; i < q; ++i){
    int num;
    scanf("%d",&num);
    for(int j = 0; j < num; ++j){
      scanf("%d",cycle+j);
    }
    printf(isHCycle(cycle, num)?"YES\n":"NO\n");
  }
  return 0;
}
