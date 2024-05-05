#include <iostream>
#include "my_header.h"

int main(){
	
	cout<<"Type two numbers: \n";
	int a, b;
	cin>>a>>b;
	
	int result = pow(a, b);
	cout<<a<<"^"<<b<<"="<<result;
	
	return 0;
}

#include "functions.cpp"
