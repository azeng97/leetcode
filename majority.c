int majorityElement(int* nums, int numsSize) {
	int x = 0;
	int y = 1;
	int counter = 1;
	while (x<numsSize){
		while(y<numsSize){
			if(nums[y]==nums[x]){
				counter++;
			}
			y++;
		}
		if (counter>numsSize/2){
			return nums[x];
		} else {
			while (nums[x]==nums[x+1]){
			    x++;
			}
			x++;
			y = x+1;
		}
	}    
}