#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n,i,j;
    printf("Enter number of Strings:\n");
    scanf("%d",&n);
    char s[n][100];
    printf("Enter Strings:\n");
    for(i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    srand(time(0));
    int ran=rand()%n;
    char temp[100];
    printf("Random string is : %s\n",s[ran]);
    printf("Enter it's anagram to check:\n");
    scanf("%s",temp);
    if(strlen(s[ran])!=strlen(temp)){
        printf("Not Anagram!\n");
        exit(0);
    }
    for(i=0;i<strlen(s[ran]);i++){
        for(j=i+1;j<strlen(s[ran]);j++){
            if(s[ran][i]>s[ran][j]){
                char t=s[ran][i];
                s[ran][i]=s[ran][j];
                s[ran][j]=t;
            }
            if(temp[i]>temp[j]){
                char t=temp[i];
                temp[i]=temp[j];
                temp[j]=t;
            }
        }
    }
    for(i=0;i<strlen(s[ran]);i++){
        if(s[ran][i]!=temp[i]){
            printf("Not Anagram!\n");
            exit(0);
        }
    }
    printf("It is ANAGRAM !\n");
return 0;
}
