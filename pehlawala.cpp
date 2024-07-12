#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

int main() {
    ll numTestCases;
    cin >> numTestCases;
    while (numTestCases--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i].first;
            nums[i].second = i;
        }
        sort(nums.begin(), nums.end());
        unordered_map<ll, ll> newIndices;
        for (int i = 0; i < n;) {
            ll j = i;
            while (j < n && nums[j].first == nums[i].first)
                j++;
            for (int k = i; k < j; k++) {
                newIndices[nums[k].second] = i;
            }
            i = j;
        }

        vector<ll> prefixSum(n, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i] = (i ? prefixSum[i - 1] : 0) + nums[i].first;
        }

        ll q;
        cin >> q;
        while (q--) {
            ll c, k;
            cin >> c >> k;
            vector<ll> indices(k);
            for (int i = 0; i < k; i++) {
                cin >> indices[i];
                indices[i]--;
                indices[i] = newIndices[indices[i]];
            }
            sort(indices.begin(), indices.end());

            ll left = 0;
            ll right = lower_bound(prefixSum.begin(), prefixSum.end(), c + 1) - prefixSum.begin() - 1;
            ll count = 0;
            ll targetSum = c;
            for (int i = 0; i < k; i++) {
                if (indices[i] <= right) {
                    count++;
                    targetSum += nums[indices[i]].first;
                    right = lower_bound(prefixSum.begin(), prefixSum.end(), targetSum + 1) - prefixSum.begin() - 1;
                }
                else
                    break;
            }
            cout << (right + 1) - count << endl;
        }
    }
    return 0;
}