#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef struct Node{
  int estate;
  double area;
  Node(){}
  Node(int y, double z):estate(y),area(z){}
}Node;
typedef struct Family{
  int min_id;
  int num;
  int total_estate;
  double total_area;
  double avg_area;
  Family():min_id(10000),num(0),total_estate(0),total_area(0.0),avg_area(0.0){}
}Family;
bool cmp(Family f1, Family f2){
  if(f1.avg_area == f2.avg_area) return f1.min_id < f2.min_id;
  else return f1.avg_area > f2.avg_area;
}
map<int, int> pre;
map<int, Node> stat;
int cnt;
int find(int x){
  return (pre[x] == x?x:pre[x]=find(pre[x]));
}
void merge(int x, int y){
  int r_x = find(x), r_y = find(y);
  if(r_x != r_y) {
    pre[r_y] = r_x;
    --cnt;
  }
}
int main(){
  int n;
  scanf("%d",&n);
  cnt = 0;
  for(int i = 0; i < n; ++i){
    int id, fa, ma,k;
    scanf("%d%d%d%d",&id,&fa,&ma,&k);
    if(pre.find(id) == pre.end()) pre[id] = id;
    if(fa != -1){
      if(pre.find(fa) == pre.end()) pre[fa] = fa;
      merge(id, fa);
    }
    if(ma != -1){
      if(pre.find(ma) == pre.end()) pre[ma] = ma;
      merge(id,ma);
    }
    for(int j = 0; j < k; ++j){
      int child;
      scanf("%d",&child);
      if(pre.find(child) == pre.end()) pre[child] = child;
      merge(id,child);
    }
    int estate;
    double area;
    scanf("%d%lf",&estate, &area);
    stat[id] = Node(estate, area);
  }
  cnt = (int)pre.size() + cnt;
  printf("%d\n",cnt);
  set<int>root;
  for(auto item : pre)
    root.insert(find(item.first));
  map<int, Family> res;
  for(auto item : root)
    res[item] = Family();
  for(auto item : pre){
    int tmp = find(item.first);
    ++res[tmp].num;
    if(item.first < res[tmp].min_id) res[tmp].min_id = item.first;
  }
  for(auto item : stat){
    int tmp = find(item.first);
    res[tmp].total_estate += item.second.estate;
    res[tmp].total_area += item.second.area;
  }
  vector<Family> output;
  for(auto &item : res){
    item.second.avg_area = item.second.total_area / item.second.num;
    output.push_back(item.second);
  }
  sort(output.begin(), output.end(), cmp);
  for(auto v : output){
    printf("%04d %d %.3lf %.3lf\n", v.min_id, v.num, (double)v.total_estate/(double)v.num,v.avg_area);
  }
  return 0;
}
