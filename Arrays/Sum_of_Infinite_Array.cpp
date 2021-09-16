
//  Given an array “A” of N integers and you have also defined the new array “B” as a concatenation of array “A” for an infinite number of times.

//Now you are given Q queries, each query consists of two integers “L“ and “R”. 
// Your task is to find the sum of the subarray from index “L” to “R” (both inclusive) in the infinite array “B” for each query.
//Constraints :
//1 <= T <= 100
//1 <= N <= 10^4   
//1 <= A[i] <= 10^9
//1 <= Q <= 10^4
//1 <= L <= R <= 10^18

//Time Limit: 1sec
//The value of the sum can be very large, return the answer as modulus 10^9+7.
//SOLUTION:


vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here
   long long  mo = 1000000007;
    vector <int> ans(q);
    vector <long long> presum(n+1);
    presum[0] = 0;
    for(long long i = 0; i < n; i++)
    	presum[i+1] = (presum[i] + arr[i]) % mo;
    long long temp;
    for(long long i = 0; i < q; i++)
    {
    long long l=queries[i][0];
    long long r=queries[i][1];
    l--;
    temp = (presum[r % n] - presum[l % n] + ((presum[n] * ((r/n - l/n) % mo)))) % mo ;
    ans[i] = temp;
    }
    return ans;
}
