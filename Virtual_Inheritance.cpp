#include<iostream>
using namespace std;

class Person{
	public:
	Person(){ cout<<"Person created!\n"; }
	~Person(){ cout<<"Person deleted!\n"; }
};
class Teacher: virtual public Person{
	public:
	Teacher(){ cout<<"Teacher created!\n"; }
	~Teacher(){ cout<<"Teacher deleted!\n"; }
};
class Student: virtual public Person{
	public:
	Student(){ cout<<"Student created!\n"; }
	~Student(){ cout<<"Student deleted!\n"; }
};
class Graduate: public Teacher, public Student{
	public:
	Graduate(){ cout<<"Graduate created!\n"; }
	~Graduate(){ cout<<"\nGraduate deleted!\n"; }
};

int main(){
	Graduate Johnny;
	return 0;
}
