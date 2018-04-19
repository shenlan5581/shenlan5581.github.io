/*
  插入排序
       6 7 9 2 5 3
过程
       6(7)9 2 5 3  
       6 7(9)2 5 3
       6 7 9(2)5 3
             <
       2 6 7 9(5)3
               <
       2 5 6 7 9(3)
                 <
       2 3 5 6 7 9    finish 
循环1  取出一个数(遍历数组）
    循环2   如果前面的比它大 把前面的数依次后移

算法分析
     O(n平方)
对于输入数据  乱序的越多 速度越慢 反之越快
并且差异很大

*/
#include <stdio.h>
#include <string.h>
void display(int *A,int nums) {
 int i = 0;
 for(i ;i<nums;i++)
  printf("%d-",A[i]);
  printf("\n");
   
}
      2      3      4     5  ... ... 
      |
      |
      |
   +-----+
   |_____|  ... ... 
   2 ....8  





void insert(int * A,int n) {
 int j,i;
 int key;
 for(j=1;p<nums;p++) {   2->8
    key = A[p];           
    i = j-1   
    while( i>0&&A[i]>key) {  2->8 = 2+3+4+5+6+7+8
       A[i+1] = A[i];       
       i=i-1;
    }
    A[i+1] = key;
 }
}
int main() {
 int arr[9] ={6,7,9,2,8,4,1,5,3};
 int nums =9 ;
 insert(arr,nums);
 display(arr,nums);
return 0;
}
