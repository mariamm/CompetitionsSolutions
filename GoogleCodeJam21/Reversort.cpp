#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <functional>
#include <tuple>

using namespace std;
int main()
{
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++)
    {
        int n = 0;
        cin >> n;

        vector<int> L(n);
        for (int& r : L)
            cin >> r;

        int cost = 0;
        for (int i = 0; i < L.size() - 1; i++) {
            //find minimum
            int idx = i;
            for (int j = i; j < L.size(); j++) {
                if (L[j] < L[idx]) {
                    idx = j;
                }
            }
            //reverse i to j
            reverse(L.begin() + i, L.begin() + idx + 1);
            cost += idx + 1 - i;
        }
        cout << "Case #" << test << ": " << cost << endl;
    }
}
