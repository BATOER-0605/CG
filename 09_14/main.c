#include <stdio.h>
#include <math.h>

int main(){
    FILE *input1 = fopen("input1.txt","r");
    FILE *output = fopen("output.csv","w");

    //ｶｳﾝﾀｧｧｧｧｧｧｧｧ変数
    int i,j;

    //回転角度すぅぅぅぃぃぃぃぃたぁぁぁぁぁの定義
    float theeee = 0;
    printf("回転角度(deg)↓\n");
    scanf("%f",&theeee);
    theeee *= 3.14 / 180;

    //必要な配列の定義
    float fire1[3][3];
    float fire2[3][3];
    float res[3][3];

    //三角形の座標情報の定義
    float point[3][3];
    for(i=0;i<3;i++){
            if(i==2){
                point[i][j] = 1;
            }
            else{
            fscanf(input1,"%f %f %f",&point[i][0],&point[i][1],&point[i][2]);
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
    cnv2[0][0]=cos(theeee);
    cnv2[0][1]=-sin(theeee);
    cnv2[0][2]=0;
    cnv2[1][0]=sin(theeee);
    cnv2[1][1]=cos(theeee);
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

    for(i=0;i<3;i++){
        fire1[0][i] = cnv1[0][0]*point[0][i] + cnv1[0][1]*point[1][i] + cnv1[0][2]*point[2][i];
        fire1[1][i] = cnv1[1][0]*point[0][i] + cnv1[1][1]*point[1][i] + cnv1[1][2]*point[2][i];
        fire1[2][i] = cnv1[2][0]*point[0][i] + cnv1[2][1]*point[1][i] + cnv1[2][2]*point[2][i];
    }

    for(i=0;i<3;i++){
        fire2[0][i] = cnv2[0][0]*fire1[0][i] + cnv2[0][1]*fire1[1][i] + cnv2[0][2]*fire1[2][i];
        fire2[1][i] = cnv2[1][0]*fire1[0][i] + cnv2[1][1]*fire1[1][i] + cnv2[1][2]*fire1[2][i];
        fire2[2][i] = cnv2[2][0]*fire1[0][i] + cnv2[2][1]*fire1[1][i] + cnv2[2][2]*fire1[2][i];
    }

    for(i=0;i<3;i++){
        res[0][i] = cnv3[0][0]*fire2[0][i] + cnv3[0][1]*fire2[1][i] + cnv3[0][2]*fire2[2][i];
        res[1][i] = cnv3[1][0]*fire2[0][i] + cnv3[1][1]*fire2[1][i] + cnv3[1][2]*fire2[2][i];
        res[2][i] = cnv3[2][0]*fire2[0][i] + cnv3[2][1]*fire2[1][i] + cnv3[2][2]*fire2[2][i];
    }

    for(i=0;i<3;i++){
        fprintf(output,"%f,%f\n",res[0][i],res[1][i]);
    }
}