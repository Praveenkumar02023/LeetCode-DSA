class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int diff = Integer.MAX_VALUE;
        int n = nums.length;
        int res = -1;
        Arrays.sort(nums);

        for(int i = 0 ; i < n ; i++){

            // if(i > 0 && nums[i-1] == nums[i]) continue;

            int left = i + 1 , right = n-1;
            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];
                int curDiff = Math.abs(target-sum);
                if(curDiff == 0) return target; 
                if(curDiff < diff){
                    res = sum;
                    diff = curDiff;
                    // while(left < n-1 && nums[left] == nums[left + 1]){
                    //     left++;
                    // }
                    // while(right > 0 && nums[right-1] == nums[right]){
                    //     right--;
                    // }
                    // left++;
                    // right--;
                }else if(sum > target){
                    right--;
                }
                else left++;

                //   while (left < right && nums[left] == nums[left + 1]) left++;
                // // Skip duplicate elements for the right pointer
                // while (left < right && nums[right] == nums[right - 1]) right--;
                

            }

        }
    return res;
    }
}