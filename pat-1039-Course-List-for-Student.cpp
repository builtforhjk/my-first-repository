#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int hash_map(const char * name){
  return (name[0]-'A')*26*26*26+(name[1]-'A')*26*26+(name[2]-'A')*26+(name[3]-'0');
}
int main(){
  map<int, vector<int> >stat;
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0; i < m; ++i){
    int id, k;
    scanf("%d %d",&id, &k);
    for(int j = 0; j < k; ++j){
      char tmp[5];
      scanf("%s",tmp);
      stat[hash_map(tmp)].push_back(id);
    }
  }
  for(int i = 0; i < n; ++i){
    char tmp[5];
    scanf("%s",tmp);
    int hash_address = hash_map(tmp);
    printf("%s %lu", tmp, stat[hash_address].size());
    auto itor = stat[hash_address].begin();
    auto fin = stat[hash_address].end();
    sort(itor,fin);
    while(1){
      if(itor == fin){
        printf("\n");
        break;
      }
      else printf(" ");
      printf("%d",*itor);
      ++itor;
    }
  }
  return 0;
}
