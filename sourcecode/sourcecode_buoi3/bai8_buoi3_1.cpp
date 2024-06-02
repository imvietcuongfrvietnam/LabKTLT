#include <bits/stdc++.h> 
using namespace std; 

struct state { 
    int i, j; 
    state(int _i = 0, int _j = 0): i(_i), j(_j) {} 
}; 
	//Ban dang muon kiem tra xem mot vat cho truoc co dung nang M nhu nguoi ta noi hay khong. Co mot can thang bang va n qua can.
	//Qua thu i nang mi. Hay chi ra mot cach can thoa man. 
	//Quy cach in ra da duoc tich hop trong ma nguon duoi.
int main() { 
    int n, M; 
    cin >> n >> M; 
    int m[n + 1]; 
    for (int i = 1; i <= n; ++i) 
        cin >> m[i]; 
    int x[n + 1]; 
    stack<state> s; 
    //# sum of selected weights 
    
    int sum = 0; 
    s.push(state(1, -1)); 
    while (!s.empty()) { 
        state &top = s.top(); 
        if (top.i > n) { 
            if (sum == M) { 
                for (int i = 1; i <= n; ++i) { 
                    if (x[i] == -1) 
                        cout << '-' << m[i]; 
                    if (x[i] == 1) 
                        cout << '+' << m[i]; 
                } 
                cout << "=" << M; 
                exit(0); 
            } 
            s.pop(); 
            continue; 
        } 
        //# Khu de quy 
        //Trinh Viet Cuong 20224941
        if (top.j > 1) 
        {
            s.pop();
            sum -= m[top.i]; 
            continue;
        }

        x[top.i] = top.j;
      
        if (top.j == 0)
        {
            sum += m[top.i];
        }
        sum += x[top.i] * m[top.i];

        s.push(state(top.i + 1, -1));
  
        (top.j)++;
    }

    cout << -1;

    return 0;
}


