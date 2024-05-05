#include <iostream>
#include <string>

using namespace std;

class User{
	public:
		string firstname, lastname;
		User(string s){
			firstname = s;
		};
		User(string s1, string s2){
			firstname = s1;
			lastname = s2;
		};
		
};


int main(){
	
	User user = {"Godwin", "Irapuluchukwu"};
	cout<<user.firstname<<" "<<user.lastname<<endl;
	user = {"Agajan"};
	cout<<user.firstname;
	return 0;	
}
