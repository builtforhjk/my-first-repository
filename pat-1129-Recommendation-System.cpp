#include <iostream>
#include <cstdio>
#include <list>
using namespace std;
int stat[50001] = {0};
int main(){
  int n,K;
  scanf("%d%d",&n,&K);
  list<int> rec;
  for(int i = 0; i < n; ++i){
    int val;
    scanf("%d",&val);
    if(i == 0){
      ++stat[val];
      rec.insert(rec.begin(), val);
      continue;
    }
    printf("%d:",val);
    int count = 0;
    for(auto iter = rec.begin(); iter != rec.end() && count < K; ++iter,++count)
      printf(" %d",*iter);
    printf("\n");
    ++stat[val];
    rec.remove(val);
    if(rec.empty()) rec.insert(rec.begin(),val);
    else{
      int total = 0;
      int sign = 0;
      for(auto iter = rec.begin(); iter != rec.end(); ++iter){
        if(stat[val] > stat[*iter]){
          rec.insert(iter, val);
          sign = 1;
          break;
        }
        else if(stat[val] == stat[*iter]){
          if(val < (*iter)){
            rec.insert(iter, val);
            sign = 1;
            break;
          }
        }
        ++total;
      }
      if(!sign && total < K) rec.push_back(val);
      else if(sign && rec.size() > K) rec.pop_back();
    }
  }
  return 0;
}
