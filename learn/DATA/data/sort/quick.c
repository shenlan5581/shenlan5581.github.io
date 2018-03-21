/*
快排
枢纽员的取值 是为关键点

对于一个数组
找到一个中间值（关键）
小于该值放左边大于该值放右边
然后再递归两边
对于数组元素小于 指定数  的数组 直接用插入排序

2 8 6 7 4 9 3 1 5
*/
#include <stdio.h>
 void display(int * a,int len) {
  int i;
  for(i=0;i<len;i++) {
    printf("%d",a[i]);
  }
  printf("\n");
 }

void Swap(int * a,int * b) {  
    int swp=*a;
     *a=*b;
     *b=swp;
}
void insertion(int *A,int nums){
 int j,p;
 int tmp;
 for(p=1;p<nums;p++) {
    tmp = A[p];                     //取出一个数
    for( j = p;j>0&&A[j-1]>tmp;j--) //判断
       A[j] = A[j-1];               //依次后移动前面大于tmp的数
    A[j] = tmp;
     }
}
/*
2 8 6 7 4 9 3 1 5
^       ^       ^
2 8 6 7 4 9 3 1 5
^       ^       ^
2 8 6 7 1 9 3 4 5
              ^
            枢纽元
*/
//中值分割
//找出一个 中间数 放到right-1 的位置
int median3(int a[],int left,int right) {

  int center = (left+right)/2;
  
  if(a[left] > a[center])
    Swap(&a[left],&a[center]);
  if(a[left] > a[right])
    Swap(&a[left],&a[right]);
  if(a[center] > a[right])
    Swap(&a[center],&a[right]);

    Swap(&a[center],&a[right-1]);
    return a[right-1];
}

/*

2 8 6 7 1 9 3 4 5   pivot = 4
i>>         <<j
2 8 6 7 1 9 3 4 5   //找到位置
  i         j           
2 3 6 7 1 9 8 4 5   // 交换
  i         j           
2 3 6 7 1 9 8 4 5   // 找到位置
    i   j           
2 3 1 7 6 9 8 4 5   // 交换
    i   j           
2 3 1 7 6 9 8 4 5   // i=>j终止 
    j i           
2 3 1 4 6 9 8 7 5   // swap a[i] a[right-1] 把中值放到中间i 的位置 
      i     (r-1)   

(2 3 1 )   4   (6 9 8 7 5)  (注意此时 i不再参与计算)
   递归           递归
      
*/
#define cutoff 3  //对于小于3的数组直接用插入排序
// 核心 
void quick(int a[],int left,int right) {
  int i,j;  
  int pivot;
  if(left+cutoff <= right) {  // 计算数组长度如果小于使用其他算法
    pivot = median3(a,left,right);
    i = left; j=right-1;//i = 左下标 j =（找到的中值）
    display(a,9); //test
    for( ; ;) {
       while( a[++i] < pivot){ }; //找到比 pivot 大的数  (最两边的值并未参与比较)
       while( a[--j] > pivot){ }; //找到比 pivot 小的数
        printf("kk:%d\n",j);
       if(i < j)                   //未相交
         Swap(&a[i],&a[j]);         //交换值
         else
         break;                     //中止时 左边的小于中值 右边的大于中值
    } 
    Swap(&a[i],&a[right-1]);       // ...<i<... 位置i 从新放回中值  (因为是基于该数值比较的，所以该数值位置此时确定）
    display(a,9); //test
    quick(a,left,i-1);
    quick(a,i+1,right);
  }else{
    insertion(a+left,right-left+1);
  }
 }

int main() {
 int a[] = {2, 8, 6, 7, 4, 9, 3, 1, 5};
 display(a,9);
 quick(a,0,8);
 display(a,9);
  
}




