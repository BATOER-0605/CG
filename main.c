#include <stdio.h>

void kuso(float , int ,FILE *);

int main(){
    float length;
    int n;

    FILE *out = fopen("output.csv","w");

    printf("辺の長さ: ");
    scanf("%f",&length);
    printf("\n");
    printf("分割数: ");
    scanf("%f",&n);

    kuso(length,n,out);

    fclose(out);

    return 0;
}

void kuso(float len,int n,FILE* fp){
    
}