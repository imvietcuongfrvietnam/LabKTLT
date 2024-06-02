#include <iostream> 
//Trinh Viet Cuong 20224941
using namespace std; 
int gcd(int a, int b){ 
if (b == 0) return a; 
return gcd(b, a % b); 
} 
 
int gcd2(int a, int b){ 
     int res;
     while(b!=0){
     	res = a%b;
     	a = b;
     	b = res;
	 }
	 res = a;
	 return res;
} 
 
int main() { 
    int a, b; 
    cin >> a >> b; 
    cout << gcd(a, b) << endl << gcd2(a, b); 
    return 0; 
}
