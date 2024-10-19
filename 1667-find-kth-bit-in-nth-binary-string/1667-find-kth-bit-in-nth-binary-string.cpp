class Solution {
public:
    string findComplement(const std::string &binary) {
    string complement = binary;
    for (char &bit : complement) {
        bit = (bit == '0') ? '1' : '0';
    }
    return complement;
}
    char findKthBit(int n, int k) {

        string s = "0";
        for(int i = 2 ; i <= n ; i++){

            string temp = findComplement(s);
            reverse(temp.begin(),temp.end());
            s += '1' + temp;
        }

        return s[k-1];
    }
};