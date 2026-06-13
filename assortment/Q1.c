#include<stdio.h>

int main(){
   int n;

   printf("enter the array's size:");
   scanf("%d",&n);
   
   int a[n];

   for (int i = 0; i < n; i++)
   {
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
   }
    
    printf("the negative element from array:");

   for(int j=0; j<=n; j++)
   {
        if(a[j] < 0){
        printf("%d ", a[j]);

        }
   }
}