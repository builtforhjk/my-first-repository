#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0
int main(){
  int a,b;
  scanf("%d %d",&a,&b);
  int c = a+b;
  bool sign = false;
  if(c < 0) sign = true;
  c = abs(c);
  int clip[50];
  int count = 0;
  if(c == 0){
    printf("0\n");
    return 0;
  }
  while(c){
    clip[count++] = c%1000;
    c = c/1000;
  }
  printf(sign?"-":"");
  for(int i = count-1; i >= 0; --i){
    if(i==count-1) printf("%d",clip[i]);
    else printf("%03d",clip[i]);
    printf(i==0?"\n":",");
  }
  return 0;
}
