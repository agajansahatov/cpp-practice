#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main(){
	ifstream MyFile ("Files/Hello.txt");
	
	string input;
	while( MyFile >> input){
		cout<< input << endl;
	}
	MyFile.close();
	return 0;
}
