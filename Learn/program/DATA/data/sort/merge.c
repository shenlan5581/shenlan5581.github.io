/*
    归并排序
 二分数组  合并
 9 5 2 8 6 3 4 1 7
 合并
 ((9 5) 2)  (8 6) (3 4)(1 7)
 (5 9 2) (8 6) (3 4) (1 7)
 (2 5 9) (6 8) (3 4) (1 7)
 (2 5 6 8 9) (1 3 4 7)
(注意合并方法） 
 比较两个数将较小的放入临时数组 移动取出数组的下标 较大的下标不变
 (2 5 6 8 9) (1 3 4 7)
 1  (2 5 6 8 9) (3 4 7)
 12  (5 6 8 9) (3 4 7)
 123  (5 6 8 9) (4 7)
 1234  (5 6 8 9) (7)
 12345  (6 8 9) (7)
 123456  ( 8 9) (7)
 1234567  ( 8 9) ()
 123456789  () ()
 (只有被取出的数组 下标移动 教大的数组下标不变） 
二分数组
总结 
  运行时间是O(N log N) 
  需要占用多一个的存储空间
  并且有复制开销
  所以速度被放慢
  (拷贝可以被避免）
*/
#include <stdio.h>
#include <string.h>
void merge(int A[],int tmparray[],int Lp,int Rp,int R_end) {
     int tmp = Lp;
     int L_end = Rp-1;
     int elements = R_end - Lp +1; //个数
     int i=0;

   printf("合并数组:%d-%d:%d-%d\n",Lp,L_end,Rp,R_end);  //test

   while(Lp <= L_end && Rp <= R_end) //两个数组可能元素个数不一样 比较相同长度的元素
   if(A[Lp]<=A[Rp])                  //(重点）
      tmparray[tmp++] = A[Lp++];
   else
      tmparray[tmp++] = A[Rp++];     

   while(Lp <= L_end)                //如果数组元素不一样复制最后一个元素
      tmparray[tmp++]= A[Lp++];
   while(Rp <= R_end)                //如果数组元素不一样复制最后一个元素
      tmparray[tmp++]= A[Rp++];   

   for(i = 0;i< elements;i++,R_end--) //将排好序的元素拷贝回去
      A[R_end] = tmparray[R_end];

//test
   for(i=0;i<9;i++)
   printf("%d",A[i]);
   printf("\n");
}
void msort(int* A,int* tmparray,int left,int right) {   //left right center 均为下标值
        int center;                                     //二分数组 消除余数 个数奇数均分 偶数 靠后一位 最终总是被均分
 static int count;
 if(left < right) {
   count++;    //test
   center =(left+right)/2;
   printf("二分数组(%d)  %d-%d:%d-%d\n",count ,left,center,center+1,right);   //test
   msort(A,tmparray,left,center);
   msort(A,tmparray,center+1,right);
   merge(A,tmparray,left,center+1,right);
 } 
}
int main() {
printf("9 5 2 8 6 3 4 1 7\n");
printf("0 1 2 3 4 5 6 7 8\n");
int a[] = {9,5,2,8,6,3,4,1,7};
int tmp[9];
memset(tmp,0,36);
msort(a,tmp,0,8);  // (8-1 是为下标）
   int i;
   for(i=0;i<9;i++) {
   printf("%d ",a[i]);
   //printf("%d ",tmp[i]);   //顺序一致
}
   printf("\n");
}
