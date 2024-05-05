#ifndef FUNCTIONS
#define FUNCTIONS
	int pow(int a, int b){
		int j = 1;
		for(int i=1; i<=b; i++){
			j *= a;
		}
		return j;
	}
#endif
