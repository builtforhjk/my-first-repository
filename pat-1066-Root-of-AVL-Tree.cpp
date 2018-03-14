#include <iostream>
#include <cstdio>
using namespace std;
typedef struct BINode{
  int val;
  BINode * lchild;
  BINode * rchild;
  BINode(int x):val(x),lchild(NULL),rchild(NULL){}
}BINode;
BINode * LL_Rotate(BINode * root){
  BINode * tmp = root->lchild;
  root->lchild = tmp->rchild;
  tmp->rchild = root;
  return tmp;
}
BINode * RR_Rotate(BINode * root){
  BINode * tmp = root->rchild;
  root->rchild = tmp->lchild;
  tmp->lchild = root;
  return tmp;
}
BINode * LR_Rotate(BINode * root){
  root->lchild = RR_Rotate(root->lchild);
  return LL_Rotate(root);
}
BINode * RL_Rotate(BINode * root){
  root->rchild = LL_Rotate(root->rchild);
  return RR_Rotate(root);
}
int depth(BINode * root){
  if(!root) return 0;
  return max(depth(root->lchild), depth(root->rchild))+1;
}
void insert(BINode *& root, int data){
  if(!root) root = new BINode(data);
  else {
    if(data < root->val){
      insert(root->lchild, data);
      if(depth(root->lchild) - depth(root->rchild) > 1){
        if(depth(root->lchild->lchild) > depth(root->lchild->rchild)) root = LL_Rotate(root);
        else root = LR_Rotate(root);
      }
    }
    else if(data > root->val){
      insert(root->rchild, data);
      if(depth(root->rchild) - depth(root->lchild) > 1){
        if(depth(root->rchild->rchild) > depth(root->rchild->lchild)) root = RR_Rotate(root);
        else root = RL_Rotate(root);
      }
    }
    else return;
  }
}
int main(){
  int n;
  scanf("%d",&n);
  BINode * tree = NULL;
  for(int i = 0; i < n; ++i){
    int data;
    scanf("%d",&data);
    insert(tree, data);
  }
  printf("%d\n",tree->val);
  return 0;
}
