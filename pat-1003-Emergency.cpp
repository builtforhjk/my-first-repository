#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;
#define INFTY 999999
struct City{
    map <int, int> connection;
    vector <int> path;
    int pathNumber;
    int weigh;
    City(int x):weigh(x){
        pathNumber = 0;
    }
};
int * dist;
int * rescue;
vector <int> exist;
bool isExist(int k){
    for(auto & item : exist){
        if(item == k)
            return true;
    }
    return false;
}
vector <City> graph;
void shortestPath(int startCity, int endCity, int citiesNumber){
    if(endCity == startCity){
        return;
    }
    for(auto & item : graph[startCity].connection){
        if(isExist(item.first)) continue;
        int distance = dist[startCity]+item.second;
        if(distance < dist[item.first]){
            dist[item.first] = distance;
            rescue[item.first] = graph[item.first].weigh+rescue[startCity];
            graph[item.first].pathNumber = graph[startCity].pathNumber;
            graph[item.first].path.clear();
            graph[item.first].path = graph[startCity].path;
            graph[item.first].path.push_back(item.first);
        }
        else if(distance == dist[item.first]){
            graph[item.first].pathNumber += graph[startCity].pathNumber;
            if(rescue[startCity]+graph[item.first].weigh > rescue[item.first]){
                rescue[item.first] = graph[item.first].weigh+rescue[startCity];
                graph[item.first].path.clear();
                graph[item.first].path = graph[startCity].path;
                graph[item.first].path.push_back(item.first);
            }
        }
    }
    int minLen = INFTY;
    int selectCity = -1;
    for(int i = 0; i < citiesNumber; ++i){
        if(isExist(i) || dist[i] == INFTY) continue;
        if(dist[i] < minLen){
            minLen = dist[i];
            selectCity = i;
        }
    }
    exist.push_back(selectCity);
    shortestPath(selectCity, endCity, citiesNumber);
}
int main(){
    int citiesNumber, roadsNumber, startCity, endCity;
    cin>>citiesNumber>>roadsNumber>>startCity>>endCity;
    dist = new int[citiesNumber];
    rescue = new int[citiesNumber];
    memset(rescue,0,sizeof(int)*citiesNumber);
    for(int i = 0; i < citiesNumber; ++i){
        dist[i] = INFTY;
    }
    dist[startCity] = 0;
    for(int i = 0; i < citiesNumber; ++i){
        int rescue;
        cin>>rescue;
        graph.push_back(City(rescue));
    }
    rescue[startCity] = graph[startCity].weigh;
    for(int i = 0; i < roadsNumber; ++i){
        int a,b,l;
        cin>>a>>b>>l;
        graph[a].connection[b] = l;
        graph[b].connection[a] = l;
    }
    graph[startCity].pathNumber = 1;
    graph[startCity].path.push_back(startCity);
    exist.push_back(startCity);
    shortestPath(startCity, endCity, citiesNumber);
    cout<<graph[endCity].pathNumber<<" "<<rescue[endCity]<<endl;
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
typedef struct Edge{
  int rear;
  int weigh;
  Edge(){}
  Edge(int x, int y):rear(x),weigh(y){}
}Edge;
typedef struct Node{
  int val;
  bool visited;
  int dist;
  int count;
  int total;
  Node(){
    this->val = 0;
    this->visited = false;
    this->dist = 999999;
    this->count = 0;
    this->total = 0;
  }
}Node;
map<int, vector<Edge> >graph;
Node * vetex;
void dijkstra(int n_start, int n_end, int n){
  if(n_start == n_end) return;
  for(auto &v : graph[n_start]){
    if(!(vetex[v.rear].visited)){
      int val_tmp = vetex[n_start].dist + v.weigh;
      if(val_tmp < vetex[v.rear].dist){
        vetex[v.rear].dist = val_tmp;
        vetex[v.rear].total = vetex[n_start].total + vetex[v.rear].val;
        vetex[v.rear].count = vetex[n_start].count;
      }
      else if(val_tmp == vetex[v.rear].dist){
        vetex[v.rear].count += vetex[n_start].count;
        int amount = vetex[n_start].total + vetex[v.rear].val;
        if(amount > vetex[v.rear].total) vetex[v.rear].total = amount;  
      }
    }
  }
  int pivot = 999999;
  int next = -1;
  for(int i = 0; i < n; ++i){
    if(!(vetex[i].visited)){
      if(vetex[i].dist < pivot){
        pivot = vetex[i].dist;
        next = i;
      }
    }
  }
  vetex[next].visited = true;
  dijkstra(next, n_end, n);
}
int main(){
  int n,m,n_start,n_end;
  scanf("%d%d%d%d",&n,&m,&n_start,&n_end);
  vetex = new Node[n+1];
  for(int i = 0; i < n; ++i){
    scanf("%d",&(vetex[i].val));
  }
  for(int i = 0; i < m; ++i){
    int h, t, weigh;
    scanf("%d%d%d",&h,&t,&weigh);
    Edge tmp;
    tmp.weigh = weigh;
    tmp.rear = t;
    graph[h].push_back(Edge(t,weigh));
    graph[t].push_back(Edge(h,weigh));
  }
  vetex[n_start].visited = true;
  vetex[n_start].dist = 0;
  vetex[n_start].count = 1;
  vetex[n_start].total = vetex[n_start].val;
  dijkstra(n_start, n_end, n);
  printf("%d %d\n",vetex[n_end].count, vetex[n_end].total);
  return 0;
}
*/
