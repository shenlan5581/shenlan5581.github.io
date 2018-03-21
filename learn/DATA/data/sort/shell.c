/*
  希尔排序
               分组
                |
1     9 8 7 6 5 4 3 2 1 0
        |_________|          增量为2分之1  且递减之前的一半
          |_________|          

          分组
          |
2     9 8 7 6 5 4 3 2 1 0
      |_____|                增量为2分之1  且递减之前的一半
        |_____|          

               分组
                |
3     9 8 7 6 5 4 3 2 1 0
              |_|            增量为2分之1  且递减之前的一半
                |_|          
思路：
设定增量 并去逐渐递减
从增量处向后移动
依次与增量前一个对应位置比较
如果当前值小就插入到前面

*/
#include <stdio.h>
void sort_echo(int *a,int len,int x,int y);
void is(int * a,int n) {
    int i,j,inc;
    int tmp;
/*1*/  for(inc = n/2;inc>0;inc/=2) {                       //1每次定位到 元素总数的二分之一处 
            //  printf("------inc=%d\n", inc);
/*2*/     for(i = inc;i<n;i++)       //2 在此处 i = n/2 开始 往后循环 直到    i <总数
               {   // printf("  2{------i=%d; tmp=%d\n",i,a[i]); 
                    tmp = a[i];          // 设置临时变量  tmp  其在第二层循环开始 每次加1
/*3*/          for( j = i;j>=inc;j-=inc)   // 
                  {                       
                    // printf("    3{------j=%d; j-inc=%d\n",j,j-inc);
                    sort_echo(a,10,tmp,a[j-inc]);
                     // printf("******   %d < %d   ******\n",tmp,a[j-inc]);
                      if(tmp<a[j-inc])     //j-inc  0～inc前面的下标     
                        {                  //tmp 跟inc前面的元素比较
                           a[j] = a[j-inc]; //tmp当前位置 = 
                        }
                      else 
                         break;             
/*3*/             }
                         a[j] = tmp; //此时 j 有两个值：1是循环条件不成立j=j-inc  2 break退出 j 为 tmp位置
                       //  couts(" ------3}\n");
                        // couts(" --------2}\n");
/*2*/          }
                     //    couts(" ----------1}\n");
                    //  echo_array(a,10,1);
/*1*/  }
}

void k1(int *a,int n) {
    int inc,i,j;
    int  tmp;
    for(inc = n/2;inc>0;inc/=2) {
       for(i=inc;i<n;i++) {
          tmp = a[i];
          if( tmp<a[i-inc]) {
            sort_echo(a,10, tmp,a[i-inc] );
            printf("******   %d < %d   ******\n",tmp,a[i-inc]);
            a[i]=a[i-inc];
            a[i-inc]=tmp;
            } 
       }
    }
    for(i = 1;i<n;i++) {
       tmp = a[i];
       if(a[i]<a[i-1]) {
         a[i] = a[i-1]; 
         a[i-1] =tmp;         
       }
    }
}

void k2(int *a,int n) {
     int inc,i,j;
     int  tmp;
    for(inc = n/2;inc>0;inc/=2) {
       for(i=inc;i<n;i++) {
          tmp = a[i];
          for(j=i;j>=inc;j-=inc) {                   //j位置在 i  i-=inc
                sort_echo(a,10, tmp,a[j-inc] );
                printf("******   %d < %d   ******\n",tmp,a[j-inc]);
                  if(tmp<a[j-inc])
 // 此处的逻辑是 每次减去一个inc的位置 如果tmp 小于前一个位置 则后移前一个元素 
 // 最终把 tmp 查入到前面去 否则 a[j]的位置（被后移动的元素位置）= tmp
                  a[j] = a[j-inc];//后移前一个元素
                  else
                  break;
           } 
              a[j]= tmp; //(注意此值是个坑它在break退出时值为j  循环不成立退出时 为 j-=jnc
        }     //插入tmp
        printf("-----------------------------\n");
    }
}
int main() {
 int arr[10] ={9,8,7,6,5,4,3,2,1,0};
 int num = 10;
   k1(arr,num);
   k2(arr,num);
}
void sort_echo(int *a,int len,int x,int y){
    int i,j ;
    for(j =0;j<2;j++) {
         for(i = 0;i<len;i++) {
            if(j ==0)
             printf(" %d ",a[i]);
            if(j ==1) {
                if(a[i]==x||a[i]==y)
                printf(" * ");
                else
                printf("   ");
            }
         }
       printf("\n" ); 
    }
}
