#include <iostream>
#define MAX 50

// ?? th? chi ph�
int G[MAX][MAX]{};

// ?? th? y�u c?u
int req[MAX][MAX]{};

// Chi ph� hi?n t?i
int cur_fee[MAX]{};

// S? ??nh c?n ?i qua
int count[MAX]{};

// ??nh ?� th?m
bool visited[MAX]{};

// Chi ph� hi?n t?i
int fee;

// T�nh chi ph� b?ng nh�nh c?n
void TRY(int id, int u, int c)
{
    // ?i?u ki?n neo
    if (c == count[id] - 1)
    {
        // C?p nh?t chi ph� b� nh?t v?i ??nh cu?i gi?ng y�u c?u
        if ((u == req[id][c - 1]) && (cur_fee[id] > fee))
        {
            cur_fee[id] = fee;
        }
        return;
    }
    // Ti?p t?c ?i
    for (size_t i = 1; i < count[id] - 1; i++)
    {
        // ??nh c� th? ?i ???c
        if ((visited[req[id][i]] == false) && (G[u][req[id][i]]))
        {
            // G�n ?� th?m
            visited[req[id][i]] = true;
            // Chi ph� b� h?n k? l?c th� ?i
            if (fee + G[u][req[id][i]] < cur_fee[id])
            {
                // ??i chi ph� v� ?i ti?p
                fee += G[u][req[id][i]];
                TRY(id, req[id][i], c + 1);
                fee -= G[u][req[id][i]];
            }
            // B? th?m
            visited[req[id][i]] = false;
        }
    }
}
//Trinh Viet Cuong 20224941
int main()
{
    int n, r;
    std::cin >> n >> r;
    // Nh?p ?? th? chi ph�
    for (size_t i = 1; i < n + 1; i++)
    {
        for (size_t ii = 1; ii < n + 1; ii++)
        {
            std::cin >> G[i][ii];
        }
    }
    int cc, tmp;
    // Nh?p c�c i�u c?u
    for (size_t i = 1; i < r + 1; i++)
    {
        cc = 0;
        cur_fee[i] = INT_MAX;
        do
        {
            std::cin >> tmp;
            req[i][cc++] = tmp;
        } while (tmp != -1);
        count[i] = cc;
    }
    // T�nh chi ph� cho m?i ng??i
    for (size_t i = 1; i < r + 1; i++)
    {
        fee = 0;
        visited[req[i][0]] = true;
        TRY(i, req[i][0], 1);
        visited[req[i][0]] = false;
        // kh�ng ?i ???c in ra 0
        std::cout << (cur_fee[i] == INT_MAX ? 0 : cur_fee[i]) << std::endl;
    }
    return 0;
}

