#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nTests;
    cin >> nTests;
    for (int test = 0; test < nTests; test++)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int> > data;
        for (int i = 0; i < n; i++)
        {
            vector<int> bits;
            string bit;
            cin >> bit;
            for (char c: bit) {
                bits.push_back((c - '0'));
            }
            data.push_back(bits);
        }

        int res = k + 1;

        for (int mask = 0; mask < (1 << k); ++mask)
        {
            vector<int> dishes;
            for (int j = 0; j < k; j++)
            {
                bool bit_is_set = (mask >> j) & 1; 
                if (bit_is_set)
                {
                    dishes.push_back(j);
                }
            }
            int nDishes = 0; 
            for (int i = 0; i < n; ++i)
            {
                for (int dish : dishes)
                {
                    if (data[i][dish] == 1)
                    {
                        nDishes++;
                        break;
                    }
                }
            }
            if (nDishes == n)
            {
                res = min(res, static_cast<int>(dishes.size()));
            }
        }
        cout << res << endl;
    }
    return 0;
}