/*
********************************************************
**问题描述:                                            **
**给定一个图,求两点的最短路径,路径不唯一时,根据顶点权值排序。 **
********************************************************
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef string elemType;
typedef struct Edge{
	int weigh;
	elemType rear;
	Edge(){}
	Edge(int x, elemType y):weigh(x),rear(y){}
}Edge;
typedef struct Info{
	int weigh;
	bool visited;
	elemType pre;
	int dist;
	int total;
	int count;
	int path;
	Info(){}
	Info(int x, bool y, elemType z, int k):weigh(x),visited(y),pre(z),dist(k){
		total = 0;
		count = 0;
		path = 0;
	}
}Info;
map<elemType, vector<Edge> > graph;
map<elemType, Info> vetex;
int n,m;
elemType start_c, end_c;
void dijkstra(elemType head){
	if(head == end_c) return;
	for(auto item : graph[head]){
		if(!vetex[item.rear].visited){
			int d = vetex[head].dist + item.weigh;
			if(d < vetex[item.rear].dist){
				vetex[item.rear].dist = d;
				vetex[item.rear].pre = head;
				vetex[item.rear].total = vetex[head].total + vetex[item.rear].weigh;
				vetex[item.rear].count = vetex[head].count+1;
				vetex[item.rear].path = vetex[head].path;
			}
			else if(d == vetex[item.rear].dist){
				vetex[item.rear].path += vetex[head].path;
				int h = vetex[head].total + vetex[item.rear].weigh;
				if(h > vetex[item.rear].total){
					vetex[item.rear].pre = head;
					vetex[item.rear].total = h;
					vetex[item.rear].count = vetex[head].count+1; 
				}
				else if(h == vetex[item.rear].total){
					if(vetex[item.rear].count > (vetex[head].count+1)){
						vetex[item.rear].pre = head;
						vetex[item.rear].count = vetex[head].count+1;
					}
				}
			}
		}
	}
	elemType next = head;
	int st = 999999;
	for(auto vex : vetex){
		if(!vex.second.visited){
			if(st > vex.second.dist){
				next = vex.first;
				st = vex.second.dist;
			}
		}
	}
	vetex[next].visited = true;
	dijkstra(next);
}
int main(){
	cin>>n>>m>>start_c>>end_c;
	vetex[start_c] = Info(0, true, "-1", 0);
	vetex[start_c].path = 1;
	for(int i = 0; i < n-1; ++i){
		elemType e;
		int t;
		cin>>e>>t;
		vetex[e] = Info(t, false, "-1", 999999);
	}
	for(int i = 0; i < m; ++i){
		elemType s,t;
		int w;
		cin>>s>>t>>w;
		graph[s].push_back(Edge(w,t));
		graph[t].push_back(Edge(w,s));
	}
	dijkstra(start_c);
	cout<<vetex[end_c].path<<" "<<vetex[end_c].dist<<" "<<vetex[end_c].total<<" "
	<<vetex[end_c].total/vetex[end_c].count<<endl;
	vector<elemType> p;
	elemType cur = end_c;
	while(cur != "-1"){
		p.push_back(cur);
		cur = vetex[cur].pre;
	}
	for(auto it = p.rbegin(); it != p.rend(); ++it){
		cout<<*it;
		if((*it) != end_c){
			cout<<"->";
		}
		else cout<<endl;
	}
	return 0;
}