#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t = 9;
    int sum = 0;
    vector<int> v(9);

    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());

    int p, q;

    for (p = 0; p < 9; p++)
    {
        for (q = p + 1; q < 9; q++)
        {
            if (sum - (v[p] + v[q]) == 100)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (i != p && i != q) cout << v[i] << '\n';
                }
                return 0;
            }
        }
    }
}