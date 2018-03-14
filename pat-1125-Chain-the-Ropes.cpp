#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  vector<double> rope;
  for(int i = 0; i < n; ++i){
    int tmp;
    scanf("%d",&tmp);
    rope.push_back(tmp);
  }
  sort(rope.begin(), rope.end());
  double res = rope[0];
  for(int i = 1; i < n; ++i){
    res = res/2;
    res += rope[i]/2;
  }
  printf("%d\n",(int)res);
  return 0;
}
