//two sum: find index of 2 numbers in array which add up to target
//by Avan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target);
void sort(int *nums, int first, int last);
int search (int value, int* nums, int numsSize, int start);
int main(){
  int x[20],size,i,n;

  printf("Enter size of the array: ");
  scanf("%d",&size);

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&x[i]);

  printf("Enter target number: ");
  scanf("%d",&n);

  twoSum(x,size,n);

  printf("Sorted elements: ");
  for(i=0;i<size;i++)
    printf(" %d",x[i]);
    printf ("\n");



  return 0;
}

int* twoSum(int* nums, int numsSize, int target) {
    int* result = malloc(2*sizeof(int));
    int x = 0;
    int y = numsSize-1;
    int copy[numsSize];
    int n = 0;
    while (n<numsSize){
        copy[n] = nums[n];
        n++;
    }
    sort(nums, 0, numsSize-1);
    while (x<numsSize){
        if (nums[x]+nums[y]==target){
            result[0]=search(nums[x],copy,numsSize,0)+1;
            result[1]=search(nums[y],copy,numsSize,0)+1;
            if (result[0]==result[1]){
                result [1]= search(nums[y],copy,numsSize,result[0])+1;
            }
            if (result[1]<result[0]){
                int temp = result[0];
                result[0]=result[1];
                result[1]=temp;
            }
            printf ("numbers are: %d %d indexes: %d %d original: %d %d\n",nums[x],nums[y],x,y,result[0],result[1]);
            return result;
        } else if (nums[x]+nums[y]>target){
            y--;
        } else {
            x++;
        }
    }  
}

void sort(int *nums, int first, int last){
    int pivot, x, y, temp;
    if (first<last){
        pivot = first;
        x = first;
        y = last;
        while (x<y){
            while(nums[x]<=nums[pivot] && x<last){
                x++;
            }
            while (nums[y]>nums[pivot]){
                y--;
            }
            if (x<y){
                temp = nums[x];
                nums[x] = nums[y];
                nums[y] = temp;
            }
        }
        temp = nums[pivot];
        nums[pivot] = nums[y];
        nums[y] = temp;
        sort(nums,first,y-1);
        sort(nums,y+1,last);
    }
}

int search (int value, int* nums, int numsSize, int start){
    int x = start;
    while (x<numsSize){
        if (nums[x]==value){
            printf("index is :%d\n",x);
            return x;
        }
        x++;
    }
}