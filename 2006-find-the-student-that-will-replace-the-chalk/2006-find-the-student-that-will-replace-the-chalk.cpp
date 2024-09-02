class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
         long long n = chalk.size();
        cout<<n<<endl;
        long long total = 0;

        for(auto x : chalk){
            total += x;
        }

        k = k % total;
        cout<<k<<endl;
        if(k == 0){
            return 0;
        }

         long long res ;
        for( long long i = 0 ; i < n ; i++){

            k = k - chalk[i];
            if(k < 0){
                res = i;
                break;
            }

        }

        return res;


    }
};