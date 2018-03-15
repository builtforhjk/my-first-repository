#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  int *data = new int[n+1];
  for(int i = 0; i < n; ++i)
    scanf("%d",data+i);
  sort(data,data+n);
  int sum_l = 0, sum_h = 0;
  for(int i = 0; i < n/2; ++i) sum_l += data[i];
  for(int i = n/2; i < n; ++i) sum_h += data[i];
  printf("%d %d\n",n%2, sum_h-sum_l);
  return 0;
}
