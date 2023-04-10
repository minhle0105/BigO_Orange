#include <iostream>
#include <string>

using namespace std;

void print_strings(string &bit_string, int H, int idx, int count)
{
    if (idx == bit_string.size())
    {
        if (count == H)
        {
            cout << bit_string << endl;
        }
        return;
    }
    if (count > H)
    {
        return;
    }
    print_strings(bit_string, H, idx + 1, count);
    bit_string[idx] = '1';
    print_strings(bit_string, H, idx + 1, count + 1);
    bit_string[idx] = '0';
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int N, H;
        cin >> N >> H;
        string bit_string;
        bit_string.append(N, '0');
        print_strings(bit_string, H, 0, 0);
    }
}