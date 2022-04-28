/**
 * @file 3.2-suffixsorting.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief https://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm/
 */
#include <bits/stdc++.h>

using namespace std;

class SuffixArray
{
    private:


    public:
        SuffixArray(string s);
        int getSuffix(int i);
};

/**
 * @brief Construct a new Suffix Array:: Suffix Array object
 * from a string
 * 
 * @param s 
 */
SuffixArray::SuffixArray(string s)
{

}

/**
 * @brief return the i:th smallest object in the suffix array
 * 
 * @param i 
 * @return int 
 */
int SuffixArray::getSuffix(int i)
{

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while(getline(cin, s))
    {
        // Read input
        int n;
        cin >> n;

        vector<int> qN;
        int qI;
        while (n--)
        {
            cin >> qI;
            qN.push_back(qI);
        }

        
        cout << s << ": ";
        for (auto &q : qN)
        {
            cout << q << " ";
        }
        cout << endl;

        cin.ignore(1, '\n');
    }
    return 0;
}