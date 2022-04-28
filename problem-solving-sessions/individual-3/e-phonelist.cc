/**
 * @file e-phonelist.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{0}, n{0};
    cin >> t;
    while (t--)
    {
        bool consistent{true};
        cin >> n;
        vector<string> numbers;
        string number;
        while(n--)
        {
            cin >> number;
            numbers.push_back(number);
        }

        sort(numbers.begin(), numbers.end());

        for (int i{0}; i<numbers.size(); ++i)
        {
            if (numbers[i+1].find(numbers[i]) != string::npos) // OUT OF BOUNDS???
            {
                consistent = false;
                break;
            }
        }
        if (consistent)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}