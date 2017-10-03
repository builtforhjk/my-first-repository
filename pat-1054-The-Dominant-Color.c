#include <stdio.h>
int main(){
  int m,n;
  scanf("%d %d",&m,&n);
  int i,j;
  int res;
  int count = 1;
  for(i = 0; i < n; ++i){
    for(j = 0; j < m; ++j){
      int t;
      scanf("%d",&t);
      if(i == 0 && j == 0) res = t;
      else {
        if(res == t) ++count;
        else {
          if(count != 0) --count;
          else res = t;
        }
      }
    }
  }
  printf("%d\n",res);
  return 0;
}
