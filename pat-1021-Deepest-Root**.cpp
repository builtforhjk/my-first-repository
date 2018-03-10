#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
using namespace std;
int pre[10001];
bool visited[10001];
int cnt;
void init(int n){
  for(int i = 0; i <= n; ++i)
    pre[i] = i;
  cnt = n;
}
void clear(int n){
  for(int i = 0; i <= n; ++i)
    visited[i] = false;
}
int find(int x){
  return (x==pre[x]?x:(pre[x]=find(pre[x])));
}
void merge(int x, int y){
  int r_x = find(x), r_y = find(y);
  if(r_x != r_y) {
    pre[r_y] = r_x;
    --cnt;
  }
}
map<int, vector<int> > graph;
void BFS(int root, set<int>& res, int n){
  clear(n);
  int queue[10001];
  int front = 0, back = 0, last = 0;
  queue[back++] = root;
  visited[root] = true;
  while(front != back){
    if(last == front){
      res.clear();
      last = back;
    }
    int tmp = queue[front++];
    res.insert(tmp);
    for(auto rear : graph[tmp]){
      if(!visited[rear]){
        queue[back++] = rear;
        visited[rear] = true;
      }
    }
  }
}
int main(){
  int n;
  scanf("%d",&n);
  init(n);
  for(int i = 1; i < n; ++i){
    int h,t;
    scanf("%d%d",&h,&t);
    graph[h].push_back(t);
    graph[t].push_back(h);
    merge(h,t);
  }
  if(cnt > 1){
    printf("Error: %d components\n",cnt);
    return 0;
  }
  set<int> first_res, second_res;
  BFS(1, first_res, n);
  for(auto p : first_res){
    set<int> tmp_res;
    BFS(p, tmp_res, n);
    second_res.insert(tmp_res.begin(), tmp_res.end());
  }
  second_res.insert(first_res.begin(), first_res.end());
  for(auto item : second_res) printf("%d\n", item);
  return 0;
}
