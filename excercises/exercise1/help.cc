#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

/*
3
how now brown <animal>
<foo> now <color> cow
who are you
<a> <b> <a>
<a> b
c <a>
//
5
how now brown <animal>
<foo> now <color> cow
who are you
<a> <b> <a>
<a> b
c <a>
my name is bill
<fuck> <off> <bill> <bre>
om <man> gor <sa> har man
<det> blir gor eller <i> <en>
//
1
how now brown <animal>
<foo> now <color> cow
*/
/*
int main()
{
    int testCases{0};

    // Read the integer telling number of cases
    cin >> testCases;
    // cout << "Tests: " << testCases << endl;

    while (testCases > 0)
    {
        map<string,string> pattern1{};
        map<string,string> pattern2{};
        string line{""};
    
        // Read first line
        cin.ignore('\n');
        getline(cin, line);
        stringstream ss1{line};

        line = "";
        // Read second line
        cin.ignore('\n');
        getline(cin, line);
        stringstream ss2{line};

        string a{};
        string b{};
        stringstream phrase{""};
        
        // Create the phrase and save the pattern for each line
        while(ss1 >> a)
        {
            ss2 >> b;

            if (a[0] == '<') {
                pattern1[a] = b;
                phrase << b << " ";
            } else {
                pattern2[b] = a;
                phrase << a << " ";
            }
        }
        cout << "Output: " << phrase.str() << endl;

        --testCases;
    }

    cout << endl;

    return 0;
}
*/

int main()
{
    


    return 0;
}