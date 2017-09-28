#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct Node{
  int val;
  int lchild;
  int rchild;
  Node():val(-1),lchild(-1),rchild(-1){}
}Node;
Node tree[101];
int arr[101];
void buildTree(int root,int &count){
  if(root == -1) return;
  buildTree(tree[root].lchild, count);
  tree[root].val = arr[count++];
  buildTree(tree[root].rchild, count);
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    scanf("%d %d",&tree[i].lchild, &tree[i].rchild);
  }
  int root = 0;
  for(int i = 0; i < n; ++i){
    scanf("%d",arr+i);
  }
  int count = 0;
  sort(arr,arr+n);
  buildTree(root, count);
  int queue[512];
  int rear = 0, head = 0;
  queue[rear++] = root;
  while(head != rear){
    int tmp = queue[head++];
    if(tree[tmp].lchild != -1) queue[rear++] = tree[tmp].lchild;
    if(tree[tmp].rchild != -1) queue[rear++] = tree[tmp].rchild;
    printf("%d",tree[tmp].val);
    printf(head==rear?"\n":" ");
  }
  return 0;
}
