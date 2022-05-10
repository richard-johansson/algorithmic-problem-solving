/**
 * @file c-longest_increasing_subsequence.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis (vector<long int> const& a)
{
    long int n = a.size();
    const long int infinity = 1e9;
    vector<long int> d(n+1, infinity), p(n, -1);
    d[0] = -infinity;

    for (long int i{0}; i < n; ++i)
    {
        long int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
        {
            d[j] = a[i];
            // p[i] = j;
        }
    }
    long int ans{0};
    for (long int i{0}; i <= n; ++i)
    {
        if (d[i] < infinity)
        {
            ans = i;
            // if (p[i] != -1)
            // {
            //     cout << p[i] << " ";
            // }
        }
    }
    // cout << "\n";
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read length of sequence
    long int n{0};

    // For every test case
    while (cin >> n)
    {
        int i{0};
        vector<long int> a;
        // Read input
        while(n--)
        {
            cin >> i;
            a.push_back(i);
        }

        // Test print
        // for (auto &x : a) { 
        //     cout << x << " ";
        // } cout << endl;

        // Call solver
        cout << lis(a) << "\n";

    }

    


    return 0;
}