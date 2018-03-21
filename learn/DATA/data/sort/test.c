
#include <stdio.h>



// 5 3 4 6 9 7 8 2 1
//默写成功
void display(int *a,int len){
 int i ;
 for(i=0;i<len;++i) 
    printf("%d",a[i]);  
    printf("\n");  
}

void insert(int *a, int nums) {
  int tmp;
  int i,j;
  for(i=1;i<nums;i++) {
     tmp = a[i];         //取出一个数
     for(j=i;j>0;j--)    //找到前一个数 
     if(tmp<a[j-1])      //如果比它大把前一个挪到现在位置 
       a[j]=a[j-1];
     else                //或则退出循环
       break;
     a[j]=tmp;           //把取出的数插入到前面的j位置
  }
}
/*（注意点）##只有移动了a[j-1] j才自减1
     5  9  3
           j

     for(j=i;j>0;j--)    
     if(tmp<a[j-1])      //##只有移动了a[j-1] j才自减1
       a[j]=a[j-1];      
     else                //此时j值不变等于上次循环的位置
       break;
     a[j]=tmp;         

 如果 < 条件成立 
 移动前一个 j-1
 否则       j不变
 退出
 j值要么移动了j-1
 j要么没移动j还是原来的位置

                     j值不变
         -------------------------------------------
         |                                          v
 ----->进入循环------->是否小-------j值不变------>a[j]= tmp
  ^                       |
  |____ 移动j______________ 
            j-1

    for(j = p;j>0&&A[j-1]>tmp;j--)  //更直观一些？？
       A[j] = A[j-1];               //依次后移动前面大于tmp的数
    A[j] = tmp;
                         
*/
//默写成功（调试了）
void shell(int *a,int nums) {
     int inc =(nums-1)/2;
     int i,j;
     for(inc;inc>0;inc/=2) {
        for(i=inc;i<nums;i++){
           int tmp = a[i];
           for(j=i;j>inc;j-=inc) { //(这部分就是个插入排序)
              if(tmp<a[j-inc])
                 a[j] = a[j-inc];
                 else
                 break;
            }
            a[j]=tmp;
         }       
      }
}
void swap(int * a,int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}

int  median(int *a,int left,int right) {
     int center = (right-left)/2;
     if(a[right]<a[left]);
        swap(&a[right],&a[left]);
     if(a[right]<a[center])
        swap(&a[right],&a[center]);
     if(a[center]<a[left])
        swap(&a[center],&a[left]);
  
        
        swap(&a[center],&a[right-1]);  // 把中值移动了一下
  return a[right-1];
}

//成功默写
void quick(int *a,int left, int right) {
     
     if(right-left>3) {
       int i=left;
       int j=right;
       int pivot = median(a,left,right);  //##（中值不能为最大数也不能为最小数） 
       while(1) {
           while(a[++i]<pivot){};
           while(a[--j]>pivot){};
         if(i<j)
           swap(&a[i],&a[j]);           //交换两边
         else
           break;
        }
          swap(&a[i],&a[right-1]);  //把中值放到i的位置  恢复原本位置
          quick(a,left,i-1);
          quick(a,i+1,right);    
     } else {
          insert(&a[left],(right-left)+1);   //插入排序
     } 
}

void Merge(int *a,int * array ,int lpos,int rpos ,int rend) {
       int elements = rend-lpos+1;
       int tmp = lpos;
       int lend = rpos-1;
       while(lpos<=lend&&rpos<=rend) 
            if(a[lpos]<a[rpos])
              array[tmp++] = a[lpos++]; 
            else
              array[tmp++] = a[rpos++];
        
        while(lpos<=lend)
             array[tmp++] = a[lpos++];
        while(rpos<=rend)
             array[tmp++] = a[rpos++];   //注意此处 tmp 及 rpos 在循环退出时其值已经越界
        int i;                           //计算的数值都是 下标 
        for(i=0;i<elements;i++,rend--)
          a[rend] = array[rend];
}

int array[9] = {0,0,0,0,0,0,0,0,0};
void merge(int *a,int *array,int left,int right){
  if(left<right) {
     int center = (left+right)/2;
         merge(a,array,left,center);
         merge(a,array,center+1,right);
         Merge(a,array,left,center+1,right);        
  }
}

int A[] = {5,3,4,6,9,7,8,2,1};


int main() {
display(A,9);
merge(A,array,0,8);
display(A,9);


}
