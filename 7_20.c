#include <stdio.h>

int main(){

    FILE *inputA=fopen("inputA.txt","r");
    FILE *inputB=fopen("inputA.txt","r");

    float A[5][5];
    float B[5][5];

    int nA,nB,i,j,flag;

    if(inputA == NULL || inputB == NULL){
        return 1;
    }

    fscanf(inputA,"%d\n",&nA);
    fscanf(inputB,"%d\n",&nB);

    fscanf(inputA,"%s\n %f %f %f %f %f %f %f %f %f %f",&A[0][0],&A[0][1],&A[1][0],&A[1][1],&A[2][0],&A[2][1],);
    fscanf(inputB,"%s\n %f %f %f %f",&B[0][0],&B[0][1],&B[1][0],&B[1][1]);
    
    printf("%f %f %f %f\n",A[0][0],A[0][1],A[1][0],A[1][1]);
    //A+B

    printf("A+B\n");

    for(i=0;i<nA;i++){
        printf("|\t");
        for(j=0;j<nA;j++){
            printf("%f\t",A[i][j]+B[i][j]);
        }
        printf("|\n");
    }

    //A-B

    printf("A-B\n");

    for(i=0;i<nA;i++){
        printf("|\t");
        for(j=0;j<nA;j++){
            printf("%f\t",A[i][j]-B[i][j]);
        }
        printf("|\n");
    }

    //B-A

    printf("B-A\n");

    for(i=0;i<nA;i++){
        printf("|\t");
        for(j=0;j<nA;j++){
            printf("%f\t",B[i][j]-A[i][j]);
        }
        printf("|\n");
    }
}