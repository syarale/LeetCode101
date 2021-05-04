// 167：两数之和 2，输入有序数组

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        vector<int> ret;
        
        if (len <= 1) {
            return ret;
        }
        
        int i = 0; 
        int j = len - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                ret.push_back(i + 1);
                ret.push_back(j + 1);
                break;
            } 
            
            if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        
        return ret;
    }
};  
