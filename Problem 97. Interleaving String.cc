class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 == 0)
            len1 = 1;
        if (len2 == 0)
            len2 = 1;
        
        string dp[len1+1][len2+1];
        dp[0][0] = "";  

        for (int i=0; i<=len1; i++){
            dp[i][0]=s1.substr(0, i);
        }
        for (int j=0; j<=len2; j++){
            dp[0][j]=s2.substr(0, j);
        }

        for (int i=1; i<=len1; i++){
            for (int j=1; j<=len2; j++){
                string above = dp[i-1][j] + s1[i-1];
                string left  = dp[i][j-1] + s2[j-1];
                if (above == s3.substr(0, i+j))
                    dp[i][j] = above;
                else if (left == s3.substr(0, i+j))
                    dp[i][j] = left;
                else
                    dp[i][j] = "";
            }
        }
        for (int i=0; i<=len1; i++){
            for (int j=0; j<=len2; j++){
                cout<<dp[i][j] << " ";
            }
            cout<<"\n";
        }
        return (dp[s1.length()][s2.length()] == s3);

    }
};
