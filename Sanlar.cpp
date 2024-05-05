#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string birlikler[] = {"nol", "bir", "iki", "uc", "dort", "bas", "alty", "yedi", "sekiz", "dokuz"};
string onluklar[] = {"on", "yigrimi", "otuz", "kyrk", "elli", "altmys", "yetmis", "segsen", "dogsan"};
string groups[] = {"", "mun ", "million ", "milliard ", "trillion ", "quadrillion ", 
					"quintillion ", "sextillion ", "septillion ", "octillion "};
/* 
	groups[0] = "" etdim sebabi gr-nyn birinji cycle-nda hic zat yazmaz yaly
	(Birinji cycle-da dine 1000den asakdaky sanlar sanalyar)
*/

/* 
	The "Integer" Function which shown by two parts belove is 
	created by using "<function overloading>"
*/
//Function of Char to Integer conversion
int integer(char ch){
	return (int)ch - (int)48;
}
//Function of String to Integer Conversion
int integer(string s){
	stringstream geek(s);
	int x = 0; 
    geek >> x;
    return x;
}

//Birlikleri, Onluklary we Yuzlukleri okayan funksiya
string read(string san){
	int size = san.size();
	if(integer(san) == 0 && size>1) return "";
	if(size == 1){
		return birlikler[integer(san[0])];	
	}else if(size == 2){
		string birlik = ""; 
		string onluk = onluklar[integer(san[0])-1];
		if(san[1] != '0') birlik = " " + birlikler[integer(san[1])];
		return onluk + birlik;
	}
	string yuzlik = birlikler[integer(san[0])] + " yuz";
	san.erase(0, 1); 
	return yuzlik + " " + read(san); //Here has a simple recursion
}

//And here is the main function begins
int main(){
	
	string san, oka;
	
	getline(cin, san);
	
	int size = san.size();
	
	if(size>0 && size<31){
		int gr = 0, counter;
		string s, oka;
		for(int i=size-1; i>=0; i--){
			if(san[i]>='0' && san[i]<='9'){
				s = san[i] + s;
				counter++;
				if(counter == 3){
					if(integer(s) != 0){
						oka = read(s) + " " + groups[gr] + oka;
					} 
					s = "";
					counter = 0;
					gr++;
				}
			}else{
				cout<<"Dine san yazmaga rugsat berilyar!"<<endl;
				oka = "";
				break;
			}
			
		}
		if(s != ""){
			oka = read(s) + " " + groups[gr] + oka;	
		}
		cout<<oka<<endl;
	}else{
		cout<<"Bagyslan!"<<endl;
		cout<<"Programma hazirlikce dine 30 sifrli sanlar ucin duzuldi."<<endl;
		cout<<"Yone eger islesen mundan yokaryny hem gosup bolya."<<endl;
		cout<<"Dine arraylara san grupbalarynyn adyny gosaymaly..."<<endl;
	}

	return 0;
}
