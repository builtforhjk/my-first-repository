#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int pre[1001];
void UFSet_init(){
  int i = 1;
  while(i++ <= 1000) pre[i-1] = i-1;
}
int UFSet_find(int x){
  int r = x;
  while(r != pre[r]) r = pre[r];
  return r;
}
void UFSet_union(int x, int y){
  int r_x = UFSet_find(x);
  int r_y = UFSet_find(y);
  if(r_x != r_y) pre[r_y] = r_x;
}
int main(){
  int n;
  scanf("%d",&n);
  UFSet_init();
  int category[1001];
  int i;
  for(i = 0; i < n; ++i){
    int m;
    scanf("%d:",&m);
    int j;
    int root;
    for(j = 0; j < m; ++j){
      int hobby;
      scanf("%d",&hobby);
      if(j==0){
        root = hobby;
        category[i+1] = root;
      }
      else UFSet_union(root,hobby);
    }
  }
  for(i = 1; i <= n; ++i)
    category[i] = UFSet_find(category[i]);
  unordered_map<int,int> stat;
  for(i = 1; i <= n; ++i)
    ++stat[category[i]];
  vector<int> res;
  for(auto item : stat)
    res.push_back(item.second);
  sort(res.begin(), res.end());
  printf("%lu\n",res.size());
  for(i = res.size()-1; i >= 0; --i){
    printf("%d",res[i]);
    printf(i==0?"\n":" ");
  }
  return 0;
}
