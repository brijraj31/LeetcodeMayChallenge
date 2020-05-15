// Problem Link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/

/* Remove K Digits */

/* Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() <= k) return "0"; //base case
        
        string res = num;
        
        int del = k;
        
        for (int j = 0; j < k; ++j) {
            for (int i = 0; i < res.length() -1; ++i) {
                if (res[i] > res[i + 1]) {
                    res.erase(i, 1);
                    del --;
                    break;
                }
            }
        }
        
        if (del >= 1) {
            int index = res.size() - del;
            res.erase(index, del);
        }
        
        res.erase (0, res.find_first_not_of('0'));
        
        if (res.size() == 0) return "0";
        
        return res;
    }
};