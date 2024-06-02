#include <iostream>
#define MAX 50

// ?? th? chi phí
int G[MAX][MAX]{};

// ?? th? yêu c?u
int req[MAX][MAX]{};

// Chi phí hi?n t?i
int cur_fee[MAX]{};

// S? ??nh c?n ?i qua
int count[MAX]{};

// ??nh ?ã th?m
bool visited[MAX]{};

// Chi phí hi?n t?i
int fee;

// Tính chi phí b?ng nhánh c?n
void TRY(int id, int u, int c)
{
    // ?i?u ki?n neo
    if (c == count[id] - 1)
    {
        // C?p nh?t chi phí bé nh?t v?i ??nh cu?i gi?ng yêu c?u
        if ((u == req[id][c - 1]) && (cur_fee[id] > fee))
        {
            cur_fee[id] = fee;
        }
        return;
    }
    // Ti?p t?c ?i
    for (size_t i = 1; i < count[id] - 1; i++)
    {
        // ??nh có th? ?i ???c
        if ((visited[req[id][i]] == false) && (G[u][req[id][i]]))
        {
            // Gán ?ã th?m
            visited[req[id][i]] = true;
            // Chi phí bé h?n k? l?c thì ?i
            if (fee + G[u][req[id][i]] < cur_fee[id])
            {
                // ??i chi phí và ?i ti?p
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
    // Nh?p ?? th? chi phí
    for (size_t i = 1; i < n + 1; i++)
    {
        for (size_t ii = 1; ii < n + 1; ii++)
        {
            std::cin >> G[i][ii];
        }
    }
    int cc, tmp;
    // Nh?p các iêu c?u
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
    // Tính chi phí cho m?i ng??i
    for (size_t i = 1; i < r + 1; i++)
    {
        fee = 0;
        visited[req[i][0]] = true;
        TRY(i, req[i][0], 1);
        visited[req[i][0]] = false;
        // không ?i ???c in ra 0
        std::cout << (cur_fee[i] == INT_MAX ? 0 : cur_fee[i]) << std::endl;
    }
    return 0;
}

