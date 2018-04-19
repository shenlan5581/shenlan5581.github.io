/*  堆排序 */


#include "k.h"

#define leftchild(i)  (2*(i)+1) 

 int percdown(int *a,int i,int n){                     //此函数 将数组 a  从i位置开始 与 i*2+1的位置 比较如果i 位置值较小 则交换 位置                
           int child;                                  //构建max 堆
           int tmp;                                
       for(tmp = a[i];leftchild(i)<n;i=child)
       {   echo_array(a,n,1);
           child = leftchild(i);              
           if(child!= n-1&&a[child +1]>a[child])
           child ++;
           if(tmp<a[child])
            a[i] = a[child];
            else
             break;
       }
     a[i] =tmp;
 }
 void swap(int *a,int *b)
 {
        int tmp = *a;
        *a= *b;
        *b = tmp;
 }
int heapsort(int *a,int n)   //构建堆
{     
     
    int i;
    for( i =n/2;i>=0;i--)     //从2分之1 处开始递减
       percdown(a,i,n);

       echo_array(a,10,1);
      for(i =n-1;i>0;i--)   //从最后一个元素开始
    {    
          couts("swap  ");
          swap(&a[0],&a[i]);  //交换第一个元素 和最后一个
          echo_array(a,10,1);
          
          
          percdown(a,0,i);    // 将堆最大元素 放入尾部  对堆从新排序
          couts("sort  ");
           echo_array(a,10,1);
    }


}
 

int main()
{
    int  a[10] = {0,1,2,3,4,5,6,7,8,9};
   /* echo_array(a,10,1);
    heapsort( a,10) ;
    echo_array(a,10,1);*/

   int  i;
   for(i=0;i<10/2;i++)
     percdown(a,i,10);
     echo_array(a,10,1);
    // for(i=10/2;i>=0;i--)
    // percdown(a,i,10);
    // echo_array(a,10,1);

}