#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nTests;
    cin >> nTests;
    for (int i = 0; i < nTests; i++)
    {
        long long n, m;
        cin >> n >> m;
        string res{""};
        int count = 63;
        for (auto bit : (bitset<64>(m)).to_string())
        {
            if (bit != '0')
            {
                res += ("(" + to_string(n) + "<<" + to_string(count) + ") + ");
            }
            count--;
        }
        res.erase(res.size() - 3, 3);
        cout << res << endl;
    }
    return 0;
}