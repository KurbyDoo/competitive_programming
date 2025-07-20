#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

int n, m;
ll k;
int nums[1000000];
using namespace std;

int main()
{
    // ofstream fout("output.txt");
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> k;
    ll total_needed = k - n;

    int lastNum = 0;
    int currentAdd = 0;

    if (k < n)
    {
        cout << "-1\n";
        return 0;
    }

    if (k == n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << "1 ";
        }

        cout << "1\n";

        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        // cout << "needed = " << total_needed << "\n";
        if (total_needed >= currentAdd)
        {
            // cout << "need more" << "\n";
            if (lastNum < m)
            {
                nums[i] = lastNum + 1;
                total_needed -= currentAdd;
                currentAdd++;
                if (currentAdd >= m)
                {
                    currentAdd = m - 1;
                }
                lastNum++;
            }
            else if (lastNum == m && lastNum != 1)
            {
                lastNum = 0;
                nums[i] = lastNum + 1;
                total_needed -= currentAdd;
                lastNum++;
            }
        }
        else if (total_needed == 0)
        {
            // cout << "have enough" << "\n";
            if (lastNum == 0)
            {
                lastNum = 1;
            }
            nums[i] = lastNum;
        }
        else if (total_needed < currentAdd)
        {
            // cout << "needed less" << "\n";
            int newNum = lastNum - total_needed;
            // cout << newNum << "\n";
            if (newNum <= 0)
            {
                newNum = m + (lastNum - total_needed);
            }
            nums[i] = newNum;
            lastNum = newNum;
            total_needed = 0;
        }
        // cout << "added " << nums[i] << "\n";
    }

    if (total_needed > 0 || k < n)
    {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << nums[i] << " ";
    }

    cout << nums[n - 1] << "\n";

    return 0;
}