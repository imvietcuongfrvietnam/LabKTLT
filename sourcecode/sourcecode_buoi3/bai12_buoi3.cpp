#include <iostream>
#include <vector>
#define MAX 30
//Trinh Viet Cuong 20224941
using namespace std;

// Danh s�ch c?nh k?
vector<int> g[MAX + 1];

// ?�nh d?u c�c ??nh ?� th?m
bool visited[MAX + 1]{};

// Bi?n nh?p li?u v� bi?n ??m
int n, k, m, count = 0;

// Nh?p li?u
void init()
{
    cin >> n >> k >> m;
    int x, y;
    for (size_t i = m; i; --i)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

// ??m s? ???ng ?i th?a m�n
void TRY(int v, int c) // ??nh hi?n t?i, ?? d�i hi?n t?i
{
    // ?i?u ki?n neo
    // Khi ???ng ?i d�i k th� t?ng bi?n ??m
    if (c == k + 1)
    {
        count++;
        return;
    }
    else
    {
        // Kh�ng th� duy?t c�c h�ng x�m c?a ??nh ?ang th?m
        for (int ii = 0; ii < g[v].size(); ii++)
        {
            int u = g[v][ii];
            // N?u ch?a th?m th� th? ?i
            if (visited[u] == false)
            {
                visited[u] = true;
                TRY(u, c + 1);
                visited[u] = false;
            }
        }
    }
}

int main()
{
    init();
    // ??m s? ???ng ?i ?? d�i k
    for (size_t i = n; i; --i)
    {
        visited[i] = true;
        TRY(i, 1);
        visited[i] = false;
    }
    cout << count / 2; // 1 ???ng c� th? ?i theo 2 chi?u
}


