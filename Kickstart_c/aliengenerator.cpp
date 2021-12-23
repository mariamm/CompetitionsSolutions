//#include <bits/stdc++.h>
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
#include <numeric>
#include <random>

using namespace std;

int main()
{  
    int tests;
    cin >> tests;


    for(int test = 1; test <= tests; test++)
    {
        int g = 0;
        int count = 0;
        cin >> g;

        //on day i, the generator will produce K + i − 1 = G_ gold bars.
        // K - G - 1 = i 
        for (int k = 1; k <= g; k++)
        {
            int g_ = 0;
            int i = 1;
            while (g_ < g)
            {
                g_ += k + i - 1;
                i++;
            }
            if (g_ == g)
                count++;
        }


        cout << "Case #" << test << ": " <<count<< endl;
    }
}
 