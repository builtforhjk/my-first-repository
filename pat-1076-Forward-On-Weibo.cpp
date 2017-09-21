#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> follows[1001];
int n,L;
int forward(int post){
  int total = 0;
  int visited[1001] = {0};
  int dist[1001] = {0};
  int queue[10001];
  int rear = 0, head = 0;
  queue[rear++] = post;
  while(rear != head){
    int tmp = queue[head++];
    if(dist[tmp] > L) break;
    if(visited[tmp] == 0){
      for(int i = 0; i < follows[tmp].size(); ++i){
        if(visited[follows[tmp][i]] == 0){
          queue[rear++] = follows[tmp][i];
          if(dist[follows[tmp][i]] == 0) dist[follows[tmp][i]] = dist[tmp]+1;
        }
      }
      ++total;
      visited[tmp] = 1;
    }
  }
  return total-1;
}
int main(){
    scanf("%d%d",&n,&L);
    for(int i = 1;i <= n; ++i){
      int t;
      scanf("%d",&t);
      for(int j = 0; j < t; ++j){
        int f;
        scanf("%d",&f);
        follows[f].push_back(i);
      }
    }
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; ++i){
      int q;
      scanf("%d",&q);
      printf("%d\n",forward(q));
    }
    return 0;
}