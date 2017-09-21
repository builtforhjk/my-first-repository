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
