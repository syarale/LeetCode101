
// 168. Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";
        if (columnNumber <= 0) {
            return title;
        }
        
        int curr = columnNumber;
        while (curr > 0) {
            int pos = curr % 26;
            if (pos == 0) {
                title = "Z" + title;
                curr = curr / 26 - 1;
            } else {
                title = char('A' + pos - 1) + title;
                curr /= 26;
            }
        }
        
        return title;
    }
}; 
