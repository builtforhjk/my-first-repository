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
