#include <iostream>
#include <cstring>

using namespace std;

class Student{
	private:
		char *name, *ID;
		int grade;
	public:
		Student(char *strname="", char *id = " ", int g = 0){
			name = new char [strlen(strname)+1];
			strcpy(name, strname);
			ID = new char[strlen(id)+1];
			strcpy(ID, id);
			grade = g;
		}
		Student(const Student& s){
			name = new char[strlen(s.name)+1];
			strcpy(name, s.name);
			ID = new char[strlen(s.ID)+1];
			strcpy(ID, s.ID);
			grade = s.grade;
		}
		Student& operator = (const Student &s){
			delete[] name;
			name = new char[strlen(s.name)+1];
			strcpy(name, s.name);
			
			delete[] ID;
			ID = new char[strlen(s.ID)+1];
			strcpy(ID,s.ID);
			
			grade = s.grade;
			return *this;
		}
		operator int(){
			return -1000;
		}
		void print() const{
			cout<<"Student: "<<ID<<" "<<name<<"; grade: "<<grade<<endl;
		}
		~Student(){
			delete[] name;
			delete[] ID;
		}
};

//VECTOR CLASS
template<typename T>
class Vector{
	private:
		T *values;
		int size;
		int space;
	public:
		Vector(): size(0), values(0), space(0) {}
		Vector(int len){
			size = 0;
			space = 0;
			values = new T[len];
		}
		Vector(const Vector &v){ //Copy constructor is needed because we used free memory space;
			size = v.size;
			values = new T[size];
			for(int i=0; i<size; ++i){
				values[i] = v.values[i];
			}
			space = v.space;
		}
		Vector &operator=(const Vector &v){
			if(&v!=this){
				delete[] values;
				values = new T[v.size];
				for(int i=0; i<v.size; i++){
					values[i] = v.values[i];
				}
				space = v.space;
			}
			return *this;
		}
		T &operator[](int index){
			return values[index];
		}
		T at(int index){
			if(index>=size){
				cout<<"Beyond boundary\n";
				return values[index];
			}else{
				return values[index];
			}
		}
		
		void reserve(int newalloc){
			if(newalloc<=space){
				return;
			}
			T *p = new T[newalloc];
			for(int i=0; i<=size; i++){
				p[i] = values[i];
				delete[] values;
				values = p;
				space = newalloc;
			}
		}
		
		void push_back(T d){
			if(space == 0){
				reserve(8);
			}else if(space == size){
				reserve(2*space);
			}
			values[size] = d;
			++size;
		}
		void pop_back(){
			if(empty()){
				cout<<"Vector is empty.\n";
			}
			else{
				--size;
			}
		}
		
		void resize(int newsize){
			reserve(newsize);
			for(int i=size; i<newsize; ++i){
				values[i] = 0;
			}
			size = newsize;
		}
		int getSize() const{
			return size;
		}
		int capacity() const {
			return space;
		}
		bool empty() const{
			return size == 0;
		}
		void clear(){
			size = 0;
		}
		
		friend ostream &operator<<(ostream&, Vector<T>&);
		
		~Vector(){
			delete[] values;
		}
};
template <typename T>
ostream &operator<<(ostream &os, Vector<T> &v){
	for(int i=0; i<v.getsize(); ++i){
		os<<v.values[i]<<" ";
	}
	return os;
}

int main(){
	int i;
	Vector<Student>sVector(3);
	cout<<"sVector size: "<<sVector.getSize()<<" sVector' space: "<<sVector.capacity()<<endl;	
	
	return 0;
}
