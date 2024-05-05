#include <iostream>
#include <string>
using namespace std;
int main(){
	string s, bogun;
	string vowels = "aeiyouAEYIOU";
	int yad, consts;
	do{
		s = ""; bogun = ""; yad = 0; consts = 0;
		getline(cin, s);
		if(s == "exit"){
			break;
		}else{
			bogun = s;
			for(int i=0; i<s.length(); i++){
				if (vowels.find(s[i]) != -1){
					if(yad == 0){
						yad = 1;	
					}else if(yad == 1){
						if (consts>0) bogun.insert(i-1, "-"); else 	bogun.insert(i, "-");
						yad++;
					}else if(yad > 1){
						if (consts>0) bogun.insert(i+yad-2, "-"); else bogun.insert(i+yad-1, "-");
						yad++;
					}
					consts = 0;
				}else{
					consts++;
				}
				
			}
			cout<<bogun<<endl;
		}
	}while(true);
	return 0;	
}
