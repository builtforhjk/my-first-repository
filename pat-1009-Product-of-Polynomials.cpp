#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
int main(){
  map<int, double> poly_1;
  map<int, double> poly_2;
  map<int, double> res;
  int n,m;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    int base;
    double coefficient;
    scanf("%d %lf",&base, &coefficient);
    poly_1[base] = coefficient;
  }
  scanf("%d",&m);
  for(int i = 0; i < m; ++i){
    int base;
    double coefficient;
    scanf("%d %lf",&base, &coefficient);
    poly_2[base] = coefficient;
  }
  for(auto item_1 : poly_1){
    for(auto item_2 : poly_2){
      res[item_1.first+item_2.first] += item_1.second*item_2.second;
      if(fabs(res[item_1.first+item_2.first]-0) < 1e-6) res.erase(item_2.first+item_1.first);
    }
  }
  printf("%lu ",res.size());
  auto itor = res.rbegin();
  while(itor != res.rend()){
    printf("%d %.1lf",(*itor).first, (*itor).second);
    printf(++itor==res.rend()?"\n":" ");
  }
  return 0;
}
