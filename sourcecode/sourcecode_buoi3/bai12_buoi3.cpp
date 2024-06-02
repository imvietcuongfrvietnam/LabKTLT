#include <iostream>
#include <vector>
#define MAX 30
//Trinh Viet Cuong 20224941
using namespace std;

// Danh sách c?nh k?
vector<int> g[MAX + 1];

// ?ánh d?u các ??nh ?ã th?m
bool visited[MAX + 1]{};

// Bi?n nh?p li?u và bi?n ??m
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

// ??m s? ???ng ?i th?a mãn
void TRY(int v, int c) // ??nh hi?n t?i, ?? dài hi?n t?i
{
    // ?i?u ki?n neo
    // Khi ???ng ?i dài k thì t?ng bi?n ??m
    if (c == k + 1)
    {
        count++;
        return;
    }
    else
    {
        // Không thì duy?t các hàng xóm c?a ??nh ?ang th?m
        for (int ii = 0; ii < g[v].size(); ii++)
        {
            int u = g[v][ii];
            // N?u ch?a th?m thì th? ?i
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
    // ??m s? ???ng ?i ?? dài k
    for (size_t i = n; i; --i)
    {
        visited[i] = true;
        TRY(i, 1);
        visited[i] = false;
    }
    cout << count / 2; // 1 ???ng có th? ?i theo 2 chi?u
}


