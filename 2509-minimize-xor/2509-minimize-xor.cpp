
class Solution {
public:
   
    pair<string, int> intToBinaryStringAndCount(int num) {
        if (num == 0) return {"0", 0};  
        string binaryStr = "";
        int setBitCount = 0;
        
        while (num > 0) {
            if (num % 2 == 1) setBitCount++;
            binaryStr = (num % 2 == 0 ? "0" : "1") + binaryStr;  
            num /= 2;
        }
        
        return {binaryStr, setBitCount};
    }

    long long binaryStringToInt(const std::string &binaryStr) {
        long long result = 0;
        for (char ch : binaryStr) {
            result = result * 2 + (ch - '0'); 
        }
        return result;
    }

    int minimizeXor(int num1, int num2) {
      
        auto binAndCnt1 = intToBinaryStringAndCount(num1);
        auto binAndCnt2 = intToBinaryStringAndCount(num2);

        int setBitIn2 = binAndCnt2.second;
        int setBitIn1 = binAndCnt1.second;

        if (setBitIn2 == setBitIn1) return num1;

        string ansNumBin = "";
        string num1Bin = binAndCnt1.first;

        bool flag = true;

        if(setBitIn1 > setBitIn2) flag = false;

        for (auto ch : num1Bin) {
                if (ch != '0') {
                    if (setBitIn2 > 0) {
                        ansNumBin.push_back('1');
                        setBitIn2--;
                    } else {
                        ansNumBin.push_back('0');
                    }
                } else {
                    ansNumBin.push_back('0');
                }
            }


        if (flag) {

            int k = ansNumBin.size() - 1;
            while (k >= 0 && setBitIn2 > 0) {
                if (ansNumBin[k] != '1') {
                    ansNumBin[k] = '1';
                    setBitIn2--;
                }
                k--;
            }

            while (setBitIn2-- > 0) {
                ansNumBin.push_back('1');
            }
        }

       
        return binaryStringToInt(ansNumBin);
    }
};
