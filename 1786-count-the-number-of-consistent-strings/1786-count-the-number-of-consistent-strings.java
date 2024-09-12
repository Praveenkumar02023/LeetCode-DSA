class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        
        HashMap<Character,Boolean> mp = new HashMap <>();

        for(char ch : allowed.toCharArray()){
            mp.put(ch,true);
        }

        int cnt = 0;
        for(String s : words){
            boolean flag = true;
            for(char c : s.toCharArray()){

                if(!mp.containsKey(c)) {
                    flag = false;
                    break;
                }
            }

            if(flag) cnt += 1;
        }


        return cnt;

    }
}