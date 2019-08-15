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

void insert(int * A,int nums) {
 int j,p;
 int tmp;
 for(p=1;p<nums;p++) {
    tmp = A[p];                     //取出一个数
    display(A,nums);
    for( j = p;j>0&&A[j-1]>tmp;j--) //判断
       A[j] = A[j-1];               //依次后移动前面大于tmp的数
    A[j] = tmp;
     }
}
int main() {
 int arr[6] ={6,7,9,2,5,3};
 int nums =6 ;
 insert(arr,nums);
 display(arr,nums);
return 0;
}
