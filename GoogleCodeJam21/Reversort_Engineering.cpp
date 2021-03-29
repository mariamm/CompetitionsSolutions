#include <bits/stdc++.h>
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

int revsort(vector<int> L)
{
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
    return cost;
}
int main()
{
    int tests;
    cin >> tests; 
    for (int test = 1; test <= tests; test++)
    {
        
        int n = 0;
        int c = 0;
        cin >> n >> c;

        vector<int> L;
        for (int i=1; i<=n; i++) 
            L.push_back(i); 

        bool found = false;
        string ans = "";
        do 
        {
            int cost = revsort(L);
            if (cost == c && ans =="")
            {
                found = true;
                for (int f : L)
                {
                    ans += to_string(f) + " ";
                } 
            }
        } while (next_permutation(L.begin(), L.end()));
        if (!found) 
            cout << "Case #" << test << ": " << "IMPOSSIBLE" << endl;
        else
            cout << "Case #" << test << ": " << ans << endl;
    }
}