#include <iostream>
#define MAX_SIZE 200

int result[MAX_SIZE];
//Trinh Viet Cuong 20224941
bool meetsCondition(int n, int H)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (result[i] == 1)
        {
            count++;
        }
    }
    return count == H;
}

void Try(int n, int current, int H)
{
    if (current == n + 1)
    {
        if (meetsCondition(n, H))
        {
            for (size_t i = 0; i < n; ++i)
            {
                std::cout << result[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    result[current - 1] = 0;
    Try(n, current + 1, H);
    result[current - 1] = 1;
    Try(n, current + 1, H);
}

int main()
{
    int n, H;
    std::cin >> n >> H;
    Try(n, 1, H);
}

