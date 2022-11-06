#include <stdio.h>

int main(){
    int Ag,ArBg,Br;
    int i,j,k;

    double A[10][10],B[10][10],Z[10][10];

    printf("A行列の行数\n");
    scanf("%d",&Ag);

    printf("A行列の列数及びB行列の行数\n");
    scanf("%d",&ArBg);

    printf("B行列の行数\n");
    scanf("%d",&Br);

    for(i=0;i<Ag;i++){
        for(j=0;j<ArBg;j++){
            printf("A (%d,%d)=",i+1,j+1);
            scanf("%lf",&A[i][j]);
        }
    }

    printf("A行列\n");
    for(i=0;i<Ag;i++){
        printf("|");

        for(j=0;j<ArBg;j++){
            if(A[i][j]>=0){
                printf(" ");
            }

        printf("%.1lf",A[i][j]);

        }
        printf("|\n");
    }

    printf("\n");

    for(i=0;i<ArBg;i++){
        for(j=0;j<Br;j++){
            printf("B(%d,%d)=",i+1,j+1);
            scanf("%lf",&B[i][j]);
        }
    }

    printf("B行列\n");
    for(i=0;i<ArBg;i++){
        printf("|");
        for(j=0;j<Br;j++){
            if(B[i][j]>=0){
                printf(" ");
            }

            printf("%.1lf",B[i][j]);
        }
        printf("|\n");
    }

    printf("\n");

    for(i=0;i<Ag;i++){
        for(j=0;j<Br;j++){
            Z[i][j] = 0;
            for(k=0;k<ArBg;k++){
                Z[i][j]+=A[i][k]*B[k][i];
            }
        }
    }

    for(i=0;i<Ag;i++){
        printf("|");
        for(j=0;j<Br;j++){
            if(Z[i][j]>=0){
                printf(" ");
            }
            if(0<=Z[i][j]){
                printf(" ");
            }
            if(-10<=Z[i][j]){
                printf(" ");
            }
            printf("%.1lf",Z[i][j]);
        }
        printf("|\n");
    }

    return 0;
}