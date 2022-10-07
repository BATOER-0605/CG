#include <stdio.h>

void kass(FILE *in,FILE *out);

int main(){
    FILE *INPUT1 = fopen("input1.txt","r");
    FILE *OUTPUT = fopen("output.csv","w");

    kass(INPUT1,OUTPUT);
}

void kass(FILE *in,FILE *out){
    float IN[3][3];
    float x[3],y[3],z[3];
    int t=0;
    int n=0;
    printf("分割数を入れんかいごらぁぁぁぁぁぁぁぁぁ!!!!!!!!!\n");
    scanf("%d",&n);

    t = n /10;
    
    for(int i=0;i<3;i++){
        fscanf(in,"%f %f %f\n",&IN[i][0],&IN[i][1],&IN[i][2]);
    }

    for(int i=0;i<3;i++){
        x[i] = (IN[i+1][0] - IN[i][0]) * t + IN[i][0];
        y[i] = (IN[i+1][1] - IN[i][1]) * t + IN[1][1];
        z[i] = (IN[i+1][2] - IN[i][2]) * t + IN[i][2];
    }

    for(int i=0;i<3;i++){
        fprintf(out,"%f,%f,%f\n",x[i],y[i],z[i]);
    }

    fclose(in);
    fclose(out);

}