#include <stdio.h>

#include <stdio.h>

int main(){
    //処理

    int i,j,count=0;
    int A[5],B[10],X[5],Y[10];

    FILE *fp = fopen("input.kuso","r");

    for(i=0;i<10;i++){
        fscanf(fp,"%d ",&B[i]);
    }

    for(i=0;i<5;i++){
        A[i]=000;
    }

    for(i=0;i<5;i++){
        printf("\nはよ要素を入れんかいな若造！(%d): ",i+1);
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

    printf("和集合A U B = {");

    for(i=0;i<10;i++){
        if(A[i]!=B[i]){
            Y[i]=B[i];
            count++;
        }
    }
    for(i=0;i<5;i++){
        printf("%d ",A[i]);
    }
    for(i=0;i<10;i++){
        printf("%d ",Y[i-count]);
    }

    printf("}\n");
    printf("積集合 A n B = {");
    //ｵﾗｵﾗｵﾗｵﾗｵﾗｵﾗｵﾗ!!!!!!
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            if(A[i]==B[j]){printf("%d ",A[i]);}
            else{continue;}
        }
    }
    printf("}\n");

    fclose(fp);
}