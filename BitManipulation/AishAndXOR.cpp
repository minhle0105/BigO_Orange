#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> bits;
    vector<int> number_of_bit_one;
    number_of_bit_one.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int bit;
        cin >> bit;
        bits.push_back(bit);
        number_of_bit_one.push_back(number_of_bit_one.back() + bit);
    }
    int nQuery;
    cin >> nQuery;
    vector<vector<int> > queries;
    for (int i = 0; i < nQuery; i++)
    {
        int l, r;
        cin >> l >> r;
        vector<int> query;
        query.push_back(l - 1);
        query.push_back(r - 1);
        queries.push_back(query);
    }
    for (int i = 0; i < nQuery; i++)
    {
        vector<int> query = queries[i];
        int l = query[0];
        int r = query[1];
        int res_1 = (number_of_bit_one[r + 1] - number_of_bit_one[l]) & 1;
        int res_2 = (r - l + 1) - (number_of_bit_one[r + 1] - number_of_bit_one[l]);
        cout << res_1 << " " << res_2 << endl;
    }
    return 0;
}
