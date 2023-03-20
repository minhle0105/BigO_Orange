#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

void solution(std::vector<int> &nums, std::vector<int> &indexes)
{
    do
    {
        std::vector<int> subset;
        subset.reserve(6);
        for (int i = 0; i < 6; ++i)
        {
            subset.push_back(nums[indexes[i]]);
        }
        for (int i = 0; i < 6; ++i)
        {
            std::cout << subset[i] << " ";
        }
        std::cout << std::endl;
    }
    while (next_combination(indexes.begin(), indexes.end()));
    std::cout << "\n";
}

int main()
{
    int k;
    std::vector<std::vector<int>> test_cases_nums;
    std::vector<std::vector<int>> test_cases_indexes;
    test_cases_nums.reserve(k);
    test_cases_indexes.reserve(k);
    int nTest = 0;
    while (true)
    {
        std::cin >> k;
        if (k == 0)
        {
            break;
        }
        std::vector<int> nums;
        std::vector<int> indexes;
        nums.reserve(k);
        indexes.reserve(k);
        for (int i = 0; i < k; ++i)
        {
            int num;
            std::cin >> num;
            nums.push_back(num);
            indexes.push_back(i);
        }
        test_cases_nums.push_back(nums);
        test_cases_indexes.push_back(indexes);
        nTest++;
    }
    for (int test = 0; test < nTest; ++test)
    {
        solution(test_cases_nums[test], test_cases_indexes[test]);
    }
}