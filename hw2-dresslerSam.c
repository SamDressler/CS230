//Sam Dressler CSCI 230 Program 2 1/25/19 2 Sort methods that sort the int or float values and 2 print methods for each of the sort methods that print high to low or low to high
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct catalog {
    char name[20];
    int numi;
    float numf;
    char color[12];

} catalog[MAX];

int loadFile(){
    FILE *fp;
    int i=0, size=0;
    fp = fopen("hw2.dat","r");
     if(fp != NULL){
        while(1){
            fscanf(fp,"%s %f %d %s",catalog[i].name, &catalog[i].numf, &catalog[i].numi, catalog[i].color);
            if(feof(fp)) break;
            //printf("%s %.2f %d %s\n",catalog[i].name, catalog[i].numf, catalog[i].numi, catalog[i].color);
            i++;
            size++;
        }

    fclose(fp);
 } else printf("Invalid or Empty file\n");
 return size;
}

void swapFloat(float *x,float *y){
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapInt(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void printFloatLowHigh(int size, float *values){
        int i,j;
    printf("Float values sorted low to high:\n\n");
    for(i = size-1; i >= 0; i--){
        for(j=0; j<size; j++){
            if(values[i] == catalog[j].numf){
                printf("%s %.2f %d %s\n", catalog[j].name, catalog[j].numf, catalog[j].numi,catalog[j].color);
                j=size-1;
            }
        }
    }

}
void printFloatHighLow(int size, float *values){
        int i,j;
    printf("Float values sorted high to Low:\n\n");
        for(i =0; i <size ; i ++){
            for(j=0; j<size; j++){
                if(values[i] == catalog[j].numf){
                     printf("%s %.2f %d %s\n", catalog[j].name, catalog[j].numf, catalog[j].numi,catalog[j].color);

                }
            }
        }

}

int sortFloat(int size, int flag){
   float values[MAX];
   int i, j, k;
//copying the float values out of the array of struct into seperate array.
   for(i = 0; i <size; i ++){
      values[i] = catalog[i].numf;
   }
//does bubble sort no matter what the flag says
   for(j=0; j<size-1; j++){
        for(k=0; k <size-j-1; k++){
          if(values[k] < values[k+1]){
            swapFloat(&values[k], &values[k+1]);
           }
        }
    }
//If flag is true then sorted values are printed high to low
    if(flag ==1){
       printFloatHighLow(size, values);
       return 0;
    }
//If flag is false then sorted values are printed low to high
    else{
       printFloatLowHigh(size, values);
       return 0;
   }
}
void printIntLowHigh(int size, int *values){
    int i,j;
    printf("Int values sorted low to high:\n\n");
    for(i = size-1; i >= 0; i--){
        for(j=0; j<size; j++){
            if(values[i] == catalog[j].numi){
                printf("%s %.2f %d %s\n", catalog[j].name, catalog[j].numf, catalog[j].numi,catalog[j].color);
            }
        }
    }

}
void printIntHighLow(int size, int *values){
    int i,j;
    printf("Int values sorted high to Low:\n\n");
         for(i = 0; i < size; i++){
             for(j=0; j<size; j++){
                if(values[i] == catalog[j].numi){
                    printf("%s %.2f %d %s\n", catalog[j].name, catalog[j].numf, catalog[j].numi,catalog[j].color);
                }
            }
        }

}
void sortInt(int size,int flag){
   int i, j, k;
   int values[MAX];

   //copying the int values out of the array of struct into seperate array.
    for(i = 0; i <size; i ++){
        values[i] = catalog[i].numi;
    }
    for(j = 0; j < size-1; j++){
        for(k = 0; k < size-j-1; k++){
            if(values[k] < values[k+1]){
                  swapInt(&values[k], &values[k+1]);
            }
        }
    }
    if (flag == 1) {
        printIntHighLow(size, values);
        return;
    }
    else{
        printIntLowHigh(size, values);
        return;
    }

}
void displayFile(int size){
   int i;
    printf("%d\n",size);
    for(i=0; i < size; i++){
      printf("%s %.2f %d %s\n", catalog[i].name, catalog[i].numf, catalog[i].numi,catalog[i].color);
   }
}
int main (void){
    int size=loadFile();
    int flag;
      do{
        int response;
        printf("-------------------Main Menu--------------------------\n");
        printf("1. Sort data by the float value & print high to low.\n");
        printf("2. Sort data by the float value & print low to high.\n");
        printf("3. Sort data by the int value & print high to low.\n");
        printf("4. Sort data by the int value & print low to high.\n");
        printf("5. Exit Program.\n");
        printf("6. Display the file\n");
        printf("Please enter an option: ");
        scanf("%d",&response);
        printf("------------------------------------------------------\n");
        if(response>0 && response <7){
        switch(response){
            case 1:
                flag = 1; //if flag is true, then code prints the data with float sorted values high to low
                sortFloat(size,flag);
                break;
            case 2:
                flag = 0;//if flag is true, then code prints the data with float sorted values low to high
                sortFloat(size,flag);
                break;
            case 3:
                flag = 1;//if flag is true then prints the sorted values high to low
                sortInt(size,flag);
                break;
            case 4:
                flag = 0; //if flag is false the prints the sorted values low to high
                sortInt(size,flag);
                break;
            case 5:
                exit(0);
            case 6:
                displayFile(size);
        }
    }else{
        printf("Enter valid number\n");
    }



}while(1);

}
