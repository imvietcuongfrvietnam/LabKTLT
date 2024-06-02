#include <iostream> 
//Trinh Viet Cuong 20224941
using namespace std; 
int n; 
int X[100], Y[100]; //# Luu t?a d? c�c bu?c di chuy?n c?a qu�n m� 
int mark[100][100]; //# ��nh d?u v? tr� c�c � m� qu�n m� d� di chuy?n qua 
//# M?ng hx, hy m� t? 8 v? tr� qu�n m� c� th? di chuy?n k? t? v? tr� hi?n t?i 
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};  
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1}; 
//# In ra d�y c�c di chuy?n t�m du?c 
void print_sol(){ 
for (int j = 1; j <= n * n; ++j) 
printf("(%d %d)\n", X[j], Y[j]); 
exit(0); 
} 
//# Thu?t to�n quay lui 
void TRY(int k) { 
    for(int i = 0; i < 8; i++) { 
        int xx = X[k-1] + hx[i]; 
        int yy = Y[k-1] + hy[i]; 

        // Check if the new position is within the bounds of the chessboard and not visited
        if (xx > 0 && xx <= n && yy > 0 && yy <= n && mark[xx][yy] == 0) {
            X[k] = xx;
            Y[k] = yy;
            mark[xx][yy] = 1;

            if (k == n * n) { // If all squares are visited, print the solution
                print_sol();
            } else {
                TRY(k + 1);
            }

            // Backtrack
            mark[xx][yy] = 0;
        }
    } 
}
int main(){ 
cin >> n; 
mark[1][1] = 1; 
X[1] = Y[1] = 1; 
TRY(2); 
return 0; 
}
