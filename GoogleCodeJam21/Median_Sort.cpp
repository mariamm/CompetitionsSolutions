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

map<vector<int>, int> queries_cache;
int queries;

int ask(vector<int> v)
{
    sort(v.begin(), v.end());
    if (queries_cache.count(v))
        return queries_cache[v];

    if (queries <= 0)
        return -1;

    for (int i : v) 
        cout << i << " ";

    cout << endl; //flush
    int ans;
    cin >> ans;
    queries--;
    queries_cache[v] = ans;
    return ans;
}

void submit(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    
    cout << endl; //flush
    int ans;
    cin >> ans;
}

vector<int> findBorders(vector<int> nums, vector<int> &middles)
{
    int m = nums.size();
    vector<int> v;
    if (m < 3) 
        return nums; 

    v.push_back(nums[0]);
    v.push_back(nums[1]);
    int i = 2;
    while(middles.size() < (m - 2)) {
        //add next index in num
        v.push_back(nums[i++]); 
        int mid = ask(v);
        middles.push_back(mid);

        //Keep the two outer values and remove the median
        if (mid == v[0])
            swap(v[0], v[2]);
        else if (mid == v[1])
            swap(v[1], v[2]);
        v.pop_back();
    }
    return v;
}

int main()
{
    int tests;
    int n = 0;
    int q = 0; 
    cin >> tests >> n >> q; 
    queries = q;

    vector<int> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(i);

    for (int test = 1; test <= tests; test++)
    { 
        queries_cache.clear();
        if (n < 3)
            submit(nums);

        vector<int> middles;
        vector<int> v = findBorders(nums, middles);

        auto compare = [&](int i, int j) {
            int mid = ask({ i, j, v[0] });
            return i == mid;
        };

        stable_sort(middles.begin(), middles.end(), compare);

        //Construct solution
        nums[0] = v[0];
        nums[n - 1] = v[1];
        int idx = 1;
        for (int i : middles)
            nums[idx++] = i; 

        //Exit check
        if (queries <= 0)
            return 0;

        submit(nums);
    }
}
