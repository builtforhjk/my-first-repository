#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
typedef struct Node{
  int data;
  int lchild;
  int rchild;
}Node;
Node tree[21];
int levelTraversal(int root){
  int queue[100];
  int rear = 0, head = 0;
  queue[rear++] = root;
  int sign = 0;
  int tmp;
  while(rear != head){
    tmp = queue[head++];
    if(tree[tmp].lchild == -1 && !sign) sign = 1;
    else if(tree[tmp].lchild != -1 && sign) return -1;
    else if(tree[tmp].lchild != -1) queue[rear++] = tree[tmp].lchild;
    if(tree[tmp].rchild == -1 && !sign) sign = 1;
    else if(tree[tmp].rchild != -1 && sign) return -1;
    else if(tree[tmp].rchild != -1) queue[rear++] = tree[tmp].rchild;
  }
  return tmp;
}
int main(){
  int n;
  scanf("%d",&n);
  int root = 0;
  int visited[21] = {0};
  for(int i = 0; i < n; ++i){
    char l[3],r[3];
    scanf("%s",l);
    scanf("%s",r);
    if(strcmp(l,"-") == 0) tree[i].lchild = -1;
    else {
      tree[i].lchild = atoi(l);
      visited[tree[i].lchild] = 1;
    }
    if(strcmp(r,"-") == 0) tree[i].rchild = -1;
    else {
      tree[i].rchild = atoi(r);
      visited[tree[i].rchild] = 1;
    }
  }
  while(visited[root]) ++root;
  int res = levelTraversal(root);
  if(res >= 0) printf("YES %d\n",res);
  else printf("NO %d\n",root);
  return 0;
}
