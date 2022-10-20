#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void kass(){
    float Sx,Sy,Sz;
    printf("拡大縮小を選択した\n");
    printf("Sxを入力\n");
    scanf("%f",&Sx);
    printf("Syを入力\n");
    scanf("%f",&Sy);
    printf("Szを入力\n");
    scanf("%f",&Sz);

    printf("|%f\t0\t0\t0|\n",Sx);
    printf("|0\t%f\t0\t0|\n",Sy);
    printf("|0\t0\t%f\t0|\n",Sz);
    printf("|0\t0\t0\t1|\n");

}
void kuso(){
    printf("X軸回転行列を洗濯した。\n");
    printf("回転角度シータを入力ェ\n");
    float rad;
    scanf("%f",&rad);
    rad *= 3.14 / 180;

    printf("|1\t0\t0\t0|\n");
    printf("|0\t%f\t%f\t0|\n",cos(rad),-sin(rad));
    printf("|0\t%f\t%f\t0|\n",sin(rad),cos(rad));
    printf("|0\t0\t0\t1|\n");
    
}
void unko(){
    printf("Y軸回転行列を洗濯\n");

    printf("回転角度シータを入力\n");
    float rad;
    scanf("%f",&rad);
    rad *= 3.14 / 180;

    printf("|%f\t0\t%f\t0|\n",cos(rad),sin(rad));
    printf("|0\t1\t0\t0|\n");
    printf("|%f\t0\t%f\t0|\n",-sin(rad),cos(rad));
    printf("|0\t0\t0\t1|\n");
}
void buri(){
    printf("Z軸回転行列を洗濯\n");

    printf("回転角度シータを入力\n");
    float rad;
    scanf("%f",&rad);
    rad *= 3.14 / 180;

    printf("|%f\t%f\t0\t0|\n",cos(rad),-sin(rad));
    printf("|%f\t%f\t0\t0|\n",sin(rad),cos(rad));
    printf("|0\t0\t1\t0|\n");
    printf("|0\t0\t0\t1|\n");
}
void joo(){
    printf("平行移動を洗濯\n");
    printf("X移動量\n");
    float Lx,Ly,Lz;
    scanf("%f",&Lx);
    printf("Y移動量\n");
    scanf("%f",&Ly);
    printf("Z移動量\n");
    scanf("%f",&Lz);

    printf("|1\t0\t0\t%f|\n",Lx);
    printf("|0\t1\t0\t%f|\n",Ly);
    printf("|0\t0\t1\t%f|\n",Lz);
    printf("|0\t0\t0\t1|\n");


}
int main(){
    int n=0;
    while (1){
        printf("1：拡大・縮小行列\n");
        printf("2：X 軸回転行列\n");
        printf("3：Y 軸回転行列\n");
        printf("4：Z 軸回転行列\n");
        printf("5：平行移動行列\n");
        printf("0：プログラム終了\n");
        printf("その他の数字：選択画面へ戻る\n");
        scanf("%d",&n);
        switch (n){
            case 1:
                kass();
                break;

            case 2:
                kuso();
                break;

            case 3:
                unko();
                break;

            case 4:
                buri();
                break;

            case 5:
                joo();
                break;

            case 0:
                exit(0);
                break;
            
            default:
                break;
            }
    }
    
}