//
// Created by 梁栋 on 2019-03-26.
//

#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int size1 = int(s.length());
        int size2 = int(p.length());
        bool dp[size1 + 1][size2 + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i=1;i<=size1;i++)
            dp[i][0] = false;
        for(int j=1;j<=size2;j++)
            dp[0][j] = dp[0][j-1] && p[j-1] == '*';
        for(int i=1;i<=size1;i++){
            for(int j=1;j<=size2;j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-1] || dp[i][j-1];
                }else{
                    if(p[j-1] == '?' || s[i-1] == p[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[size1][size2];
    }
    bool match(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        if(pattern[1] == '\0'){
            if((*str == *pattern || *pattern == '.') && *(str) == '\0')
                return match(str + 1, pattern + 1);
            else
                return false;
        }
        if(*(pattern + 1) == '*'){
            // * 前面一定存在字符，所以pattern可以加一
            if(*str == *pattern || (*pattern == '.' && *str != '\0')){
                return match(str+1, pattern) || match(str + 1, pattern + 2) || match(str, pattern + 2);
            }else{
                return match(str, pattern + 2);
            }
        }else{
            if(*str == *pattern || *pattern == '.'){
                return match(str+1, pattern + 1);
            }else{
                return false;
            }
        }
    }
    static void solution(){
        Solution solution1;
        string str1 = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab";
        string str2 = "***bba**a*bbba**aab**b";


        // cout<<solution1.match((char*)str1.data(), (char*)str2.data())<<endl;
        cout<<solution1.isMatch(str1, str2)<<endl;
    }
};