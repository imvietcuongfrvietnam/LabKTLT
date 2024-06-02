#include <iostream>
#define MAX_DAYS 200 //So ngay toi da

int workSchedule[MAX_DAYS]; 
int consecutiveWorkDays[MAX_DAYS];
//Trinh Viet Cuong 20224941
bool check(int n, int minConsecutiveWorkDays, int maxConsecutiveWorkDays)
{
    bool flag = true;
    consecutiveWorkDays[0] = workSchedule[0];
    for (size_t i = 1; i < n; i++)
    {
        if (workSchedule[i] == 0)
        {
            consecutiveWorkDays[i] = 0;
            continue;
        }
        consecutiveWorkDays[i] = (!consecutiveWorkDays[i - 1]) ? 1 : consecutiveWorkDays[i - 1] + 1;
        consecutiveWorkDays[i - 1] = (!consecutiveWorkDays[i - 1]) ? 0 : consecutiveWorkDays[i];
        size_t ii = i - 1;
        while ((workSchedule[ii] == 1) && ii)
        {
            consecutiveWorkDays[ii] = consecutiveWorkDays[i];
            ii--;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if ((consecutiveWorkDays[i] != 0) && (consecutiveWorkDays[i] < minConsecutiveWorkDays || consecutiveWorkDays[i] > maxConsecutiveWorkDays))
        {
            flag = false;
            break;
        }
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        if ((!consecutiveWorkDays[i]) & (!consecutiveWorkDays[i + 1]))
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void Try(int n, int cur, int minConsecutiveWorkDays, int maxConsecutiveWorkDays)
{
    if (cur == n + 1)
    {
        if (check(n, minConsecutiveWorkDays, maxConsecutiveWorkDays) == true)
        {
            for (size_t i = 0; i < n; ++i)
            {
                std::cout << workSchedule[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    workSchedule[cur - 1] = 0;
    Try(n, cur + 1, minConsecutiveWorkDays, maxConsecutiveWorkDays);
    workSchedule[cur - 1] = 1;
    Try(n, cur + 1, minConsecutiveWorkDays, maxConsecutiveWorkDays);
}

int main()
{
    int n, minConsecutiveWorkDays, maxConsecutiveWorkDays;
    std::cin >> n >> minConsecutiveWorkDays >> maxConsecutiveWorkDays;
    Try(n, 1, minConsecutiveWorkDays, maxConsecutiveWorkDays);
}

