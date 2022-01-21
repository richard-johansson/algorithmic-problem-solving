#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;
/* Example input
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line{};
    unordered_map<string, string> pattern{};

    while(getline(cin, line))
    {
        string a{}, b{};
        if (line.empty())
        {
            break;
        }
        stringstream line_stream{line};
        line_stream >> a >> b;
        pattern[b] = a;
    }

    while (getline(cin, line))
    {
        string english{pattern[line]};
        if (english.empty())
        {
            cout << "eh" << "\n";
        }
        else 
        {
            cout << english << "\n";
        }
    }

    return 0;
}