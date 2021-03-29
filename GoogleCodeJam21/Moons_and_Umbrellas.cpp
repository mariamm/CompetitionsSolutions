
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

int main() {
	int tests;
	cin >> tests;

	for (int test = 1; test <= tests; test++) {
		int x, y;
		string word;
		cin >> x >> y >> word;
		int cost = 0;

		char prev = word[0];
		for (int i=1; i < word.length(); i++)
		{
			if (word[i] == '?')
				continue;

			if (prev == 'J' && word[i] == 'C')
				cost += y;
			
			else if (prev == 'C' && word[i] == 'J')
				cost += x;

			prev = word[i];
		}
		cout << "Case #" << test << ": " << cost << endl;
	}
}