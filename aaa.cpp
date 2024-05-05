#include <iostream>

using namespace std;


int& returnReference(int& b){
	return b;
}
int& spam(){
	int x;
	cout<<x<<endl;
	return x;
}
int main(){
	int a = 5;
	int b = 3;
	int c = returnReference(a);
	returnReference(b) = a;
	cout<<a<<" "<<b<<endl;
	spam();
	spam() = 9;
	spam();
	return 0;
}
