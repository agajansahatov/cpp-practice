#include <iostream>
using namespace std;

ostream &operator <<(ostream &output, int a){
	output<<a<<endl<<endl;
	return output;
}
int main(){
	cout<<"Hello Irrapulukuchu!"<<45;
	return 0;
}
