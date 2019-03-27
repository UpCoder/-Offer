//
// Created by 梁栋 on 2019-03-27.
//
#include <string>
#include <cstring>
using namespace std;
class Solution{
public:
    bool isNumericWOE(char* string1){
        if((*string1) == '\0')
            return false;
        if((*string1) == '+' || (*string1) == '-')
            string1 += 1;
        while((*string1) != '\0'){
            if((*string1) >= '0' && (*string1) <= '9'){
                string1 += 1;
            }else{
                return false;
            }
        }
        return true;
    }
    bool isNumericWOFlag(char* string1, bool meet_point= false){
        int start_pos = 0;
        char* cur_char = string1;
        while((*cur_char) != '\0'){
            if((*cur_char) >= '0' && (*cur_char) <= '9'){
                cur_char += 1;
            }else{
                if((*cur_char) == 'E' || (*cur_char) == 'e'){
                    return isNumericWOE(cur_char + 1);
                }else{
                    if((*cur_char) == '.' && !meet_point){
                        return isNumericWOFlag(cur_char + 1, true);
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isNumeric(char* string1)
    {
        if(string1[0] == '-' || string1[0] == '+'){
            return isNumericWOFlag(string1+1);
        }
        return isNumericWOFlag(string1);
    }

    static void solution(){
        Solution solution1;
        string string1 = "12e+5.4";
        cout<<solution1.isNumeric((char*) string1.c_str())<<endl;
    }
};