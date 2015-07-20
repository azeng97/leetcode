void rotate(int* nums, int numsSize, int k) {
	int* copy[numsSize];
	int x = 0;
	while (x<numsSize){
		copy[x]=nums[x];
		x++;
	}
	x = 0;
	while (x<numsSize){
		nums[(x+k)%numsSize]=copy[x];
		x++;
	}
}

