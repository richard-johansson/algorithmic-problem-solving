#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line{};
    while(getline(cin, line))
    {
        unordered_map<int, int> person_a{};
        int N{0}, M{0}, cd{0}, match{0};

        stringstream line_stream{line};
        line_stream >> N >> M;
        if (N == 0 && M == 0)
        {
            return 0;
        }
        while (N--)
        {
            cin >> cd;
            person_a[cd] = 1;
        }
        while (M--)
        {
            cin >> cd;
            if (person_a[cd] == 1)
            {
                match++;
            }
        }
        cout << match << "\n";
        cin.ignore(1, '\n');
    }
    return 0;
}