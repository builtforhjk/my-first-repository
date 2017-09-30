#include <stdio.h>
int pre[1001];
void UFSet_init(int n){
  int i = 1;
  while(i++ <= n) pre[i-1] = i-1;
}
int UFSet_find(int x){
  int r = x;
  while(r != pre[r]) r = pre[r];
  //路径压缩
  int i = x;
  while(i != r) {
    int tmp = pre[i];
    pre[i] = r;
    i = tmp;
  }
  return r;
}
void UFSet_union(int x, int y){
  int r_x = UFSet_find(x);
  int r_y = UFSet_find(y);
  if(r_x != r_y) pre[r_y] = r_x;
}
int head[500000];
int tail[500000];
int main(){
  int n,m,q;
  scanf("%d %d %d",&n,&m,&q);
  int i;
  for(i = 0; i < m; ++i)
    scanf("%d %d",head+i, tail+i);
  for(i = 0; i < q; ++i){
    UFSet_init(n);
    int check;
    scanf("%d",&check);
    int j;
    for(j = 0; j < m; ++j){
      if(head[j] == check || tail[j] == check) continue;
      UFSet_union(head[j],tail[j]);
    }
    int res = 0;
    for(j = 1; j <= n; ++j)
      res += (pre[j]==j?1:0);
    if(res <= 1) printf("0\n");
    else printf("%d\n",res-2);
  }
  return 0;
}
