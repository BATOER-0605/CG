#include <stdio.h>
void kuso(FILE *out,float X,float Y,float Z);
int main(){

 FILE *OUTPUT = fopen("output.csv","w");
 float X,Y,Z;
 kuso(OUTPUT,X,Y,Z);
}
void kuso(FILE *out,float X,float Y,float Z) {
 float IN[3][3];
 float t,tt;
 float n=0;
 int i;
 for(i=0;i<3;i++){
 scanf("%f %f %f\n",&IN[i][0],&IN[i][1],&IN[i][2]);
 }
 printf("分割数を入れんかいごらぁぁぁぁぁぁぁぁぁ!!!!!!!!!\n");
 scanf("%f",&n);
 tt = 1 / n;
 t=0;
 printf("tt の値: %f\n",tt);
 for(i=0;i<3;i++){
 for(t=0;t<1.0;t+=tt){
 X = (IN[i+1][0] - IN[i][0]) * t + IN[i][0];
 Y = (IN[i+1][1] - IN[i][1]) * t + IN[i][1];
 Z = (IN[i+1][2] - IN[i][2]) * t + IN[i][2];
 printf("%f,%f,%f\n", X, Y,Z);
 fprintf(out, "%f,%f,%f\n", X, Y,Z);
 }
 }

 fclose(out);
}
