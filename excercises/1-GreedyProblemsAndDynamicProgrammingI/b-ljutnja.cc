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
    // Data output
    cout << "candies: " << candies << " children: " << children << " sum of wishes: " << sumWishes << endl;

    // Solve the problem
    /*
    for every candy every chlid misses -> candy ^2
    if 5 kids, 18 missing candy --> 
        18-18%5/5 = 15/5 = 3 candies each not to give
        18%5 = 4 candies more not to give

        candies not to give to five kids
        [ 0 0 0 0 0 ]
        [ 3 3 3 3 3 ] + 4 more candy not to give
        [ 4 4 4 4 3 ]
        each candy not to give ^2
        [ 16 16 16 16 9 ]
        = 73

        --> 5 kids - 4 more candy = 1 kid lacks 3 candy
        the rest = 4 kids lacks 3+1 = 4 candy
    */

    // Candies not to give
    int missingCandyEach{((sumWishes - candies) - (sumWishes - candies) % children) / children};
    cout << "missingCandyEach: " << missingCandyEach << endl;

    // Lacking candy
    int childrenLackingMoreCandy{(sumWishes - candies)%children};
    cout << "childrenLackingMoreCandy: " << childrenLackingMoreCandy << endl;
    int childrenLackingLessCandy{children-childrenLackingMoreCandy};
    cout << "childrenLackingLessCandy: " << childrenLackingLessCandy << endl;

    // Anger
    int anger{childrenLackingLessCandy * (missingCandyEach * missingCandyEach)};
    cout << "anger: " << anger << endl;
    if (childrenLackingMoreCandy)
    {
        int moreAnger{childrenLackingMoreCandy * ((missingCandyEach + 1) * (missingCandyEach + 1))};
        cout << "moreAnger: " << moreAnger << endl;
        cout << ">>> total: " << anger + moreAnger << endl;
    }
    else
    {
        cout << ">>> total: " << anger << endl;
    }
    return 0;
}