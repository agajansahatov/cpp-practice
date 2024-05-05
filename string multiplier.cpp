#include<iostream>
#include<string>

using namespace std;

class User{
	string cs;
};
User User::operator* (char *s, int n){
	string str = "";
	for(int i=1; i<=n; i++){
		str += s;
	}
	this->cs = str;
	return *this;
}


int main(){
	string s = "*";
	cout<<"*"*5<<endl;
	
	return 0;
}
