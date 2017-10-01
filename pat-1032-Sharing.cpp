#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
typedef struct Node{
    int addr;
    char val;
    int next;
    Node(){}
    Node(int a,char x, int y):addr(a),val(x),next(y){}
}Node;
unordered_map<int, Node> linklist;
int root1, root2;
int n;
int main(){
  scanf("%d %d %d",&root1, &root2, &n);
  for(int i = 0; i < n; ++i){
    int addr, next;
    char x;
    scanf("%d %c %d", &addr, &x, &next);
    linklist[addr] = Node(addr,x,next);
  }
  int len1 = 0, len2 = 0;
  int cur1 = root1, cur2 = root2;
  while(1){
    if(cur1 == -1 && cur2 == -1) break;
    if(cur1 != -1){
      ++len1;
      cur1 = linklist[cur1].next;
    }
    if(cur2 != -1){
      ++len2;
      cur2 = linklist[cur2].next;
    }
  }
  cur1 = root1, cur2 = root2;
  if(len1 > len2){
    for(int i = 0; i < (len1-len2); ++i)
      cur1 = linklist[cur1].next;
  }
  else{
    for(int i = 0; i < (len2-len1); ++i)
      cur2 = linklist[cur2].next;
  }
  bool flag = true;
  int suffix;
  while(1){
    if(cur1 == -1 && cur2 == -1){
      flag = false;
      break;
    }
    else if(linklist[cur1].addr == linklist[cur2].addr){
      suffix = linklist[cur1].addr;
      break;
    }
    else{
      cur1 = linklist[cur1].next;
      cur2 = linklist[cur2].next;
    }
  }
  if(flag == false) printf("-1\n");
  else printf("%05d\n",suffix);
  return 0;
}
