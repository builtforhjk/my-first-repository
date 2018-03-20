#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
void lowercase(string & str){
  int diff = 'a' - 'A';
  for(auto & ch : str){
    if(ch < 'a') ch = ch + diff;
  }
}
typedef struct Node{
  string codes;
  double weight;
  int total;
}Node;
bool cmp(Node n1, Node n2){
  if((int)n1.weight == (int)n2.weight){
    if(n1.total == n2.total) return strcmp(n1.codes.c_str(), n2.codes.c_str()) < 0;
    else return n1.total < n2.total;
  }
  else return (int)n1.weight > (int)n2.weight;
}
map<string, Node> stat;
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    string test, school;
    int grade;
    cin>>test>>grade>>school;
    lowercase(school);
    ++stat[school].total;
    stat[school].codes = school;
    if(test[0] == 'A') stat[school].weight += grade;
    else if(test[0] == 'T') stat[school].weight += (double)grade * 1.5;
    else stat[school].weight += (double)grade / 1.5;
  }
  printf("%d\n",(int)stat.size());
  vector<Node> res;
  for(auto item : stat){
    res.push_back(item.second);
  }
  sort(res.begin(), res.end(), cmp);
  int rank = 1;
  int tmp = 0;
  int seq = 1;
  for(auto item : res){
    if((int)item.weight != tmp) {
      rank = seq;
      tmp = (int)item.weight;
    }
    printf("%d %s %d %d\n",rank, item.codes.c_str(), (int)item.weight, item.total);
    ++seq;
  }
  return 0;
}
