class Solution {
public:
    long long maximumSumOfHeights(vector<int>& A) 
    {
        int n = A.size();
        vector<long long > leftsum(n) , stack  = {-1};
        
        long long res = 0 , cur = 0;
        
        for(int i=0;i<n;i++){
            while(stack.size()>1 and A[stack.back()]>A[i])
            {
                // to do part
                int j = stack.back();
                stack.pop_back();
                cur -= 1L * (j-stack.back())*A[j];
            }
            
            cur+= 1L * (i-stack.back())*A[i];
            stack.push_back(i);
            leftsum[i] = cur;
        }
        
        stack = {n};
        cur = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            while(stack.size()>1 and A[stack.back()]>A[i])
            {
                 int j = stack.back();
                stack.pop_back();
                cur -=1L* -(j-stack.back())*A[j];
            }
            
            cur+= 1L * -(i-stack.back())*A[i];
            stack.push_back(i);
            res = max(res, leftsum[i] + cur - A[i]);
        }
        return res;
        
    }
    
    
    
};