#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Data input
    int candies{0}, children{0};
    cin >> candies >> children;

    int wish{0}, i{0}, sumWishes{0};
    while(cin >> wish)
    {
        sumWishes += wish;
    }

    // Candies not to give
    int missingCandyEach{((sumWishes - candies) - (sumWishes - candies) % children) / children};

    // Lacking candy
    int childrenLackingMoreCandy{(sumWishes - candies)%children};
    int childrenLackingLessCandy{children-childrenLackingMoreCandy};

    // Anger
    int anger{childrenLackingLessCandy * (missingCandyEach * missingCandyEach)};
    if (childrenLackingMoreCandy)
    {
        int moreAnger{childrenLackingMoreCandy * ((missingCandyEach + 1) * (missingCandyEach + 1))};
        cout << anger + moreAnger << endl;
    }
    else
    {
        cout << anger << endl;
    }
    return 0;
}