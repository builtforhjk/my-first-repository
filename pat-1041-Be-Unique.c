#include <stdio.h>
int main(){
  int addr[10001] = {0};
  int n;
  scanf("%d",&n);
  int i;
  int src[100001];
  for(i = 0; i < n; ++i){
    scanf("%d",src+i);
    ++addr[src[i]];
  }
  int sign = 0;
  for(i = 0; i < n; ++i){
    if(addr[src[i]] == 1){
      printf("%d\n",src[i]);
      sign = 1;
      break;
    }
  }
  if(!sign) printf("None\n");
  return 0;
}
