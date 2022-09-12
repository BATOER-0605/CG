#include <stdio.h>

int main(){

    FILE *inputA=fopen("inputA.txt","r");
    FILE *inputB=fopen("inputB.txt","r");

    int i,j,N;
    float A[5][5],B[5][5];

    fscanf(inputA,"%d",&N);
    fscanf(inputB,"%d",&N);

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            fscanf(inputA," %f",&A[i][j]);
            fscanf(inputB," %f",&B[i][j]);
        }
    }

    //A+B

    printf("A+B\n");

    for(i=0;i<N;i++){
        printf("|\t");
        for(j=0;j<N;j++){
            printf("%f\t",A[i][j]+B[i][j]);
        }
        printf("|\n");
    }

    //A-B

    printf("A-B\n");

    for(i=0;i<N;i++){
        printf("|\t");
        for(j=0;j<N;j++){
            printf("%f\t",A[i][j]-B[i][j]);
        }
        printf("|\n");
    }

    //B-A

    printf("B-A\n");

    for(i=0;i<N;i++){
        printf("|\t");
        for(j=0;j<N;j++){
            printf("%f\t",B[i][j]-A[i][j]);
        }
        printf("|\n");
    }

    fclose(inputA);
    fclose(inputB);
}