#include <iostream>

using namespace std;

int f(int n, int b){
	return n+b;
}
void f(int n){
	cout<<n<<endl;
}

int main(){
	f(2);
	f(0);
	cout<<f(2,3)<<endl;
	return 0;
}
