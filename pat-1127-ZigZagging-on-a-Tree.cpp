#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef struct Node{
  int val;
  Node * lchild;
  Node * rchild;
  Node(){}
  Node(int x):val(x),lchild(NULL),rchild(NULL){}
}Node;
int inOrder[32], postOrder[32];
void create(Node *& root, int in_left, int in_right, int post_left, int post_right){
  if(in_right < in_left) return;
  int pos = in_left;
  for(; inOrder[pos] != postOrder[post_right]; ++pos);
  root = new Node(postOrder[post_right]);
  create(root->lchild, in_left, pos-1, post_left, post_left+pos-in_left-1);
  create(root->rchild, pos+1, in_right, post_left+pos-in_left, post_right-1);
}
void levelTraversal(Node * root){
  vector< vector<int> > levelOrder;
  Node queue[100];
  int front = 0, back = 0, last = 0;
  if(!root) return;
  queue[back++] = *root;
  vector<int> tmp;
  while(front != back){
    if(front == last){
      levelOrder.push_back(tmp);
      tmp.clear();
      last = back;
    }
    Node cur = queue[front++];
    if(cur.lchild) queue[back++] = *cur.lchild;
    if(cur.rchild) queue[back++] = *cur.rchild;
    tmp.push_back(cur.val);
  }
  levelOrder.push_back(tmp);
  bool sign = true;
  bool start = true;
  for(auto item : levelOrder){
    if(sign){
      for(auto itor = item.begin(); itor != item.end(); ++itor)
        printf(" %d",*itor);
      sign = false;
    }
    else{
      for(auto itor = item.rbegin(); itor != item.rend(); ++itor){
        if(start) start = false;
        else printf(" ");
        printf("%d",*itor);
      }
      sign = true;
    }
  }
  printf("\n");
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i)
    scanf("%d",inOrder+i);
  for(int i = 0; i < n; ++i)
    scanf("%d",postOrder+i);
  Node * tree = NULL;
  create(tree, 0, n-1, 0, n-1);
  levelTraversal(tree);
  return 0;
}
