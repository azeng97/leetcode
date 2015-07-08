//two sum: find index of 2 numbers in array which add up to target
//by Avan

int* twoSum(int* nums, int numsSize, int target) {
    int result[2];
    int x = 0;
    int y = 1;
    while (x<numsSize){
    	while (y<numsSize){
    		if (nums[x]+nums[y]==target){
    			result[0]=x;
    			result[1]=y;
    			return result;
    		} else {
    			y++;
    		}
    	}
    	x++;
    	y = x+1;
    }
}