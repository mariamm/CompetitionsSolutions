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
#include <numeric>

using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {

        string input = "";

        cin >> input;

        string ans = "";
        char player = 'I';
        char other = 'O';
        int i = 0;
        int j = input.size() - 1;
        while (i <= j)
        {
            //Can't play
            if (player != input[i] && input[j] != player)
            {
                ans = other;
                ans += " " + to_string(j - i + 2);
                break;
            }
            //play optimally
            //"I I OOOOOIOIOIO O I"
            if (player == input[i] && input[j] == player)
            {
                //play i or j?
                //play i or j?
                int playi = 0;
                int playj = 0;
                for(int x=i; x<j; x++)
                {
                    if(input[x] == input[x+1] && input[x] == player)
                    {
                        playi = x-i;
                        break;
                    }
                }
                for(int y = j; y>i; y--)
                {
                    if(input[y] == input[y-1] && input[y] == player)
                    {
                        playj = j-y;
                        break;
                    }
                }
                if (playi < playj)
                    i++;
                else
                    j--;
            }
            else
            {
                if (player == input[i])
                    i++;
                else
                    j--;
            }
            swap(player, other);
        }
        if (ans.empty())
        {
            ans += other;
            ans += " 1";
        }

        cout << "Case #" << test << ": " << ans << endl;

    }
}