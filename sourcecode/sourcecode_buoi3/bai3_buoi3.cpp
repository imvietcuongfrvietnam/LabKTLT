#include <bits/stdc++.h> 
using namespace std; 
#define MAX 100   

int n, c[MAX][MAX];
int cmin = INT_MAX;
int best = INT_MAX;
int curr;
int mark[MAX];
int x[MAX];

void input(){ 
    cin >> n; 
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j){ 
            cin >> c[i][j]; 
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]); 
        } 
} 
//Trinh Viet Cuong 20224941
void TRY(int k){ 
    for(int i = 2; i <= n; i++){ 
        if(mark[i] == 0){ 
            x[k] = i;
            mark[i] = 1; 
            curr += c[x[k-1]][x[k]]; 
            if (k == n) {
                best = min(best, curr + c[x[k]][1]); 
            } else if (curr + (n - k + 1) * cmin < best) { 
                TRY(k + 1);
            }
            curr -= c[x[k-1]][x[k]]; 
            mark[i] = 0; 
        }
    } 
} 

int main() { 
    input(); 
    x[1] = 1; 
    TRY(2); 
    cout << best; 
    return 0; 
}

