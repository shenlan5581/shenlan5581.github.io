/*
*   插入排序
*/

#include "k.h"

void is(int * a,int n)
{   
     int j,p;
     int tmp;
     for(p =1 ;p<n;p++)
     {   echo_array(a ,10,1);
         tmp = a[p];
        for( j = p;j>0&&a[j-1]>tmp;j--)
          a[j] = a[j-1];

          a[j] = tmp;
     }
}



int main()
{
 int arr[10] ={9,8,7,6,5,4,3,2,1,0};
 int num = 10;
  // echo_array(arr,10,1);
   is(arr,num);
 echo_array(arr,10,1);


}