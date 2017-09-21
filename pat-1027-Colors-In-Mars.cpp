#include <iostream>
#include <string>
#include <vector>
using namespace std;
string convertToRGBFommat(int color){
	int decimal = color / 13;
	int digit = color % 13;
	string temp;
	switch(decimal){
		case 10:
			temp.append("A");
			break;
		case 11:
			temp.append("B");
			break;
		case 12:
			temp.append("C");
			break;
		default:
			char a = decimal + 48;
			temp.push_back(a);
			break;
	}
	switch(digit){
		case 10:
			temp.append("A");
			break;
		case 11:
			temp.append("B");
			break;
		case 12:
			temp.append("C");
			break;
		default:
			char a = digit + 48;
			temp.push_back(a);
			break;
	}
	return temp;
}
int main(){
	int red = 0;
	int green = 0;
	int blue = 0;
	cin>>red>>green>>blue;
	vector <string> RGB;
	RGB.push_back(convertToRGBFommat(red));
	RGB.push_back(convertToRGBFommat(green));
	RGB.push_back(convertToRGBFommat(blue));
	cout<<"#"<<RGB[0]<<RGB[1]<<RGB[2]<<endl;
	return 0;
}