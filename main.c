#include <stdio.h>
#include <stdlib.h>

//平行移動する関数やで
void HKmove(x,y,z);

//拡大縮小移動する関数やで
void big_small(Sx,Sy,Sz);

//X 回転移動の関数やで
void beyblade_X(rad,x,y,z);

//Y 回転移動の関数やで
void beyblade_Y(rad,x,y,z);

//Z 回転移動の関数やで
void beyblade_Z(rad,x,y,z);

//gnuplot呼び出し
void call_nguplot(path);

int main(){

    FILE *fp1 = fopen("file1.txt","r");
    FILE *fp2 = fopen("file2.txt","r");

    int mode = 0;
    float X,Y,Z,rad;
    float Sx,Sy,Sz;

    fscanf(fp1,"%d",&mode);
    //拡大縮小時の読み取り
    if(mode == 1){fscanf(fp1,"(%lf,%lf,%lf)",&Sx,&Sy,&Sz);}
    //X Y Z 軸回転
    else if(mode == 2 || mode == 3 || mode == 4){fscanf(fp1,"%lf (%lf,%lf,%lf)",&rad,&X,&Y,&Z);}
    //平行移動
    else if(mode == 5){fscanf(fp1,"(%lf,%lf,%lf)",&X,&Y,&Z);}
    else if(mode == 0){exit(0);}

    char res = system("pwd");

    switch(mode){
        case 1:
            //拡大・縮小変換
            call_nguplot(res);
            HKmove();
            call_nguplot(res);
            big_small();
            call_nguplot(res);
            HKmove();

        case 2:
            //X変換
            call_nguplot(res);
            HKmove();
            call_nguplot(res);
            beyblade_X();
            call_nguplot(res);
            HKmove();

        case 3:
            //Y変換
            call_nguplot(res);
            HKmove();
            call_nguplot(res);
            beyblade_Y();
            call_nguplot(res);
            HKmove();

        case 4:
            //Z変換
            call_nguplot(res);
            HKmove();
            call_nguplot(res);
            beyblade_Z();
            call_nguplot(res);
            HKmove();

        case 5:
            //平行移動
            call_nguplot(res);
            HKmove();

        default:
            printf("隠しコマンド発動！！！\n");

    }
    return 0;
}