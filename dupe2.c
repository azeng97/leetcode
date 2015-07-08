//returns whether array contains nearby duplicates
//by Avan

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int x = 0;
    int y = 1;
    while (x<numsSize){
    	while (y<numsSize){
    		if (nums[x]==nums[y] && abs(x-y)<=k){
    			return true;
    		} else {
    			y++;
    		}
    	}
    	x++;
    	y = x+1;
    }
    return false;
}