//returns whether array contains duplicates
//by Avan

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    int x = 0;
    int y = 1;
    while (x<numsSize){
    	while (y<numsSize){
    		if (x==y){
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