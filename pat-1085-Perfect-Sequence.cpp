#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
  int n,p;
  scanf("%d%d",&n,&p);
  int *seq = new int[n+1];
  for(int i = 0; i < n; ++i){
    scanf("%d",seq+i);
  }
  sort(seq,seq+n);
  int max = 1;
  for(int i = 0; i < n; ++i){
    int gap = max;
    for(int j = i+gap; j < n; ++j){
      if((double)seq[j]/(double)seq[i] <= (double)p) ++gap;
      else break;
    }
    if(gap > max) max = gap;
  }
  printf("%d\n",max);
  return 0;
}
