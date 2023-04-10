#include <iostream>
#include <map>
#include <vector>

using namespace std;

void reverse(vector<int> &nums)
{
    for (size_t i = 0; i < nums.size() / 2; ++i)
    {
        int temp = nums[i];
        nums[i] = nums[nums.size() - i - 1];
        nums[nums.size() - i - 1] = temp;
    }
}

void decimal_to_binary(int num, vector<int> &current_binary)
{
    if (num == 0)
    {
        while (current_binary.size() < 32)
        {
            current_binary.push_back(0);
        }
        reverse(current_binary);
        return;
    }
    current_binary.push_back(num % 2);
    decimal_to_binary(num / 2, current_binary);
}

int binary_to_decimal(string &binary)
{
    string decimal{binary};
    int dec_value = 0;

    int base = 1;

    size_t len = decimal.length();
    for (size_t i = len - 1; i > 0; --i) {
        if (decimal[i] == '1')
        {
            dec_value += base;
        }
        base = base * 2;
    }
    return dec_value;
}

string vector_to_string(const vector<int> &nums)
{
    string res;
    for (int num : nums)
    {
        res += to_string(num);
    }
    return res;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> binary;
        decimal_to_binary(n, binary);
        map<int, int> indexes;

        int i = 1;
        for (int index = binary.size() - 1; index >= 0; --index)
        {
            if (binary[index] == 1)
            {
                indexes[i] = index;
                i++;
            }
        }
        vector<int> a(binary.size());
        vector<int> b(binary.size());
        for (const auto &index_pair : indexes) {
            if (index_pair.first % 2 == 0) {
                b[index_pair.second] = 1;
            } else {
                a[index_pair.second] = 1;
            }
        }
        string binary_a = vector_to_string(a);
        string binary_b = vector_to_string(b);

        int res_a = binary_to_decimal(binary_a);
        int res_b = binary_to_decimal(binary_b);
        cout << res_a << " " << res_b << endl;
    }
}