#include <stdio.h>
#include <stdlib.h>
int k;
int queen[1001];
int main(){
  scanf("%d",&k);
  int i;
  for(i = 0; i < k; ++i){
    int j, n;
    scanf("%d",&n);
    for(j = 1; j <= n; ++j){
      scanf("%d",queen+j);
    }
    int sign = 1;
    for(j = 1; j <= n; ++j){
      int r;
      for(r = j+1; r <= n; ++r){
        if(queen[r]==queen[j] || abs(queen[r]-queen[j]) == abs(r-j)){
          sign = 0;
          break;
        }
      }
      if(!sign) break;
    }
    if(!sign) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}
