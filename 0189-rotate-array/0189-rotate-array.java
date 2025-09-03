class Solution {
    public void rotate(int[] nums, int k) {
        int n=nums.length;
        k%=n;
        helper(nums,0,n-k-1);
        helper(nums,n-k,n-1);
        helper(nums,0,n-1);
    }
    static void helper(int[] nums,int left,int right){
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }
    }
}