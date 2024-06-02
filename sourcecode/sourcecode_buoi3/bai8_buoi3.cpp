#include <iostream>
#include <stack>
using namespace std;

struct state { 
    int i, j, old_L;
    // Constructor 
    state(int _i = 0, int _j = 0, int _L = 0) : i(_i), j(_j), old_L(_L) {}
};

int main() {
int n,k;
cin>>n>>k; 
int x[n+1] = {0};
for(int i = 0;i<=n;i++){
	cin>>x[i];
}
    for (int i = 1; i <= n; ++i) 
cout << x[i] << " \n"[i == n]; 
}
