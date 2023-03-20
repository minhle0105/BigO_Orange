#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

pair<long, long> min_absolute_diff;
vector<long> res;

void minimize_fractions(pair<long, long> &fraction)
{
    long greatest_common_divisor = gcd(fraction.first, fraction.second);
    if (greatest_common_divisor == 1)
    {
        return;
    }
    fraction.first = fraction.first / greatest_common_divisor;
    fraction.second = fraction.second / greatest_common_divisor;
    minimize_fractions(fraction);
}

pair<long, long> get_absolute_diff(long n1, long d1, long n2, long d2)
{
    pair<long, long> res;
    res.first = abs((n1 * d2) - (n2 * d1));
    res.second = d1 * d2;
    minimize_fractions(res);
    return res;
}

bool pair_one_less_than(const pair<long, long> &pair_1, const pair<long, long> &pair_2)
{
    return (pair_1.first * pair_2.second) - (pair_1.second * pair_2.first) < 0;
}

int main()
{
    vector<long> nums(5);
    vector<long> indexes(5);
    for (long i = 0; i < 5; ++i)
    {
        cin >> nums[i];
        indexes[i] = i;
    }
    min_absolute_diff = get_absolute_diff(nums[0], nums[1], nums[2], nums[3]);
    res = {0, 1, 2, 3};
    do
    {
        vector<long> fractions(4);
        for (long i = 0; i < 4; ++i)
        {
            fractions[i] = nums[indexes[i]];   
        }
        pair<long, long> absolute_diff = get_absolute_diff(fractions[0], fractions[1], fractions[2], fractions[3]);
        if (pair_one_less_than(absolute_diff, min_absolute_diff))
        {
            min_absolute_diff = absolute_diff;
            for (long i = 0; i < 4; ++i)
            {
                res[i] = indexes[i];
            }
        }
    }
    while (next_permutation(indexes.begin(), indexes.end()));

    for (long r : res)
    {
        cout << r << " ";
    }
}
