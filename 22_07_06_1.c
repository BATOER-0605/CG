#include <stdio.h>
#include <math.h>

double X,Y;
double tx,ty;
double Sx,Sy;
double rad;

void kuso1();
void kuso2();
void kuso3();

int main(){
    int n;

    while(1){
        printf("初めのメニュー\n");
        printf("1 拡大縮小\n");
        printf("2 回転\n");
        printf("3 平行移動\n");
        printf("0 プログラム修了\n");
        printf("その他の数字 この画面に戻る\n");

        scanf("%d",&n);

        if(n==1){
            kuso1();
        }
        else if(n==2){
            kuso2();
        }
        else if(n==3){
            kuso3();
        }
        else if(n==0){
            return 0;
        }
        else{
            continue;
        }
    }
}

//各関数の処理

void kuso1(){
    printf("Sx,Syを入力(書式 「Sx Sy」)\n");
    scanf("%lf %lf",&Sx,&Sy);
    
    printf("拡大縮小\n");
    printf("| %.1lf 0 0 |\n",Sx);
    printf("| 0 %.1lf 0 |\n",Sy);
    printf("| 0 0 1 |\n");
}

void kuso2(){
    printf("角度を入力\n");
    scanf("%lf",&rad);
    
    printf("回転\n");
    printf("| %.1lf -%.1lf 0 |\n",cos(rad),sin(rad));
    printf("| %.1lf %.1lf 0 |\n",sin(rad),cos(rad));
    printf("| 0 0 1 |\n");
}

void kuso3(){
    printf("tx,tyを入力(書式 「tx ty」)\n");
    scanf("%lf %lf",&tx,&ty);
    
    printf("平行移動\n");
    printf("| 1 0 %.1lf |\n",tx);
    printf("| 0 1 %.1lf |\n",ty);
    printf("| 0 0 1 |\n");
}