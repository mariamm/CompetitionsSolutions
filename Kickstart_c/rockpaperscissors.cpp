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
    int x;
    cin >> x; //expected value
    int score = 0;
    for(int test = 1; test <= tests; test++)
    {
        int w, e; //w winning profit, e=draw profit
        cin >> w >> e;

        string strategy(60, 'P');
        if (score < x)
        {
            //adjust strategy 
            int r = 0, s = 0, p = 0;
            double probr = 1. / 3.; //his prob s
            double probs = 1. / 3.; //his prob p
            double probp = 1. / 3.; //his prob r
            for (int i = 1; i <= 60; i++)
            {
                double maxprob = max({ probr, probs, probp });
                double drawprob = (probr * probp) + (probs * probr) + (probp * probs);
                score += maxprob * w + drawprob * e;
                if (probr == maxprob)
                {
                    r++;
                    strategy[i-1] = 'R';
                }
                else if (probs == maxprob)
                {
                    s++;
                    strategy[i-1] = 'S';
                }
                else
                {
                    p++;
                    strategy[i-1] = 'P';
                } 
                cout << score <<" ";

                probs = (double)r / double(i);
                probp = (double)s / double(i);
                probr = (double)p / (double)(i);
            }
        }

        cout << "Case #" << test << ": " <<strategy<< endl;
    }
}
 