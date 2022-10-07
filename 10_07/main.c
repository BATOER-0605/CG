#include <stdio.h>

void kuso(FILE *in,FILE *out);

int main(){
    FILE *INPUT1 = fopen("input1.txt","r");
    FILE *OUTPUT = fopen("output.csv","w");

    kuso(INPUT1,OUTPUT);
}

void kuso(FILE *in,FILE *out) {
    float IN[3][3];
    float x[3],y[3],z[3];
    int t=0,tt;
    int n=0;
    float *X,*Y,*Z;
    int i;

    for(i=0;i<3;i++){
        fscanf(in,"%f %f %f\n",&IN[i][0],&IN[i][1],&IN[i][2]);
    }

    printf("分割数を入れんかいごらぁぁぁぁぁぁぁぁぁ!!!!!!!!!\n");
    scanf("%d",&n);
    tt = n/10;

    i=0;

    for(i=0;i<=n-1;i++){

        *X = (IN[i+1][0] - IN[i][0]) * t + IN[i][0];
        *Y = (IN[i+1][1] - IN[i][1]) * t + IN[i][1];
        *Z = (IN[i+1][2] - IN[i][2]) * t + IN[i][2];
        printf("%f,%f,%f\n", *X, *Y,*Z);
        fprintf(out, "%f,%f,%f\n", *X, *Y,*Z);
    }

    fclose(in);
    fclose(out);
}