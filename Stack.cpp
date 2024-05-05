#include <iostream>
#include <vector>

using namespace std;

class stack{
	int i;
	void **ptr[10];
	public:
		stack(){
			i = 0;
		}
		template<typename T>
		void push(T var){
			int iptr = new T(var);
			void ptr[i++] = iptr;
		}
		void print(){
			cout<<"[";
			for(int j=0; j<i-1; j++){
				cout<<*static_cast<int*>(ptr[j])<<", ";
			}
			cout<<static_cast<char*>(ptr[i-1])<<"]";
		}
		~stack(){}
};

int main(){
	stack stack;
	stack.push(5);
	stack.push("agajan");
	stack.print();
	return 0;
}

