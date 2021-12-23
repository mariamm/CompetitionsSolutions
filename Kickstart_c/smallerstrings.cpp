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

bool generatePalindrome(vector<char>& letters, int nn, bool even, int i, string s, string p, int& count)
{
    if (i == nn)
    {
        string pal = p;
        if (!even)
        { 
            pal.pop_back();
        }
        reverse(p.begin(), p.end());
        pal += p;
        if (pal < s)
        {
            count++;
            return true;
        }
        return false;
    }

    for (int j = 0; j < letters.size(); j++)
    {
        p+= letters[j];
  
        if (!generatePalindrome(letters, nn, even, i + 1, s, p, count))
            return false;
        p.pop_back();
    } 
    return true;
}
int main()
{  
    int tests;
    cin >> tests;


    for(int test = 1; test <= tests; test++)
    {
        int k = 0;
        int n = 0;
        string s = "";
        cin >>  n >> k>> s;

        //count all palindromes, with k first letters of alphabet, that are smaller than s
        int count = 0;  
        vector<char> letters; //first k letters
        for (int i = 0; i < k; i++)
            letters.push_back(i + 'a');

        if (n == 1)
        {
            for (char c : letters)
                if (c < s[0])
                    count++;
        }
        else
        {
            int nn = (n+1) / 2;
            bool even = n % 2 == 0;
            string p = "";
            generatePalindrome(letters, nn, even, 0, s, p, count);
        }
        cout << "Case #" << test << ": " <<count<< endl;
    }
}
 