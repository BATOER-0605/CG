/*
    for文群の中の処理、(b - a)の形を修正しろ。
    splotする前に「set datafile separetor ","」を実行！！！
*/

#include <stdio.h>

void kuso(FILE *out,float X,float Y,float Z,float);

int main(){
    //FILE *INPUT1 = fopen("input1.txt","r");
    FILE *OUTPUT = fopen("output.csv","w");

    float length,X,Y,Z;

    printf("変の長さを入れんかいゴラ: ");
    scanf("%f",&length);

    kuso(OUTPUT,X,Y,Z,length);
}

void kuso(FILE *out,float X,float Y,float Z,float length) {
    //float IN[3][3];
    float t,tt;
    float n=0;
    int i;

    printf("\n分割数を入れんかいごらぁぁぁぁぁぁぁぁぁ!!!!!!!!!\n");
    scanf("%f",&n);
    tt = 1 / n;
    t=0;

    //n n n
    for(t=0;t<1.0;t+=tt){
        X = (length - 0)*t + 0;
        Y = (length - 0)*t + 0;
        Z = (length - 0)*t + 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X, Y,Z);
    }

    //0 0 0
    for(t=0;t<1.0;t+=tt){
        printf("%d,%d,%d\n",0,0,0);
        fprintf(out, "%d,%d,%d\n",0,0,0);
    }

    //n 0 n
    for(t=0;t<1.0;t+=tt){
        X = (length - 0)*t + 0;
        Y = 0;
        Z = (length - 0)*t + 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X, Y,Z);
    }

    //0 n n
    for(t=0;t<1.0;t+=tt){
        X = 0;
        Y = (length - 0)*t + 0;
        Z = (length - 0)*t + 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X, Y,Z);
    }

    //n n 0
    for(t=0;t<1.0;t+=tt){
        X = (length - 0)*t + 0;
        Y = (length - 0)*t + 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X, Y,Z);
    }

    //0 0 n
    for(t=0;t<1.0;t+=tt){
        X = 0;
        Y = 0;
        Z = (length - 0)*t + 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X, Y,Z);
    }

    //0 n 0
    for(t=0;t<1.0;t+=tt){
        X = 0;
        Y = (length - 0)*t + 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X, Y,Z);
    }

    //n 0 0
    for(t=0;t<1.0;t+=tt){
        X = (length - 0)*t + 0;
        Y = 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X, Y,Z);
    }


    fclose(out);
}