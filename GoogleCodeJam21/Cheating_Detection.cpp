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

//Did not pass!!
int main() {
    int tests;
    int p = 0;
    cin >> tests >> p; 
    int n = 100;
    int q = 10000;

    for (int test = 1; test <= tests; test++) { 
        int maxcorrect = 0;
        int cheater = -1; //assumption: cheater has the most correct answer
        for (int i = 1; i <= n; i++)
        {
            int correct = 0;
            for (int j = 0; j < q; j++)
            {
                char ans;
                cin >> ans;
                if (ans == '1')
                    correct++;
            }
            if (correct > maxcorrect)
            {
                maxcorrect = correct;
                cheater = i;
            }
        }
        cout << "Case #" << test << ": " << cheater;
    }
}
