#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool cmp(int x,int y){
  return x > y;
}
int main(){
  int n;
  scanf("%d",&n);
  int arr[100001];
  for(int i = 0; i < n; ++i){
    scanf("%d",arr+i);
  }
  sort(arr,arr+n,cmp);
  int ans = 0;
  for(int i = 0; i < n; ++i){
    if(arr[i] > ans && arr[i] > (i+1)) ++ans;
  }
  printf("%d\n",ans);
  return 0;
}
