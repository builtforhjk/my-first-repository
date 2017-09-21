#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int * dist = new int[10];
int * pay = new int[10];
int cityNumber = 0;
struct HighWay{
	int startCity;
	int endCity;
	int cost;
	int distance;
};
struct Path{
	vector <int>sPath;
};
Path * paths = new Path[10];
vector <HighWay>highways;
vector <int>exist;
bool isExisted(int city){
	for(int i = 0; i < exist.size(); ++i){
		if(exist[i] == city){
			return true;
		}
	}
	return false;
}
void shortestPath(int startCity, int endCity){
	for(int i = 0; i < highways.size(); ++i){
		if(highways[i].startCity == startCity){
			int pDist = dist[startCity]+highways[i].distance;
			int pPay = pay[startCity]+highways[i].cost;
			if(pDist < dist[highways[i].endCity]){
				dist[highways[i].endCity] = pDist;
				pay[highways[i].endCity] = pPay;
				paths[highways[i].endCity].sPath.clear();
				paths[highways[i].endCity].sPath.insert(paths[highways[i].endCity].sPath.end(),
					paths[startCity].sPath.begin(),paths[startCity].sPath.end());
				paths[highways[i].endCity].sPath.push_back(highways[i].endCity);
			}
			else if(pDist == dist[highways[i].endCity]){
				if(pPay < pay[highways[i].endCity]){
					pay[highways[i].endCity] = pPay;
					dist[highways[i].endCity] = pDist;
					paths[highways[i].endCity].sPath.clear();
					paths[highways[i].endCity].sPath.insert(paths[highways[i].endCity].sPath.end(),
						paths[startCity].sPath.begin(),paths[startCity].sPath.end());
					paths[highways[i].endCity].sPath.push_back(highways[i].endCity);
				}
			}
		}
		else if(highways[i].endCity == startCity){
			int pDist = dist[startCity]+highways[i].distance;
			int pPay = pay[startCity]+highways[i].cost;
			if(pDist < dist[highways[i].startCity]){
				dist[highways[i].startCity] = pDist;
				pay[highways[i].startCity] = pPay;
				paths[highways[i].startCity].sPath.clear();
				paths[highways[i].startCity].sPath.insert(paths[highways[i].startCity].sPath.end(),
					paths[startCity].sPath.begin(),paths[startCity].sPath.end());
				paths[highways[i].startCity].sPath.push_back(highways[i].startCity);
			}
			else if(pDist == dist[highways[i].startCity]){
				if(pPay < pay[highways[i].startCity]){
					pay[highways[i].startCity] = pPay;
					dist[highways[i].startCity] = pDist;
					paths[highways[i].startCity].sPath.clear();
					paths[highways[i].startCity].sPath.insert(paths[highways[i].startCity].sPath.end(),
						paths[startCity].sPath.begin(),paths[startCity].sPath.end());
					paths[highways[i].startCity].sPath.push_back(highways[i].startCity);
				}
			}
		}
	}
	int min = 999999;
	int city = 0;
	for(int i = 0; i < cityNumber; ++i){
		if(dist[i] < min && !isExisted(i)){
			min = dist[i];
			city = i;
		}
	}
	exist.push_back(city);
	if(city == endCity){
		return;
	}
	else{
		shortestPath(city, endCity);
	}
}
int main(){
	int pathNumber = 0;
	int startCity = 0;
	int endCity = 0;
	cin>>cityNumber>>pathNumber>>startCity>>endCity;
	for(int i = 0; i < pathNumber; ++i){
		HighWay temp;
		cin>>temp.startCity>>temp.endCity>>temp.distance>>temp.cost;
		highways.push_back(temp);
	}
	delete []dist;
	delete []pay;
	delete []paths;
	dist = new int[cityNumber];
	pay = new int[cityNumber];
	paths = new Path[cityNumber];
	for(int i = 0; i < cityNumber; ++i){
		dist[i] = 999999;
		pay[i] = 999999;
	}
	paths[startCity].sPath.push_back(startCity);
	dist[startCity] = 0;
	pay[startCity] = 0;
	exist.push_back(startCity);
	shortestPath(startCity, endCity);
	for(int i = 0; i < paths[endCity].sPath.size(); ++i){
		cout<<paths[endCity].sPath[i]<<" ";
	}
	cout<<dist[endCity]<<" "<<pay[endCity]<<endl;
	return 0;
}