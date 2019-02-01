//Sam Dressler 
#include <stdio.h>
void printTable(float r, float B, float P){
int month = 1;
float totalInterest=0;
float I0= 0 ;//I0 is the interest due after the first month 
while(B >= 0){    
        I0 = ((r/12)*B);    
        printf("%d %.2f %.2f\n",month,I0,B);
        B = (B + I0)-P; // second interest equation but rearanged 
        totalInterest+= I0;    
        month++; 
}
I0 = ((r/12)*B);
printf("%d %.2f %.2f\n\n",month,I0,B);
printf("total interest paid: %.2f\n", totalInterest);
return;
}

int main(void){
    float r = 0.25;     //anual interest rate
    float B = 2000.0;   //amount borrowed
    float P = 0;          //monthly payment (amount chosen by user)
    
    printf("Enter your monthly payment: ");
    scanf("%f", &P);            //getting monthly payment from user
    
    printf("\nr = %.2f\n", r);   //displaying interest rate, amount borrowed
    printf("B = %.1f\n", B);     //      and the monthly payment amount.    
    printf("P = %.1f\n\n", P);
    
    printTable(r,B,P);
  return 0;
}
