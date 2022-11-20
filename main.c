#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//平行移動する関数やで
/*void HKmove(float Lx,float Ly,float Lz,float x,float y,float z);

//拡大縮小移動する関数やで
void big_small(Sx,Sy,Sz);

//X 回転移動の関数やで
void beyblade_X(rad,x,y,z);

//Y 回転移動の関数やで
void beyblade_Y(rad,x,y,z);

//Z 回転移動の関数やで
void beyblade_Z(rad,x,y,z);

//gnuplot呼び出し
void call_nguplot(path);*/

int main(){

    FILE *fp1 = fopen("file1.txt","r");
    FILE *fp2 = fopen("file2.txt","r");

    int mode = 0;
    float X,Y,Z,rad;
    float Sx,Sy,Sz;
    float Lx,Ly,Lz;
    float T[4][4];
    int n;
    float x[5],y[5],z[5];

    fscanf(fp1,"%d",&mode);
    //拡大縮小時の読み取り
    if(mode == 1){while(fscanf(fp1,"(%f,%f,%f)",&Sx,&Sy,&Sz) != EOF);}
    //X Y Z 軸回転
    else if(mode == 2 || mode == 3 || mode == 4){fscanf(fp1,"%f (%f,%f,%f)",&rad,&X,&Y,&Z);}
    //平行移動
    else if(mode == 5){fscanf(fp1,"(%f,%f,%f)\n",&Lx,&Ly,&Lz);}
    else if(mode == 0){exit(0);}

    char res = system("pwd");

    fscanf(fp2,"%d ",&n);

    int i=0;
        while(fscanf(fp2,"(%f,%f,%f)",&x[i],&y[i],&z[i]) != EOF){
            printf("%f %f %f\n",x[i],y[i],z[i]);
            i++;
        }

    for(i=0;i<n;i++){
        continue;
    }

    exit(0);

    /*switch(mode){
        case 1:
            //拡大・縮小変換
            call_nguplot(res);
            HKmove(Lx,Ly,Lz,x,y,z);
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

    }*/
    return 0;
}

/*
void HKmove(Lx,Ly,Lz,x,y,z){
    float T[4][4];
    float result[4];

    for(int i=0;i<4;i++){
        for(int j=0;i<4;j++){
            if(i==0 || j==0){
                T[i][j] = 1;
            }
            else if(i==1 || j==1){
                T[i][j] = 1;
            }
            else if(i==2 || j==2){
                T[i][j] = 1;
            }
            else if(i==3 && j==3){
                T[i][j] = 1;
            }

            else if(i==0 || j==3){
                T[i][j] = x;
            }
            else if(i==1 || j==3){
                T[i][j] = y;
            }
            else if(i==2 || j==3){
                T[i][j] = z;
            }
            else{T[i][j] = 0;}
        }
    }

    //result[0][0] = T[0][0] * T[1][1] * x + T[0][0] * T[1][2] * y + T[0][0] * T[1][3] * z; //これを脳筋で解く。図はGoodNotes参照

    for(int i=0;i<4;i++){
        result[i] = T[i][0]*x + T[i][1]*y + T[i][2]*z + T[1][3]*1;
    }
 
}

void big_small(Sx,Sy,Sz,x,y,z){
    float T[4][4];
    float result[4];

    for(int i=0;i<4;i++){
        for(int j=0;i<4;j++){
            if(i==0 || j==0){
                T[i][j] = Sx;
            }
            else if(i==1 || j==1){
                T[i][j] = Sy;
            }
            else if(i==2 || j==2){
                T[i][j] = Sz;
            }
            else if(i==3 && j==3){
                T[i][j] = 1;
            }

            else{T[i][j] = 0;}
        }
    }

    for(int i=0;i<4;i++){
        result[i] = T[i][0]*x + T[i][1]*y + T[i][2]*z + T[1][3]*1;
    }
}

void beyblade_X(rad,x,y,z){
    float T[4][4];
    float result[4];
    rad *= 3.14 / 180;

    for(int i=0;i<4;i++){
        for(int j=0;i<4;j++){
            if(i==0 || j==0){
                T[i][j] = cos(rad);
            }
            else if(i==0 || j==1){
                T[i][j] = -sin(rad);
            }
            else if(i==1 || j==0){
                T[i][j] = sin(rad);
            }
            else if(i==1 || j==1 ){
                T[i][j] = cos(rad);
            }
            else if(i==2 || j==2){
                T[i][j] = 1;
            }
            else if(i==3 || j==3){
                T[i][j] = 1;
            }

            T[i][j] = 0;
        }

    }
    for(int i=0;i<4;i++){
        result[i] = T[i][0]*x + T[i][1]*y + T[i][2]*z + T[1][3]*1;
    }

}

void beyblade_Y(rad,x,y,z){
    float T[4][4];
    float result[4];
    rad *= 3.14 / 180;

    for(int i=0;i<4;i++){
        for(int j=0;i<4;j++){
            if(i==1 || j==1){
                T[i][j] = cos(rad);
            }
            else if(i==1 || j==2){
                T[i][j] = -sin(rad);
            }
            else if(i==2 || j==1){
                T[i][j] = sin(rad);
            }
            else if(i==2 || j==2 ){
                T[i][j] = cos(rad);
            }
            else if(i==0 || j==0){
                T[i][j] = 1;
            }
            else if(i==3 || j==3){
                T[i][j] = 1;
            }

            T[i][j] = 0;
        }

    }
    for(int i=0;i<4;i++){
        result[i] = T[i][0]*x + T[i][1]*y + T[i][2]*z + T[1][3]*1;
    }

}

void beyblade_Z(rad,x,y,z){
    float T[4][4];
    float result[4];
    rad *= 3.14 / 180;

    for(int i=0;i<4;i++){
        for(int j=0;i<4;j++){
            if(i==0 || j==0){
                T[i][j] = cos(rad);
            }
            else if(i==2 || j==0){
                T[i][j] = -sin(rad);
            }
            else if(i==0 || j==2){
                T[i][j] = sin(rad);
            }
            else if(i==2 || j==2 ){
                T[i][j] = cos(rad);
            }
            else if(i==1 || j==1){
                T[i][j] = 1;
            }
            else if(i==3 || j==3){
                T[i][j] = 1;
            }

            T[i][j] = 0;
        }

    }
    for(int i=0;i<4;i++){
        result[i] = T[i][0]*x + T[i][1]*y + T[i][2]*z + T[1][3]*1;
    }

}*/