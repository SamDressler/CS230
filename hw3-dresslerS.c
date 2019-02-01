//Sam Dressler Hw3 CS 230
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int main(void){
FILE *fp1 = fopen("american0.txt", "r");
FILE *fp2 = fopen("american1.txt", "r");
FILE *fp3 = fopen("american2.txt", "r");

if(fp1 == NULL || fp2 == NULL || fp3 == NULL ){
    printf("One or more of the files were not found.");
}
char temp [1][MAX];
int s1=0;int s2=0;int s3=0;
int i=0;int j=0;
int totalSize = 0;
char **words;
//getting size of all three files
while(1){
    fscanf(fp1,"%s", temp[0]);
    while(1){
        fscanf(fp2,"%s",temp[0]);
        while(1){
            fscanf(fp3,"%s", temp[0]);
            if(feof(fp3))break;
            s3++;
        }
        if(feof(fp2))break;
        s2++;
    }
    if(feof(fp1))break;
    s1++;

}
totalSize = s1+s2+s3;
printf("Sizes of files: %d %d %d\n",s1,s2,s3);
printf("Total size: %d\n",totalSize);

fclose(fp1);
fclose(fp2);
fclose(fp3);
    //create dynamic array
    words = (char**)calloc(totalSize,sizeof(*words));
    for(i=0; i < totalSize; i++){
        words[i] = calloc(MAX, sizeof(char));
    }
  //populate array with words from files.
    FILE *fp = fopen("american0.txt","r");
    for(i = 0; i < s1; i++){
        fscanf(fp, "%s",words[j++]);
    }
    fclose(fp);
    fp = fopen("american1.txt","r");
    for(i = 0; i < s2; i++){
        fscanf(fp, "%s",words[j++]);
    }
    fclose(fp);
    fp = fopen("american2.txt","r");
    for(i = 0; i < s3; i++){
        fscanf(fp, "%s",words[j++]);
    }
    fclose(fp);

    //Sort the array
    char temp1[MAX];
    for(i = 0; i < totalSize; i++){
        for(j = 0; j < totalSize-1; j++){
             if(strcasecmp(words[j],words[j+1])>0){
                strcpy(temp1, words[j+1]);
                strcpy(words[j+1],words[j]);
                strcpy(words[j],temp1);
            }
        }
    }
    fp = fopen("words.txt","w");
    for(i=0; i < totalSize; i++){
        fprintf(fp,"%s\n",words[i]);
    }
    for(i = 0; i <totalSize; i++){
        free(words[i]);
    }
    free(words);
    fclose(fp);
    printf("Save to file complete!\n");

    return 0;
}
