#include <iostream>
#include <unordered_map>
using namespace std;
typedef struct Node{
    int next;
    int data;
    Node(int x, int y):next(x),data(y) {}
    Node(){}
}Node;
typedef int address;
unordered_map<address, Node> l;
int root;
int n, k;
void reversed(int len,Node&last,int head){
    if(head == -1) return;
    if(len < k){
        last.next = head;
        return;
    }
    int count = 0;
    int cur = head;
    while(count < k){
        if(count == 0){
            last.next = cur;
            cur = l[cur].next;
        }
        else{
            if(last.data == -99999 && count == k-1) root = cur;
            int st = l[cur].next;
            l[cur].next = last.next;
            last.next = cur;
            cur = st;
        }
        ++count;
    }
    l[head].next = -1;
    reversed(len-k,l[head],cur);
}
int main(){
    scanf("%d %d %d",&root, &n, &k);
    for(int i = 0; i < n; ++i){
        int addr, next;
        int data;
        scanf("%d %d %d",&addr, &data, &next);
        l[addr] = Node(next, data);
    }
    int head = root;
    Node last(-1,-99999);
    int len = 0;
    int probe = root;
    while(probe != -1){
    	++len;
    	probe = l[probe].next;
    }
    reversed(len, last, head);
    int cur = root;
    while(1){
      	if(l[cur].next == -1) {
          printf("%05d %d %d\n",cur,l[cur].data,l[cur].next);
          break;
      	}
      	printf("%05d %d %05d\n",cur,l[cur].data,l[cur].next);
        cur = l[cur].next;
    }
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef struct Node{
  int val;
  int next;
  Node(){}
  Node(int x, int y):val(x),next(y){}
}Node;
map<int, Node>linkedlist;
int main(){
  int root, n,k;
  scanf("%d%d%d",&root,&n,&k);
  for(int i = 0; i < n; ++i){
    int addr, data, next;
    scanf("%d%d%d",&addr, &data, &next);
    linkedlist[addr] = Node(data, next);
  }
  int total = 0, cur = root;
  while(cur != -1){
    ++total;
    cur = linkedlist[cur].next;
  }
  int pos = 1;
  cur = root;
  int mark = root, head = cur, pre = cur;
  bool sign = false;
  while(pos+k-1 <= total){
  	cur = linkedlist[cur].next;
    for(int i = 1; i < k; ++i){
      int tmp = linkedlist[cur].next;
      linkedlist[cur].next = head;
      linkedlist[pre].next = tmp;
      head = cur;
      cur = tmp;
    }
    if(!sign){
    	root = head;
    	sign = true;
    }
    else {
      linkedlist[mark].next = head;
      mark = pre;
    }
    head = cur;
    pre = cur;
    pos += k;
  }
  cur = root;
  while(1){
    printf("%05d %d ", cur, linkedlist[cur].val);
    cur = linkedlist[cur].next;
    if(cur == -1){
      printf("-1\n");
      break;
    }
    else printf("%05d\n",cur);
  }
  return 0;
}
*/
