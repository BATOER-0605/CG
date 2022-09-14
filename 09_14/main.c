#include <stdio.h>
#include <math.h>

int main(){
    FILE *input1 = fopen("input1.txt","r");
    FILE *output = fopen("output.csv","w");

    //ｶｳﾝﾀｧｧｧｧｧｧｧｧ変数
    int i,j;

    //回転角度すぅぅぅぃぃぃぃぃたぁぁぁぁぁの定義
    float θ = 0;

    //必要な配列の定義
    float fire1[3][3];
    float fire2[3][3];
    float res[3][3];

    //三角形の座標情報の定義
    float point[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(j==3){
                point[i][j] = 1;
            }
            else{
            fscanf(input1,"%f %f",&point[i][j],&point[i][j]);
            }
        }
    }

    //同次変換行列3x3の宣言(原点に戻していくｩｩｩｩｩｩｩ!!!!!)
    float cnv1[3][3];
    cnv1[0][0]=1;
    cnv1[0][1]=0;
    cnv1[0][2]=-point[0][0];
    cnv1[1][0]=0;
    cnv1[1][1]=1;
    cnv1[1][2]=-point[0][1];
    cnv1[2][0]=0;
    cnv1[2][1]=0;
    cnv1[2][2]=1;

    //同次変換行列3x3の宣言(回転ﾝﾝﾝﾝﾝ)
    float cnv2[3][3];
    cnv2[0][0]=cos(-θ);
    cnv2[0][1]=-sin(-θ);
    cnv2[0][2]=0;
    cnv2[1][0]=sin(-θ);
    cnv2[1][1]=cos(-θ);
    cnv2[1][2]=0;
    cnv2[2][0]=0;
    cnv2[2][1]=0;
    cnv2[2][2]=1;
    
    //同次変換行列3x3の宣言(ﾝﾝﾝﾝﾝ戻していくｩｩｩｩｩｩｩｩｩｩ!!!!!!!!!!!)
    float cnv3[3][3];
    cnv3[0][0]=1;
    cnv3[0][1]=0;
    cnv3[0][2]=point[0][0];
    cnv3[1][0]=0;
    cnv3[1][1]=1;
    cnv3[1][2]=point[0][1];
    cnv3[2][0]=0;
    cnv3[2][1]=0;
    cnv3[2][2]=1;


    //ここから下、計算のアルゴリズムを見直す必要あり
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            fire1[i][j] = cnv3[i][j]*cnv2[j][i];
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            fire2[i][j] = fire1[i][j]*cnv1[j][i];
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            res[i][j] = fire2[i][j]*point[j][i];
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
        fprintf(output,"%f %f\n",res[i][j-1],res[i][j]);
            }
        }
}