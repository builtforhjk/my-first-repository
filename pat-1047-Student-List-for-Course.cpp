#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int name2num(const char * name){
  return (name[0]-'A')*26*26*26+(name[1]-'A')*26*26+(name[2]-'A')*26+(name[3]-'0');
}
char * num2name(const int num){
  char *res = new char[5];
  res[0] = num/(26*26*26)+'A';
  res[1] = num%(26*26*26)/(26*26)+'A';
  res[2] = num%(26*26*26)%(26*26)/26+'A';
  res[3] = num%(26*26*26)%(26*26)%26+'0';
  res[4] = '\0';
  return res;
}
int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  map<int, vector<int> >stat;
  for(int i = 0; i < n; ++i){
    char tmp[5];
    int k;
    scanf("%s %d",tmp,&k);
    for(int j = 0; j < k; ++j){
      int id;
      scanf("%d",&id);
      stat[id].push_back(name2num(tmp));
    }
  }
  for(int i = 1; i <= m; ++i){
    if(stat.find(i) == stat.end()){
      printf("%d 0\n",i);
      continue;
    }
    printf("%d %lu\n", i, stat[i].size());
    auto itor = stat[i].begin();
    auto fin = stat[i].end();
    sort(itor, fin);
    while(itor != fin){
      char *res = num2name(*itor);
      printf("%s\n",res);
      ++itor;
    }
  }
  return 0;
}
