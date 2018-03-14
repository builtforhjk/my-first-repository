#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int main(){
  map <string, bool> visited;
  vector<string> follower;
  int m,n,s;
  scanf("%d%d%d",&m,&n,&s);
  bool exchanged = false;
  for(int i = 0; i < m; ++i){
    char str[22];
    scanf("%s",str);
    string tmp(str);
    visited[tmp] = false;
    follower.push_back(tmp);
  }
  for(int i = s; i <= m;){
    if(!visited[follower[i-1]]){
      exchanged = true;
      printf("%s\n",follower[i-1].c_str());
      visited[follower[i-1]] = true;
      i += n;
    }
    else ++i;
  }
  if(!exchanged) printf("Keep going...\n");
  return 0;
}
