class Solution {
public:
    // find first element that >= x
    int binary_search(vector<int> &arr, int l, int r, int x) {
        if(l == r) return l;
        int mid = l + (r-l)/2;
        if(x <= arr[mid])
            return binary_search(arr, l, mid, x);
        else
            return binary_search(arr, mid+1, r, x);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = binary_search(arr, 0, arr.size()-1, x);
        int l = index-1, r = index;
        vector<int> ans;
        while(ans.size() < k) {
            if( r >= arr.size() ||
               ( l >= 0 && abs(arr[l]-x) <= abs(arr[r]-x) ) ) {
                ans.push_back(arr[l]);
                --l;
            }
            else {
                ans.push_back(arr[r]);
                ++r;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
