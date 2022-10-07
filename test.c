#include <stdio.h>
#include <math.h>
#define pi 3.1415926

int main(){
    FILE *fpin = fopen("input1.txt","r");
    FILE *fpout = fopen("output.csv","w");

    double A[3][2];
    double B[3][2];

    int i,j;
    double rad;

    for (i=0;i<3;i++){
        fscanf(fpin,"%lf %lf",&A[i][0],&A[i][1]);
    }
    fclose(fpin);

    printf("回転角度の入力");
    scanf("%lf",&rad);

    rad *= (pi/180);

    for(i=0;i<3;i++){
        B[i][0] = (A[i][0]*cos(rad)) + (A[i][1]*sin(rad)*(-1));
        B[i][1] = (A[i][0]*sin(rad)) + (A[i][1]*cos(rad));

        fprintf(fpout,"%lf,%lf\n",B[i][0],B[i][1]);
    }
    
}