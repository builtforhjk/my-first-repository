#include <iostream>
#include <cstdio>
using namespace std;
typedef struct Node{
  int lchild;
  int rchild;
  int val;
  Node(){}
  Node(int x, int l, int r):lchild(l),rchild(r),val(x){}
}Node;
Node tree[10];
int res[10];
int inRes[10];
void levelTraversal(int root){
  int queue[100];
  int rear = 0, head = 0;
  int count = 0;
  queue[rear++] = root;
  while(rear != head){
    int tmp = queue[head++];
    if(tree[tmp].rchild != -1) queue[rear++] = tree[tmp].rchild;
    if(tree[tmp].lchild != -1) queue[rear++] = tree[tmp].lchild;
    res[count++] = tmp;
  }
}
void inOrder(int root, int &count){
  if(root == -1) return;
  inOrder(tree[root].rchild,count);
  inRes[count++] = root;
  inOrder(tree[root].lchild,count);
}
int main(){
  int n;
  scanf("%d",&n);
  getchar();
  int visited[10] = {0};
  for(int i = 0; i < n; ++i){
    char l,r;
    scanf("%c %c",&l,&r);
    getchar();
    if(l == '-') tree[i].lchild = -1;
    else {
      tree[i].lchild = l-'0';
      visited[l-'0'] = 1;
    }
    if(r == '-') tree[i].rchild = -1;
    else {
      tree[i].rchild = r-'0';
      visited[r-'0'] = 1;
    }
    tree[i].val = i;
  }
  int root = 0;
  while(visited[root] == 1) ++root;
  levelTraversal(root);
  for(int i = 0; i < n; ++i){
    printf("%d",res[i]);
    if(i+1 == n) printf("\n");
    else printf(" ");
  }
  int x = 0;
  inOrder(root,x);
  for(int i = 0; i < n; ++i){
    printf("%d",inRes[i]);
    if(i+1 == n) printf("\n");
    else printf(" ");
  }
  return 0;
}
