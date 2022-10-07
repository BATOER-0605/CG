#include <stdio.h>

void kuso(FILE *in,FILE *out,float X,float Y,float Z);

int main(){
    FILE *INPUT1 = fopen("input1.txt","r");
    FILE *OUTPUT = fopen("output.csv","w");

    float X,Y,Z;

    kuso(INPUT1,OUTPUT,X,Y,Z);
}

void kuso(FILE *in,FILE *out,float X,float Y,float Z) {
    float IN[3][3];
    float t,tt;
    float n=0;
    int i;

    for(i=0;i<3;i++){
        fscanf(in,"%f %f %f\n",&IN[i][0],&IN[i][1],&IN[i][2]);
    }

    printf("分割数を入れんかいごらぁぁぁぁぁぁぁぁぁ!!!!!!!!!\n");
    scanf("%f",&n);
    tt = 1 / n;
    t=0;
    printf("ttの値: %f\n",tt);

    while(t<=1.0){

        X = (IN[1][0] - IN[0][0]) * t + IN[i][0];
        Y = (IN[2][1] - IN[1][1]) * t + IN[i][1];
        Z = (IN[0][2] - IN[2][2]) * t + IN[i][2];
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X, Y,Z);

        t+=tt;
    }

    fclose(in);
    fclose(out);
}