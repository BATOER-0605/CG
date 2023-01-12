#include <stdio.h>

void kuso(FILE *out,float);

int main(){

    FILE *OUTPUT = fopen("output.csv","w");

    float length;

    printf("変の長さを入れんかいゴラ: ");
    scanf("%f",&length);

    kuso(OUTPUT,length);
}

void kuso(FILE *out,float length) {

    float t,tt;
    float n=0;
    int i;

    printf("\n分割数を入れんかいごらぁぁぁぁぁぁぁぁぁ!!!!!!!!!\n");
    scanf("%f",&n);
    tt = 1 / n;
    t=0;

    float X,Y,Z;
    for(t=0;t<1.0;t+=tt){

        X = 0;
        Y = 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = (length - 0)*t +0;
        Y = 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = 0;
        Y = (length - 0)*t +0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = 0;
        Y = 0;
        Z = (length -0)+t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = length;
        Y = (length - 0)*t +0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = (0 - length)*t +length;
        Y = length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = length;
        Y = 0;
        Z = (length - 0)*t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = length;
        Y = (length - 0)*t +0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = length;
        Y = length;
        Z = (0 - length)*t +length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = (0 - length)*t +length;
        Y = 0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = 0;
        Y = (length - 0)*t +0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = (length - 0)*t +0;
        Y = length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        X = 0;
        Y = length;
        Z = (0 - length)*t + length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

    }


    fclose(out);
}