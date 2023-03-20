#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nTests;
    cin >> nTests;
    for (int test = 0; test < nTests; test++)
    {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            int next_num;
            cin >> next_num;
            nums[i] = next_num;
        }
        if (!(n & 1))
        {
            cout << 0 << endl;
        }
        else
        {
            int res = nums[0];
            for (int i = 2; i < n; i+=2)
            {
                res = res ^ nums[i];
            }
            cout << res << endl;
        }
    }
    return 0;
}