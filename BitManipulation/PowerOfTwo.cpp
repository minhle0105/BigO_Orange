#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool isPowerOfTwo(int x)
{
    return (x & (-x)) == x;
}

bool solution(vector<int> nums)
{
    for (int bit = 0; bit < 32; ++bit)
    {
        vector<int> set_bits;
        for (int num : nums)
        {
            if (((num >> bit) & 1) == 1)
            {
                set_bits.push_back(num);
            }
        }
        if (set_bits.size() == 0)
        {
            continue;
        }
        int and_bits = set_bits[0];
        for (int set_bit : set_bits)
        {
            and_bits &= set_bit;
        }
        if (isPowerOfTwo(and_bits))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int nTest;
    cin >> nTest;
    for (int test = 0; test < nTest; test++)
    {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        if (solution(nums))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}