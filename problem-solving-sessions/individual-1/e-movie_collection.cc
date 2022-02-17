#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    
    long m,r;
    vector<long> id;

    while(cases--)
    {
        cin >> m >> r;

        long ai;
        while(r--)
        {
            cin >> ai;
            id.push_back(ai);
        }

    }


    return 0;
}