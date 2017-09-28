#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int isPrime(int n){
  if(n <= 1) return 0;
  for(int i = 2; i <= sqrt(n); ++i){
    if(n%i == 0) return 0;
  }
  return 1;
}
int main(){
  ios::sync_with_stdio(false);
  int list[10001];
  int visited[10001];
  memset(visited,0,sizeof(visited));
  int n;
  scanf("%d",&n);
  for(int i = 1; i <= n; ++i){
    int id;
    scanf("%d",&id);
    list[id] = i;
  }
  int query;
  scanf("%d",&query);
  for(int i = 0; i < query; ++i){
    int id;
    scanf("%d",&id);
    printf("%04d: ",id);
    if(list[id] == 0) printf("Are you kidding?\n");
    else if(visited[id] == 1) printf("Checked\n");
    else{
      if(list[id] == 1) printf("Mystery Award\n");
      else if(isPrime(list[id]) == 1) printf("Minion\n");
      else printf("Chocolate\n");
      visited[id] = 1;
    }
  }
  return 0;
}
