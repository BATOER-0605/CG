#include <stdio.h>

float kuso(float x0,float y0,float x1,float y1,float t,float tt,float* x,float* y,FILE *fp){
    while (t <= 1.0) {
        *x = (x1 - x0) * t + x0;
        *y = (y1 - y0) * t + y0;

        fprintf(fp,"%f,%f\n",*x,*y);
        t+=tt;
    }
}

int main() {

    float x1_r, y1_r, x2_r, y2_r, x3_r, y3_r;

    float x0_1, y0_1, x1_1, y1_1;
    float x0_2, y0_2, x1_2, y1_2;
    float x0_3, y0_3, x1_3, y1_3;
    float t,x,y,tt = 0.2;

    FILE *fp2 = fopen("input.csv", "r");
    FILE *fp1 = fopen("out.csv", "a");

    fscanf(fp2,"%f,%f,%f,%f,%f,%f",&x1_r, &y1_r, &x2_r, &y2_r, &x3_r, &y3_r);

    x0_1=x1_r;
    y0_1=y1_r;
    x1_1=x2_r;
    y1_1=y2_r;

    kuso(x0_1,y0_1,x1_1,y1_1,t,tt,&x,&y,fp1);

    x0_2=x1_1;
    y0_2=y1_1;
    x1_2=x3_r;
    y1_2=y3_r;
    kuso(x0_2,y0_2,x1_2,y1_2,t,tt,&x,&y,fp1);

    x0_3=x1_2;
    y0_3=y1_2;
    x1_3=x1_r;
    y1_3=y1_r;
    kuso(x0_3,y0_3,x1_3,y1_3,t,tt,&x,&y,fp1);

    printf("入力した座標:\n%f,%f\n%f,%f\n%f,%f\n",x1_r, y1_r, x2_r, y2_r, x3_r, y3_r);
    fclose(fp1);
    fclose(fp2);
}