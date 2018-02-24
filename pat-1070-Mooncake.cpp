#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct Node{
  double amount;
  double price;
  double unit;
}Node;
bool cmp(Node n1, Node n2){
  return n1.unit > n2.unit;
}
int main(){
  Node mooncake[1002]; 
  int n,demand;
  scanf("%d%d",&n,&demand);
  for(int i = 0; i < n; ++i) 
    scanf("%lf",&(mooncake[i].amount));
  for(int i = 0; i < n; ++i)
    scanf("%lf",&(mooncake[i].price));
  for(int i = 0; i < n; ++i)
    mooncake[i].unit = mooncake[i].price/mooncake[i].amount;
  sort(mooncake,mooncake+n,cmp);
  double diff = demand, sum = 0;
  int cur = 0;
  while(cur < n){
    if(diff < mooncake[cur].amount){
      sum += diff * mooncake[cur].unit;
      break;
    }
    else {
      sum += mooncake[cur].price;
      diff = diff - mooncake[cur].amount;
      ++cur;
    }
  }
  printf("%.2lf\n",sum);
  return 0;
}
