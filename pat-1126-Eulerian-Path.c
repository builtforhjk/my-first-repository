#include <stdio.h>
int pre[520] ,cnt;
void init(int n){
  int i = 0;
  cnt = n;
  for(; i <= n; ++i)
    pre[i] = i;
}
int find(int x){
  return (pre[x]==x?x:pre[x]=find(pre[x]));
}
void merge(int x, int y){
  int r_x = find(x), r_y = find(y);
  if(r_x != r_y) {
    pre[r_y] = r_x;
    --cnt;
  }
}
int main(){
  int degree[520] = {0};
  int n,m;
  scanf("%d%d",&n,&m);
  init(n);
  int i;
  for(i = 0; i < m; ++i){
    int h,t;
    scanf("%d%d",&h,&t);
    ++degree[h];
    ++degree[t];
    merge(h,t);
  }
  int oddPoint = 0;
  for(i = 1; i <= n; ++i){
    printf("%d", degree[i]);
    if(degree[i]%2) ++oddPoint;
    if(i == n) printf("\n");
    else printf(" ");
  }
  if(cnt == 1 && oddPoint == 0) printf("Eulerian\n");
  else if(cnt == 1 && oddPoint == 2) printf("Semi-Eulerian\n");
  else printf("Non-Eulerian\n");
  return 0;
}
