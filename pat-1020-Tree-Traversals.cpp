#include <iostream>
#include <cstdio>
using namespace std;
typedef struct Node{
  int data;
  Node * lchild;
  Node * rchild;
  Node():lchild(NULL),rchild(NULL){}
  Node(int x):data(x),lchild(NULL),rchild(NULL){}
}Node;
int n;
void reBuilt(Node ** root, int *inOrder, int *postOrder,int length){
  if(length == 0) return;
  (*root) = new Node;
  int i;
  for(i = 0; inOrder[i] != postOrder[length-1]; ++i);
  (*root)->data = inOrder[i];
    reBuilt(&((*root)->lchild), inOrder, postOrder,i);
    reBuilt(&((*root)->rchild), inOrder+i+1, postOrder+i,length-1-i);
}
void levelTraversal(Node * root){
  Node queue[100];
  int head = 0, rear = 0;
  queue[rear++] = *root;
  while(rear != head){
    Node tmp = queue[head++];
    if(tmp.lchild) queue[rear++] = *(tmp.lchild);
    if(tmp.rchild) queue[rear++] = *(tmp.rchild);
    printf("%d",tmp.data);
    printf(rear == head?"\n":" ");
  }
}
int main(){
  scanf("%d",&n);
  int *inOrder = new int[n];
  int *postOrder = new int[n];
  for(int i = 0; i < n; ++i){
    scanf("%d",postOrder+i);
  }
  for(int i = 0; i < n; ++i){
    scanf("%d",inOrder+i);
  }
  Node * root = NULL;
  reBuilt(&root, inOrder, postOrder, n);
  levelTraversal(root);
  return 0;
}