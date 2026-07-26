class Solution {
public:
    int largestInteger(int n, int s) {
        int n1= n;
        int m=1;
        int ans=0;
        while(n1>1){
            m*=10;
            n1--;
        }
        for(int i=0; i<n;i++){
            if(s<=9){
                ans+=s*m;
                return ans;
            }
            else{
                s-=9;
                ans+=9*m;
                m/=10;
            }
        }
            return -1;
    }
};