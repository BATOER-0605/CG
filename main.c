#include <stdio.h>

void kuso(FILE *);

int main(){
    FILE *out = fopen("out.csv","w");

    kuso(out);
}

void kuso(FILE *fp){
    float w,n;
    printf("へんの長さ: ");
    scanf("%f",&w);

    printf("\n分割数を入れんかいゴラァ: ");
    scanf("%f",&n);

    float tt = 1/n;
    float t=0;
    float X[11],Y[11];

    //原点

    int i,j;
    while(t<1.0){
        for(i=0;i<n;i++){
            X[i] = (w - 0)*t +0;
            printf("X[%d]: %f\n",i,X[i]);
            t+=tt;
        }
    }

    t=0;

    while(t<1.0){
        for(i=0;i<n;i++){
            Y[i] = (w - 0)*t +0;
            printf("Y[%d]: %f\n",i,Y[i]);
            t+=tt;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d,%d: %f,%f\n",i,j,X[i],Y[j]);
            fprintf(fp,"%f,%f\n",X[i],Y[j]);
        }
    }
    
}