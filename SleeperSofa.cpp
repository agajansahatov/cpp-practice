#include <iostream>

using namespace std;

class Furniture{
	public:
		int weight;
		Furniture(int w):weight(w){
			cout<<"Constructing Furniture!"<<endl;
		}
};

class Bed: virtual public Furniture{
	public:
		Bed(int w): Furniture(w){
			cout<<"Constructing Bed!"<<endl;
		}
		void sleep(){
			cout<<"Sleep!"<<endl;
		}
};
class Sofa: virtual public Furniture{
	public:
		Sofa(int w): Furniture(w){
			cout<<"Constructing Sofa!"<<endl;
		}
		void watchTV(){
			cout<<"Watch TV"<<endl;
		}
};
class SleeperSofa: public Bed, public Sofa{
	public:
		SleeperSofa(int w): Bed(w), Sofa(w), Furniture(w){
			cout<<"Constructing Sleeper Sofa!"<<endl;
		}
		void foldOut(){
			cout<<"Fold Out!"<<endl;
		}
};
int main(){
	Bed bed(15);
	Sofa sofa(20);
	SleeperSofa ss(25);
	cout<<"Bed Weight="<<bed.weight<<endl;
	cout<<"Sofa Weight="<<sofa.weight<<endl;
	cout<<"SleeperSofa Weight="<<ss.weight<<endl;
	return 0;
}
