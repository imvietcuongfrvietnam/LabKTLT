#include<stdio.h>
//***************** 
//Trinh Viet Cuong 20224941
//****************
int lucas(int n) { 
	//Dieu kien neo de quy
	if(n == 0){
		return 2;
	}
	else if(n == 1){
		return 1;
	}
	else return lucas(n-1) + lucas(n-2);
}
