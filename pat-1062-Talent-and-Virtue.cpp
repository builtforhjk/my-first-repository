#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct Node{
    int id;
    int v_g;
    int t_g;
    int type;
    Node(){}
    Node(int a, int x, int y):id(a),v_g(x),t_g(y){}
}Node;
Node * p;
bool cmp(Node n1, Node n2){
    if(n2.type == n1.type){
        if(n2.v_g+n2.t_g == n1.v_g+n1.t_g){
            if(n2.v_g == n1.v_g) return n1.id < n2.id;
            else return n1.v_g > n2.v_g;
        }
        else return n1.v_g+n1.t_g > n2.v_g+n2.t_g;
    }
    else return n1.type < n2.type;
}
int main(){
    int n,L,H;
    scanf("%d %d %d",&n,&L,&H);
    p = new Node[n];
    int count = 0;
    for(int i = 0; i < n; ++i){
        
        int id,x,y;
        scanf("%d %d %d",&id,&x,&y);
        if(x>=L && y>=L){
            p[count] = Node(id,x,y);
            if(x>=H && y>=H) p[count].type = 1;
            else if(x>=H) p[count].type = 2;
            else if(x>=y) p[count].type = 3;
            else p[count].type = 4;
            ++count;
        }
    }
    sort(p,p+count,cmp);
    printf("%d\n",count);
    for(int i = 0; i < count; ++i){
      	printf("%08d %d %d\n",p[i].id, p[i].v_g, p[i].t_g);
    }
    return 0;
}
