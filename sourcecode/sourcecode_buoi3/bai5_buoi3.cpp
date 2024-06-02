#include <iostream> 
using namespace std; 
//Trinh Viet Cuong 20224941
int binom(int n, int k) { 
if (k > n) return 0; 
if (k == 0) return 1; 
return binom(n-1, k) + binom(n-1, k-1); 
} 
int binom2(int n, int k){ 
	int tu = n;
	int mau = 1;
	int res = 1;
	while(mau!=n-k+1){
		res*=tu;
		res/=mau;
		tu--;
		mau++;
	}
	return res;

} 
int main() { 
int m; 
cin >> m; 
for (int n = 1; n <= m; ++n){ 
for (int k = 0; k <= n; ++k) 
printf("%d ", binom(n, k)); 
printf("\n"); 
} 
for (int n = 1; n <= m; ++n){ 
for (int k = 0; k <= n; ++k) 
printf("%d ", binom2(n, k)); 
printf("\n"); 
} 
return 0; 
}
