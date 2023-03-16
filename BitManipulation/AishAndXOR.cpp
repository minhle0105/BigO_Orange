#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> bits, int l, int r)
{
    int bit_one_count = 0;
    int bit_zero_count = 0;

    for (int i = l; i <= r; i++)
    {
        bits[i] == 0 ? bit_zero_count ++ : bit_one_count ++;
    }
    int res_xor = bit_one_count % 2 != 0 ? 1 : 0;
    vector<int> res;
    res.push_back(res_xor);
    res.push_back(bit_zero_count);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> data;
    for (int i = 0; i < n; i++)
    {
        int bit;
        cin >> bit;
        data.push_back(bit);
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
        vector<int> res = solution(data, l, r);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}