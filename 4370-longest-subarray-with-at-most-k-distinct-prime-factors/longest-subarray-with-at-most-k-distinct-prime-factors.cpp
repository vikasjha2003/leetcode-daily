class Solution {
public:
    vector<int> isPrime() {
        vector<int> prime(1e5+1, 1);
        prime[0] = 0, prime[1] = 0;
        int n = prime.size();

        for(int i = 2; i*i< n; i++) {
            if(prime[i] == true) {
                for(int j = i*i; j<n; j += i) {
                    prime[j] = false;
                }
            }
        }

        return prime;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prime = isPrime();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int,int> freq;

        while(r < n) {
            for(int i = 1; i*i <= nums[r]; i++) {
                if(nums[r] % i == 0) {
                    if(prime[i]) {
                        freq[i]++;
                    }
                    if(prime[nums[r]/i]) {
                        freq[nums[r]/i]++;
                    }
                }
            }

            while(freq.size() > k) {
                for(int i = 1; i*i <= nums[l]; i++) {
                    if(nums[l] % i == 0) {
                        if(prime[i]) {
                            freq[i]--;
                            if(freq[i] == 0) freq.erase(i);
                        }
                        if(prime[nums[l]/i]) {
                            freq[nums[l]/i]--;
                            if(freq[nums[l]/i] == 0) freq.erase(nums[l]/i);
                        }
                    }
                }
                l++;
            }

            maxLen = max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }
};