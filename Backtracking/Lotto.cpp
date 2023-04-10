#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

void solution(std::vector<int> &nums, std::vector<int> &current_sequence, int current_index)
{
    if (current_index == 6)
    {
        for (int num : current_sequence)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }
    if (current_index == 0)
    {
        for (auto num : nums)
        {
            current_sequence[current_index] = num;
            solution(nums, current_sequence, current_index + 1);
        }
    }
    else
    {
        for (auto num : nums)
        {
            if (num > current_sequence[current_index - 1])
            {
                current_sequence[current_index] = num;
                solution(nums, current_sequence, current_index + 1);
            }
        }
    }
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
        std::vector<int> current_sequence(6);
        solution(test_cases_nums[test], current_sequence, 0);
        std::cout << std::endl;
    }
}