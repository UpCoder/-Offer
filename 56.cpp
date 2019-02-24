//
// Created by 梁栋 on 2019-02-22.
//
#include <vector>
#include <iostream>
using namespace std;
class FindOnceNumber{
private:
    static int findBinaryOnePosition(int x){
        // 在x的二进制中找到一位为1的位置
        int res = 1;
        while(true){
            if(x & 1 == 1)
                return res;
            x >>= 1;
            res += 1;
        }
    }
public:
    static int findAppearOnceNumber(vector<int> nums){
        // 数组中除了某一个数，其他数字都出现了两次。
        if(nums.size() == 0 || nums.size() % 2 == 0){
            cout<<"Error"<<endl;
            return -1;
        }
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            res ^= nums[i];
        }
        return res;
    }
    static int findTwoAppearOnceNumber(vector<int> nums){
        // 数组中除了两个数，其他数字都出现了两次
        if(nums.size() == 0 || nums.size() % 2 == 1){
            cout<<"Error 1"<<endl;
            return -1;
        }
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            res ^= nums[i];
        }
        if(res == 0){
            cout<<"Error 2"<<endl;
            return -1;
        }
        int pos = findBinaryOnePosition(res);
        int splited_number = (1 << (pos-1));

        int num1 = 0;
        int num2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & splited_number == 1){
                num1 ^= nums[i];
            }else{
                num2 ^= nums[i];
            }
        }
        cout<<"one number is "<<num1<<", other number is "<<num2<<endl;
        return 0;
    }
    static int findOneAppearThirdNumber(vector<int> nums){
        if(nums.size() == 0){
            cout<<"Error1"<<endl;
            return -1;
        }
       int digits[32] = {0};
        for(int i=0;i<nums.size();i++){
            //int bitMask = 1;
            for(int idx=0;idx<32;idx++){
                int bit = nums[i] & (1 << idx);
                if(bit != 0)
                    digits[idx] += 1;
            }
        }
        for(int i=0;i<32;i++)
            cout<<digits[i]<<",";
        cout<<endl;
        int res = 0;
        for(int idx=0; idx<=31; idx++){
            res <<= 1;
            if(digits[idx] % 3 != 0){
                res += (digits[idx] % 3);
            }
        }
        return res;
    }
};
class Solution{
public:
    static void solution(){
        FindOnceNumber findOnceNumber;
        vector<int> nums = {1, 1, 2, 2, 3, 3, 5, 9, 9};
        cout<<findOnceNumber.findAppearOnceNumber(nums)<<endl;
        vector<int> nums_2 = {1, 1, 2, 2, 3, 3, 5, 9, 9, 0};
        findOnceNumber.findTwoAppearOnceNumber(nums_2);
        cout<<sizeof(int)<<endl;
        cout<<((1<<(31)) | 1)<<endl;
        // 注意，C++里面是以补码的形式存储负数的，补码即原码除符号位外，全部取反再+1
        vector<int> nums_3 = {1, 1, 1, -2, -2, -2, 4, 4, 5, -1, 5, 4, 5};
        cout<<findOnceNumber.findOneAppearThirdNumber(nums_3)<<endl;
    }
};
