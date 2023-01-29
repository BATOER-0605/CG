#include <stdio.h>

int main(){

    int i,j,count=0,flag =0;
    int A[5],B[10];

    FILE *fp = fopen("input.txt","r");

    for(i=0;i<10;i++){

        fscanf(fp,"%d\n",&B[i]);
    }

    for(i=0;i<5;i++){
        printf("\nはよ要素を入れんかいな若造(%d): ",i+1);
        scanf("%d",&A[i]);
    }

    //A
    printf("集合A = {");
    for(i=0;i<5;i++){
        printf("%d ",A[i]);
    }
    printf("}\n");

    //B
    printf("集合B = {");
    for(i=0;i<10;i++){
        printf("%d ",B[i]);
    }
    printf("}\n");

    //A U B
    printf("和集合A U B = {");

    for(i=0;i<10;i++){
        printf(" %d",B[i]);
    }

    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            if(A[i] == B[j]){
                flag =1;
            }
        }
        if(flag==0){
            printf(" %d",A[i]);
        }
        flag=0;
    }

    printf("}\n");

    //A n B
    printf("積集合 A n B = {");
    
    flag = 0;

    for(i=0;i<10;i++){
        for(j=0;j<5;j++){
            if(A[j] == B[i]){
                flag =1;
            }
        }
        if(flag==1){
            printf(" %d",B[i]);
        }
        flag=0;
    }

    printf("}\n");
    
    fclose(fp);
}