#include <stdio.h>
int array[100002];
int prior[100001];
int minor[100001];
int main(){
  int n;
  scanf("%d",&n);
  int i;
  scanf("%d",array+1);
  minor[1] = array[1];
  for(i = 2; i <= n; ++i){
    scanf("%d",array+i);
    if(array[i-1] > minor[i-1]) minor[i] = array[i-1];
    else minor[i] = minor[i-1];
  }
  prior[n] = array[n];
  for(i = n-1; i >= 1; --i){
    if(array[i+1] < prior[i+1]) prior[i] = array[i+1];
    else prior[i] = prior[i+1];
  }
  int count = 0;
  int res[100001];
  for(i = 1; i <= n; ++i){
    if(array[i] >= minor[i] && array[i] <= prior[i]){
      res[count++] = array[i];
    }
  }
  printf("%d\n",count);
  for(i = 0; i < count; ++i){
    printf("%d",res[i]);
    if(i+1 != count) printf(" ");
  }
  printf("\n");
  return 0;
}
