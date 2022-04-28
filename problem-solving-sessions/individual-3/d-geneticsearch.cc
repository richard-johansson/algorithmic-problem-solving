/**
 * @file d-geneticsearch.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S, L;

    while(cin >> S)
    {
        set<string> type2, type3;
        // cout << S << " ";
        if (S.front() == '0')
        {
            break;
        }
        
        cin >> L;

        // Add all types to word arrays
        // words.insert(S);
        for(int i{0}; i < S.length(); ++i)
        {
            // Remove one letter
            type2.insert(S.substr(0,i) + S.substr(i+1,S.length()));

            // Add A
            type3.insert(S.substr(0,i) + 'A' + S.substr(i,S.length()));
            type3.insert(S + 'A');

            // Add G
            type3.insert(S.substr(0,i) + 'G' + S.substr(i,S.length()));
            type3.insert(S + 'G');

            // Add C
            type3.insert(S.substr(0,i) + 'C' + S.substr(i,S.length()));
            type3.insert(S + 'C');

            // Add T
            type3.insert(S.substr(0,i) + 'T' + S.substr(i,S.length()));
            type3.insert(S + 'T');
        }

        int count{0};

        string word{S};
        int index{0};
        while ((index = L.find(word, index)) != string::npos)
        {
            ++count;
            ++index;
        }
        cout << count << " ";
        
        count = 0;
        for (string w : type2)
        {
            word = w;
            int index{0};
            while ((index = L.find(word, index)) != string::npos)
            {
                ++count;
                ++index;
            }
        }
        cout << count << " ";
        
        count = 0;
        for (string w : type3)
        {
            word = w;
            int index{0};
            while ((index = L.find(word, index)) != string::npos)
            {
                ++count;
                ++index;
            }
        }
        cout << count << "\n";
    }

    return 0;
}