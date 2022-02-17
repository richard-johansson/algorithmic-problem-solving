#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N, L;
    cin >> N >> L;

    vector<pair<long,long>> people;
    long sum{0};
    
    while(N--)
    {
        long Ai,Bi;
        cin >> Ai >> Bi;

        people.push_back(make_pair(Ai,Bi));
    }

    // Sort people in descending order based on the amount of money, if two people
    // have the same amount of money, sort descending based on time
    sort(people.begin(), people.end(), [](pair<long,long> a, pair<long,long> b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    });

    // Test print
    // for (pair<long,long> person: people)
    // {
    //     cout << person.first << ": " << person.second << endl;
    // }

    vector<long> servingQueue(L,0);
    // Serve the ones with most money, as late as possible
    for (pair<long,long> person: people)
    {
        if (person.second >= 0)
        {
            for (long i{person.second}; i >= 0; --i)
            {
                if (servingQueue[i] == 0)
                {
                    servingQueue[i] = person.first;
                    break;
                }
            }
        }
    }

    for (long money: servingQueue)
    {
        // cout << money << endl;
        sum += money;
    }

    cout << sum << endl;

    return 0;
}