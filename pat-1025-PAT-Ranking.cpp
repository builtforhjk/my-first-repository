#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
struct Testee{
	int location;
	string id;
	int score;
	int rank;
	int localRank;
	Testee(int lo, string i, int x): location(lo), id(i),score(x){
		rank = 0;
		localRank = 0;
	}
};
vector <Testee> testees;
bool compare(Testee t1, Testee t2){
	if(t1.score == t2.score){
		return strcmp(t1.id.c_str(), t2.id.c_str()) < 0;
	}
	else{
		return t1.score > t2.score;
	}
}
int main(){
	int rankSet;
	cin>>rankSet;
	int sum = 0;
	map <int,int>topScore;
	for(int i = 0; i < rankSet; ++i){
		int number;
		cin>>number;
		sum += number;
		for(int j = 0; j < number; ++j){
			string id;
			int score;
			cin>>id>>score;
			testees.push_back(Testee(i+1,id,score));
		}
	}
	sort(testees.begin(), testees.end(), compare);
	int * localRank = new int[rankSet];
	int * localRankDleta = new int[rankSet];
	memset(localRank, 0, rankSet * sizeof(int));
	memset(localRankDleta, 0, rankSet * sizeof(int));
	cout<<sum<<endl;
	for(int i = 0; i < sum; ++i){
		if(!i){
			testees[i].rank = 1;
			testees[i].localRank = 0;
			topScore[testees[i].location] = testees[i].score;
		}
		else{
			if(testees[i].score == testees[i-1].score){
				testees[i].rank = testees[i-1].rank;
			}
			else{
				testees[i].rank = i+1;
			}
			if(topScore.find(testees[i].location) == topScore.end()){
				testees[i].localRank = 0;
				topScore[testees[i].location] = testees[i].score;
			}
			else if(testees[i].score == topScore[testees[i].location]){
				testees[i].localRank = localRank[testees[i].location-1];
				++localRankDleta[testees[i].location-1];
			}
			else{
				topScore[testees[i].location] = testees[i].score;
				localRank[testees[i].location-1] += localRankDleta[testees[i].location-1]+1;
				localRankDleta[testees[i].location-1] = 0;
				testees[i].localRank = localRank[testees[i].location-1];
			}
		}
		cout<<testees[i].id<<" "<<testees[i].rank<<" "<<testees[i].location<<" "<<testees[i].localRank+1<<endl;
	}
}