#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int val;
  struct Node * lchild;
  struct Node * rchild;
}Node;
void rebuild(Node ** root, int *pre, int *in, int length){
  if(!length) return;
  (*root) = (Node*)malloc(sizeof(Node));
  int i;
  for(i=0; in[i]!=pre[0]; ++i);
  (*root)->val = pre[0];
  rebuild(&((*root)->lchild), pre+1, in, i);
  rebuild(&((*root)->rchild), pre+1+i, in+1+i, length-i-1);
}
void postOrder(Node * root){
  static int sign = 0;
  if(!root) return;
  if(sign) return;
  postOrder(root->lchild);
  postOrder(root->rchild);
  if(!sign){
    sign = 1;
    printf("%d\n",root->val);
  }
}
int main(){
  int n;
  scanf("%d",&n);
  int i;
  int pre[50002], in[50002];
  for(i = 0; i < n; ++i)
    scanf("%d",pre+i);
  for(i = 0; i < n; ++i)
    scanf("%d",in+i);
  Node * root = 0;
  rebuild(&root, pre, in, n);
  postOrder(root);
  return 0;
}
