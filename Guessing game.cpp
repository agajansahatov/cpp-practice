#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	
	srand(time(NULL));
	int random = rand() % 100, number, count = 1;
	
	cout<<"Guess my number: ";
	cin>>number;
	
	while(true){
		if(number == random){
			cout<<"\nGreat! You won!"<<endl;
			cout<<"It took "<<count<<" times to guess this number :)";
			return false;
		}else if(number > random){
			cout<<"Too High! Try one more time: ";
			cin>>number;
			count++;
		}else if(number < random){
			cout<<"Too Low! Try one more time: ";
			cin>>number;
			count++;
		}
	}
	return 0;
}
