#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 2
#define R 3


int i,j,k,u;

void com_AD(int a1,int a2,int b1,int b2){
    //printf("行列Aの要素 %d %d\n",a1,a2);

    float A[a1][a2];
    float B[b1][b2];

    if (a2!=b1){
        printf("この行列は計算できません。\n");
        exit(0);
    }

    else{
        float AB[a1][b2];

        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                for(u=0;u<M;u++){
                    for(k=0;k<R;k++){
                        AB[i][u]+=A[i][j]*B[j][k];
                        }
                    }
                
                }
            }
    }

}