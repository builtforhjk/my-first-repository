#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int digitSum(int x){
  int sum = 0;
  while(x){
    sum += x%10;
      x /= 10;
  }
  return sum;
}
int main(){
  int n;
  scanf("%d",&n);
  set<int>stat;
  for(int i = 0; i < n; ++i){
    int in;
    scanf("%d",&in);
    int sum = digitSum(in);
    stat.insert(sum);
  }
  printf("%d\n",(int)stat.size());
  int count = 0;
  for(auto iter = stat.begin(); iter != stat.end(); ++iter){
    printf("%d",*iter);
    ++count;
    printf(count == stat.size()?"\n":" ");
  }
  return 0;
}
