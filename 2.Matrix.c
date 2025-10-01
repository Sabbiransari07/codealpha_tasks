#include<stdio.h>
int main(){
   int m, n;
   printf("Enter number of rows and columns: ");
   scanf("%d %d", &m, &n);

   int a[m][n], b[m][n], sum[m][n];

   printf("Enter elements of first matrix:\n");    // Input first matrix
   for (int i = 0; i < m; i++) 
   {
      for (int j = 0; j < n; j++) 
      {
         scanf("%d", &a[i][j]);
      }
   } 
   printf("Enter elements of second matrix:\n");    // Input second matrix
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         scanf("%d", &b[i][j]);
      }
   }
   for (int i = 0; i < m; i++)     // Add the matrices 
   {    
      for (int j = 0; j < n; j++)
      {
          sum[i][j] = a[i][j] + b[i][j];
      }
   }
   printf("Resultant Matrix (Sum):\n");     // Print the result
   for (int i = 0; i < m; i++) 
   {
      for (int j = 0; j < n; j++)
      {
         printf("%d\t", sum[i][j]);
      }
      printf("\n");
   }
return 0;
}