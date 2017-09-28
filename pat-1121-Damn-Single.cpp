#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
map<int,int> couples;
map<int,int>party;
int main(){
  int n,m;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    int id_1, id_2;
    scanf("%d %d",&id_1,&id_2);
    couples[id_1] = id_2;
    couples[id_2] = id_1;
  }
  scanf("%d",&m);
  for(int i = 0; i < m; ++i){
    int id;
    scanf("%d",&id);
    party[id] = 1;
  }
  set<int>res;
  for(auto item : party){
    if(couples.find(item.first) == couples.end()) res.insert(item.first);
    else if(party[couples[item.first]] != 1) res.insert(item.first);
  }
  printf("%d\n",(int)res.size());
  int count = 0;
  for(auto iter = res.begin(); iter != res.end(); ++iter){
    printf("%05d",*iter);
    ++count;
    printf(count == res.size()?"\n":" ");
  }
  return 0;
}
