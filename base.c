#include <stdio.h>
/*
set datafile separator ","
→呪文

ろじっく：
自分で考えろ。

まあ貴様如きにこの俺の考えが理解できるとは思えないが一応教えといてやろう。

1,前回のソースコードを元に
2,length分、x,y,zを移動させる。
3,完成

どうだ？できたか？
できるわけねーよなwwwバーロwwwwwwwww
所詮貴様はその程度さ
*/

/*言い訳タイム*/
/*
いや、理論上は動くんだけどさ。
なんでGNUplotだと今回作成分が動いてくれないん？
正確には読み込んでくれない感じ。
出力では正常に点は出せているんだが。
これはクソですね
クソオブクソ。
*/

void kuso(FILE *out,float,float n);
void kass(FILE *out,float,float n);
void gomi(FILE *out,float,float n);
void unko(FILE *out,float,float n);

int main(){

    FILE *OUTPUT = fopen("output.csv","w");

    float length;
    float n;
    printf("\n分割数を入れんかいごらぁぁぁぁぁぁぁぁぁ!!!!!!!!!\n");
    scanf("%f",&n);

    printf("変の長さを入れんかいゴラ: ");
    scanf("%f",&length);

    kass(OUTPUT,length,n);
    kuso(OUTPUT,length,n);
    gomi(OUTPUT,length,n);
    unko(OUTPUT,length,n);
}

void kuso(FILE *out,float length,float n) {

    float t,tt;
    int i;

    tt = 1 / n;
    t=0;

    float X,Y,Z;
    for(t=0;t<1.0;t+=tt){

        //原点
        X = 0;
        Y = 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n00
        X = (length - 0)*t +0;
        Y = 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0n0
        X = 0;
        Y = (length - 0)*t +0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //00n
        X = 0;
        Y = 0;
        Z = (length -0)+t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nn0
        X = length;
        Y = (length - 0)*t +0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nn0の原点に向かって行くver
        X = (0 - length)*t +length;
        Y = length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n0n
        X = length;
        Y = 0;
        Z = (length - 0)*t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnn
        X = length;
        Y = (length - 0)*t +0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnnの手前に引っ張ってくるver
        X = length;
        Y = length;
        Z = (0 - length)*t +length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n0nのX0に持ってくるver
        X = (0 - length)*t +length;
        Y = 0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0nn
        X = 0;
        Y = (length - 0)*t +0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnn
        X = (length - 0)*t +0;
        Y = length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0nnの手前に持ってくるver.
        X = 0;
        Y = length;
        Z = (0 - length)*t + length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

    }


    fclose(out);
}

void kass(FILE *out,float length,float n) {
    
    float t,tt;
    int i;

    tt = 1 / n;
    t=0;

    float X,Y,Z;
    for(t=0;t<1.0;t+=tt){

        //原点
        X = length;
        Y = 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n00
        X = (length - 0)*t +0+length;
        Y = 0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0n0
        X = 0+length;
        Y = (length - 0)*t +0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //00n
        X = 0+length;
        Y = 0;
        Z = (length -0)+t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nn0
        X = length+length;
        Y = (length - 0)*t +0;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nn0の原点に向かって行くver
        X = (0 - length)*t +length+length;
        Y = length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n0n
        X = length+length;
        Y = 0;
        Z = (length - 0)*t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnn
        X = length+length;
        Y = (length - 0)*t +0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnnの手前に引っ張ってくるver
        X = length+length;
        Y = length;
        Z = (0 - length)*t +length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n0nのX0に持ってくるver
        X = (0 - length)*t +length+length;
        Y = 0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0nn
        X = 0+length;
        Y = (length - 0)*t +0;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnn
        X = (length - 0)*t +0+length;
        Y = length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0nnの手前に持ってくるver.
        X = 0+length;
        Y = length;
        Z = (0 - length)*t + length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

    }

    fclose(out);
}

void gomi(FILE *out,float length,float n) {

    float t,tt;
    int i;

    tt = 1 / n;
    t=0;

    float X,Y,Z;
    for(t=0;t<1.0;t+=tt){

        //原点
        X = 0;
        Y = 0+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n00
        X = (length - 0)*t +0;
        Y = 0+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0n0
        X = 0;
        Y = (length - 0)*t +0+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //00n
        X = 0;
        Y = 0+length;
        Z = (length -0)+t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nn0
        X = length;
        Y = (length - 0)*t +0+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nn0の原点に向かって行くver
        X = (0 - length)*t +length;
        Y = length+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n0n
        X = length;
        Y = 0+length;
        Z = (length - 0)*t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnn
        X = length;
        Y = (length - 0)*t +0+length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnnの手前に引っ張ってくるver
        X = length;
        Y = length+length;
        Z = (0 - length)*t +length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n0nのX0に持ってくるver
        X = (0 - length)*t +length;
        Y = 0+length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0nn
        X = 0;
        Y = (length - 0)*t +0+length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnn
        X = (length - 0)*t +0;
        Y = length+length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0nnの手前に持ってくるver.
        X = 0;
        Y = length+length;
        Z = (0 - length)*t + length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

    }


    fclose(out);
}

void unko(FILE *out,float length,float n) {

    float t,tt;
    int i;

    tt = 1 / n;
    t=0;

    float X,Y,Z;
    for(t=0;t<1.0;t+=tt){

        //原点
        X = 0+length;
        Y = 0+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n00
        X = (length - 0)*t +0+length;
        Y = 0+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0n0
        X = 0+length;
        Y = (length - 0)*t +0+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //00n
        X = 0+length;
        Y = 0+length;
        Z = (length -0)+t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nn0
        X = length+length;
        Y = (length - 0)*t +0+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nn0の原点に向かって行くver
        X = (0 - length)*t +length+length;
        Y = length+length;
        Z = 0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n0n
        X = length+length;
        Y = 0+length;
        Z = (length - 0)*t +0;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnn
        X = length+length;
        Y = (length - 0)*t +0+length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnnの手前に引っ張ってくるver
        X = length+length;
        Y = length+length;
        Z = (0 - length)*t +length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //n0nのX0に持ってくるver
        X = (0 - length)*t +length+length;
        Y = 0+length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0nn
        X = 0+length;
        Y = (length - 0)*t +0+length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //nnn
        X = (length - 0)*t +0+length;
        Y = length+length;
        Z = length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

        //0nnの手前に持ってくるver.
        X = 0+length;
        Y = length+length;
        Z = (0 - length)*t + length;
        printf("%f,%f,%f\n", X, Y,Z);
        fprintf(out, "%f,%f,%f\n", X,Y,Z);

    }


    fclose(out);
}