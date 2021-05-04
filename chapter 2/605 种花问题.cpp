// 605: 种花问题

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int>& flowerbed, int i) {
        int len = flowerbed.size();
        
        // assert(!flowerbed.empty() || i >= 0);
        
        if (i >= len || flowerbed[i] != 0) {
            return false;
        }
        
        if ((i - 1 < 0 || flowerbed[i - 1] == 0) &&
            (i + 1 == len || flowerbed[i + 1] == 0)) {
            
            return true;
        }
        
        return false;     
    }
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int maxNum = 0;
        
        if (n == 0) {
            return true;
        } 
        
        if (flowerbed.empty()) {
            return false;
        }
        
        for (int i = 0; i < len; i++) {
            if (canPlace(flowerbed, i)) {
                maxNum++;
                flowerbed[i] = 1;
            }
        }
        
        if (n <= maxNum) {
            return true;
        } else {
            return false;
        }

    }
}; 



//int main()
//{
//    int arr[7] = {1,0,0,0,1,0,0};
//    vector<int> flowerbed(arr, arr + 7);
//    int n = 2;
//    
//    Solution sol;
//    
//
//    
//    if (sol.canPlaceFlowers(flowerbed, n)) {
//        cout<<"true";
//    } else {
//        cout<<"false";
//    }
//    
//    cout<<endl;
//    for (int i = 0; i < 7; i++) {
//        cout<<flowerbed[i]<<" ";
//    }
//    
//    return 0;
//}



