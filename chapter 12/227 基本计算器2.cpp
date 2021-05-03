
// 227. Basic Calculator II 

class Solution {
private:
    stack<long> number;

public:
    long calNumber(long x, long y, char op) {
        switch(op) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            default:
                return INT_MIN; // throw error;
        }
    }

    long getNumber(string s, int pos, int& end) {
        // assert(begin >= 0);
        int len = s.size();
        while (pos < len && s[pos] == ' ') {
            pos++;
        } 

        long val = 0; 
        while (pos < len && '0' <= s[pos] && s[pos] <= '9') {
            val = val * 10 + (s[pos] - '0');
            pos++;
        }
        end = pos;
        return val;
    }

    int calculate(string s) {
        if (s.empty()) {
            // throw error
            return INT_MIN;
        }

        int i = 0; 
        int len = s.size();
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }

            if ('0' <= s[i] && s[i] <= '9') {
                int j = -1;
                int pos = i;

                // long val = getNumber(s, i, j);         // call function may over time limit
                while (pos < len && s[pos] == ' ') {
                    pos++;
                } 

                long val = 0; 
                while (pos < len && '0' <= s[pos] && s[pos] <= '9') {
                    val = val * 10 + (s[pos] - '0');
                    pos++;
                }
                
                number.push(val);
                i = pos;
                continue;
            }

            if (s[i] == '+' || s[i] == '-') {
                int j = -1;
                // long val = getNumber(s, i + 1, j);
                int pos = i + 1;
                while (pos < len && s[pos] == ' ') {
                    pos++;
                } 

                long val = 0; 
                while (pos < len && '0' <= s[pos] && s[pos] <= '9') {
                    val = val * 10 + (s[pos] - '0');
                    pos++;
                }

                if (s[i] == '-') {
                    number.push(-val);
                } else {
                    number.push(val);
                }
                i = pos;
                continue;
            }

            if (s[i] == '*' || s[i] == '/') {
                // assert(!number.empty() && i < len - 1);
                char op = s[i];
                long x = number.top();
                number.pop();

                int j = -1;
                // long y = getNumber(s, i + 1, j);
                int pos = i + 1;
                while (pos < len && s[pos] == ' ') {
                    pos++;
                } 

                long val = 0; 
                while (pos < len && '0' <= s[pos] && s[pos] <= '9') {
                    val = val * 10 + (s[pos] - '0');
                    pos++;
                }
                i = pos;

                int y = val;

                long k = calNumber(x, y, op);
                number.push(k);
                continue;
            }

            // assert not happend
            i++;
        }

        long sum = 0;
        while (!number.empty()) {
            sum += number.top();
            number.pop();
        }

        return sum;
    }
};
