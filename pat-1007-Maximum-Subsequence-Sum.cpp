#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  int a[10001];
  int sum[10001];
  for(int i = 0; i < n; ++i)
    scanf("%d",a+i);
  sum[0] = a[0];
  int left = a[0], right = a[n-1];
  int pos = 0;
  int maxSum = sum[0];
  for(int i = 1; i < n; ++i){
    sum[i] = max(sum[i-1]+a[i], a[i]);
    if(maxSum < sum[i]) {
      maxSum = sum[i];
      right = a[i];
      pos = i;
    }
  }
  if(maxSum < 0) printf("0 %d %d\n",left,right);
  else {
    printf("%d ",maxSum);
    for(int i = 0; i <= pos; ++i){
      if(sum[i] == a[i]) left = a[i];
    }
    printf("%d %d\n",left,right);
  }
  return 0;
}
