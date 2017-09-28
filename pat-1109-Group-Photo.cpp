#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
typedef struct Node{
  char name[10];
  int height;
}Node;
Node people[10001];
bool cmp(Node p1, Node p2){
  if(p1.height == p2.height) return strcmp(p1.name, p2.name) < 0;
  else return p1.height > p2.height;
}
int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  for(int i = 0; i < n; ++i){
    scanf("%s",people[i].name);
    scanf("%d",&people[i].height);
  }
  sort(people,people+n,cmp);
  int rows = n/k;
  int firstRows = n-rows*(k-1);
  string *formation = new string[firstRows];
  int count = 0;
  int len;
  int num = 0;
  while(count < k){
    if(count == 0) len = firstRows;
    else len = rows;
    int curCount = 1;
    int pos = 1;
    formation[len/2] = people[num++].name;
    while(curCount < len){
      formation[len/2 - pos] = people[num++].name;
      if(++curCount < len) formation[len/2 + pos] = people[num++].name;
      ++pos;
      ++curCount;
    }
    for(int i = 0; i < len; ++i){
      printf("%s",formation[i].c_str());
      printf(i == (len-1)?"\n":" ");
    }
    ++count;
  }
  return 0;
}
