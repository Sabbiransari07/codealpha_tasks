#include<stdio.h>
#include<stdlib.h>
int main(){
   int a, b, c;
   int ch;
   printf("Calculator in  C Language:\n");
   printf("1.Addition\n2.Subtration\n3.Multiplication\n4.Division\n");
   printf("Enter your 1st number:");
   scanf("%d",&a);
   printf("Enter your 2st number:");
   scanf("%d",&b);
while (1)
{
   printf("Enter your choice:");
   scanf("%d", &ch);
   switch(ch)
   {
    case 1:
        c = a + b;
        printf("Sum is :%d\n", c);
        break;
    case 2:
          c = a - b;
        printf("Difference is :%d\n", c);
        break;
    case 3:
        c = a * b;
        printf("Multiplication is :%d\n", c);
        break;
    case 4:
        if(b!=0)
        {
          c = a / b;
          printf("Division is :%d\n", c);
        }
        else{
            printf("Division is not allowed by Zero\n");
        }
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("Enter a valid Choice!\n");
        
   }
}
return 0;
}