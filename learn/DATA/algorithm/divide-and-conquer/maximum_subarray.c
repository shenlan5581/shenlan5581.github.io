/*  算导第四章
#[分治]
最大子数组问题(股票买进卖出问题，最大化收益）

求一组数中间差值最大的一组

*/
  
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int A[] = {8,1,3,7,4,9,5,2,6};
   
//暴力比较
void * findmaxA(int * a,int nums) {
int max=0;          //记录最大差值
int f,r;            //记录下表位置
int i,j;            
for(i =1;i<nums;i++) {
 int tmp=a[i];
    for(j=i;j<nums;j++) {
       if((a[j]-tmp)>max) {
         max=a[j]-tmp;         //保存最大值
         f=i;                  //记录下标
         r=j;
       }
    }
}
printf("%d %d\n",f,r);
void *x=malloc(8);
memcpy(x,&f,4);
memcpy(x+4,&r,4);
return x;
}
/* 分治
分解为子数组
找出最大差

核心思路：
将一个数组二分 

   1 -2 -4 7 -5 4 3 -4 
1 找到左边的最大和
2 找到右边的最大和
3 找到跨越中点的最大和（此处仍不太明白）
（    所加最大和  <-  中点 ->   所加的最大数   )
4 比较中三者最大者 返回给上层4 




*/
int AA[] = {1,-2,-4,7,-5,4,3,-4};//转换为求最大的和（转换）

void cross(int *a,int low,int mid,int high,int *left,int *right,int *S){
int left_sum =-1000,right_sum=-1000;
int sum = 0;
int i,j;
int max_left,max_right;
    for(i=mid;i>=low;i--) {
       sum+=a[i];
       if(sum>left_sum) {
          left_sum=sum;
          max_left=i;
       }
    }
    sum = 0;
    for(j=mid+1;j<=high;j++) {
       sum+=a[j];
       if(sum>right_sum) {
          right_sum=sum;
          max_right=j;
       }
    }
*left = max_left;
*right =max_right ;
*S = right_sum + left_sum;
}
void maximum(int *a,int low,int hight,int* left,int* right,int* Sum) {
     if(hight== low) {
       *left = low;*right = hight;*Sum= a[low];
     } else {
            int mid = (low+hight)/2;
            printf("%d\n",mid);
            int left_low,left_hight,left_sum;    
            maximum(a,low,mid,&left_low,&left_hight,&left_sum);
            int right_low,right_hight,right_sum;    
            maximum(a,mid+1,hight,&right_low,&right_hight,&right_sum);
            int cross_low,cross_hight,cross_sum;    
            cross(a,low,mid,hight,&cross_low,&cross_hight,&cross_sum);
  
            if(left_sum >= right_sum&&left_sum >= cross_sum) {
              *left = left_low;*right = left_hight;*Sum=left_sum;
            } else if(right_sum >= left_sum&&right_sum >= cross_sum) {
                     *left=right_low;*right = right_low;*Sum=right_sum;
                   } else {
                         *left = cross_low;*right = cross_hight;*Sum=cross_sum;
                   }
    }
} 

int main() {
void * ret = findmaxA(A,9);
printf("%d,%d\n",*(int*)ret,*(int*)(ret+4));
free(ret);
int left,right,sum;
maximum(AA,0,7,&left,&right,&sum);
printf("%d %d %d",left,right,sum);



}
