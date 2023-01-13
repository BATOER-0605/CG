#include <stdio.h>

void kuso(FILE *);

int main(){
    FILE *out = fopen("out.csv","w");

    kuso(out);
}

void kuso(FILE *fp){
    printf("へんの長さ: ");
    float W;
    scanf("%f",&W);

    printf("\n分割数を入れんかいゴラァ: ");
    float n;
    scanf("%f",&n);

    
}