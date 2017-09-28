#include <stdio.h>
int pre[10001];
void t_init(){
  int i = 0;
  for(; i < 10001; ++i) pre[i] = i;
}
int t_find(int x){
  int r = x;
  while(pre[r] != r) r = pre[r];
  while(x != r){
    int i = pre[x];
    pre[x] = r;
    x = i;
  }
  return r;
}
void t_union(int x, int y){
  int r_x = t_find(x);
  int r_y = t_find(y);
  if(r_x != r_y) pre[r_x] = r_y; 
}
int main(){
  int n;
  scanf("%d",&n);
  t_init();
  int num = 0;
  int i;
  for(i = 1; i <= n; ++i){
    int m;
    scanf("%d",&m);
    int root;
    int j;
    for(j = 0; j < m; ++j){
      int t;
      scanf("%d",&t);
      if(t > num) num = t;
      if(j == 0) root = t;
      else t_union(t, root);
    }
  }
  int tree = 0;
  for(i = 1; i <= num; ++i){
    if(pre[i] == i) ++tree;
  }
  printf("%d %d\n",tree,num);
  int query;
  scanf("%d",&query);
  for(i = 0; i < query; ++i){
    int b1,b2;
    scanf("%d %d",&b1,&b2);
    if(t_find(b1) == t_find(b2)) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
