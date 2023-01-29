#include <stdio.h>

int main(){
    //処理

    int i,j,count=0;
    int A[5],B[10],Ans[15];

    FILE *fp = fopen("input.txt","r");

    for(i=0;i<10;i++){

        fscanf(fp,"%d\n",&B[i]);
        printf("%d\n",B[i]);
    }

    for(i=0;i<5;i++){
        printf("\nはよ要素を入れんかいな若造(%d): ",i+1);
        scanf("%d",&A[i]);
    }

    //A
    printf("集合A = {");
    for(i=0;i<5;i++){
        printf("%d ",A[i]);
    }
    printf("}\n");

    //B
    printf("集合B = {");
    for(i=0;i<10;i++){
        printf("%d ",B[i]);
    }
    printf("}\n");

    printf("和集合A U B = {");

        //処理
        for(i=0;i<10;i++){
            //debug
            printf("%d\n",B[i]);
            Ans[i] = B[i];
        }

        //debug
        for(i=0;i<15;i++){
            printf("%d ",Ans[i]);
        }
/*
        count = 11;

        for(i=0;i<5;i++){
            for(j=0;j<10;j++){
                if(A[i]==B[j]){
                    continue;
                }else{
                    Ans[count] = A[i];
                    count++;
                }
            }
        }

        if(count < 15){
            Ans[count] = EOF;
        }
        

        for(i=0;i<15;i++){
            while(Ans[i] != EOF){
                printf(" %d",Ans[i]);
            }
        }


    printf("}\n");

    /*
    printf("積集合 A n B = {");
    //ｵﾗｵﾗｵﾗｵﾗｵﾗｵﾗｵﾗ!!!!!!
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            if(A[i]==B[j]){printf("%d ",A[i]);}
            else{continue;}
        }
    }
    printf("}\n");
    */
    fclose(fp);
}