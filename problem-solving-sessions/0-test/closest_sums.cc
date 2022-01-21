#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int amount_of_cases{0}, counter{1};

    while(cin >> amount_of_cases)
    {
        vector<int> sum_integers{}, sum{}, query_integers{};
        int amount_of_queries{0}, number_for_sum{0};

        // Read all numbers to be summarized
        while(amount_of_cases--)
        {
            cin >> number_for_sum;
            sum_integers.push_back(number_for_sum);
        }
        // Adding every numbers together (not with itself)
        for(int i{0}; i<sum_integers.size(); ++i)
        {
            for(int j{i+1}; j<sum_integers.size(); ++j)
            {
                sum.push_back(sum_integers[i] + sum_integers[j]);
            }
        }
        cout << "Case " << counter << ":\n";

        // Read all query numbers
        cin >> amount_of_queries;
        int query_integer{0};
        while(amount_of_queries--)
        {
            cin >> query_integer;
            query_integers.push_back(query_integer);
        }

        // Count closest sum
        sort(sum.begin(), sum.end());
        for (auto &query : query_integers)
        {
            auto greater_or_equal{lower_bound(sum.begin(), sum.end(), query)};

            cout << "Closest sum to " << query << " is ";
            // Case 1 the first integer is the closest
            if (greater_or_equal == sum.begin())
            {
                cout << *greater_or_equal << ".\n";
            }

            // Case 2 we need to see if the one step less is closer than our
            else if (abs(*greater_or_equal - query) < abs(*(greater_or_equal - 1) - query))
            {
                cout << *greater_or_equal << ".\n";
            }
            else
            {
                cout << *(greater_or_equal - 1) << ".\n";
            }
        }
        ++counter;
    }
}
