
// 415. Add Strings

class Solution {
public:
    string addChar(string num1, int ptr1, string num2, int ptr2, int& add) {
        int number1 = 0, number2 = 0;
        if (0 <= ptr1 && ptr1 < num1.size()) {
            number1 = num1[ptr1] - '0';
        } 
        
        if (0 <= ptr2 && ptr2 < num2.size()) {
            number2 = num2[ptr2] - '0';
        }
        
        int res = number1 + number2 + add;
        add = res / 10;
        
        return to_string(res % 10);
    }
    
    
    string addStrings(string num1, string num2) {
        if (num1.empty()) {
            return num2;
        }  else if (num2.empty()) {
            return num1;
        }
        
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;
        int add = 0;
        string sum = "";
        
        while (ptr1 >= 0 || ptr2 >= 0 || add > 0) {
            sum = addChar(num1, ptr1, num2, ptr2, add) + sum;
            ptr1--;
            ptr2--;
        }
        
        return sum;
    }
};
