#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    int n;
    int mode;

    double XYZ[4][5];
    double XYZT[4][5];
    double XYZA[4][5];
    double P[4];

    double G1[4][4];
    double G2[4][4];
    double G3[4][4];
    double GZ[4][4];
    double GA[4][4];

    FILE* one = fopen("file1.txt","r");
    FILE* two = fopen("file2,txt","r");
    FILE* three = fopen("file3.txt","w");
    FILE* four = fopen("file4.txt","w");

    for(a=0;a<4;a++){
        for(b=0;b<4;b++){
            if(a==b){GZ[a][b] = 1;}
            else{GZ[a][b]=0;}

            if(a==b){G1[a][b] = 1;}
            else{G1[a][b] =0;}

            if(a==b){G2[a][b] = 1;}
            else{G2[a][b]= 0;}
        }
    }

    fscanf(two,"%d",&n);
    for(a=0;a<4;a++){
        fscanf(two,"%lf %lf %lf",&XYZ[0][a],&XYZ[1][a],&XYZ[2][a]);
        XYZ[3][a]=1;
    }

    for(;;){
        fscanf(one,"%d",&mode);
        switch(mode){
            case 1:
                fscanf(one,"%lf %lf %lf",&P[0],&P[1],&P[2]);
                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==b){
                            switch(a){
                                case 0:
                                    G1[a][b] = P[0];
                                    break;

                                case 1:
                                    G1[a][b] = P[1];
                                    break;

                                case 2:
                                    G1[a][b] = P[2];
                                    break;

                                case 3:
                                    G1[a][b] = 1;
                                    break;

                                default:
                                    printf("debug point 1\n");
                            }
                        }
                        else{G1[a][b] = 0;}
                    }
                }
                break;

            case 2:
                fscanf(one,"%lf %lf %lf",&P[0],&P[1],&P[2]);
                P[0] *= M_PI / 180.0;

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==b){G1[a][b] = 1;}
                        else if(a== 3 && b==0){G1[a][b] = P[1];}
                        else if(a== 3 && b==1){G1[a][b] = P[2];}
                        else if(a== 3 && b==2){G1[a][b] = P[3];}
                        else{G1[a][b] =0;}
                    }
                }
                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==0 && b==0){G2[a][b] =1;}
                        else if(a== 1 && b==1){G2[a][b] = cos(P[0]);}
                        else if(a== 1 && b==2){G2[a][b] = -sin(P[0]);}
                        else if(a== 2 && b==1){G2[a][b] = sin(P[0]);}
                        else if(a== 2 && b==2){G2[a][b] = cos(P[0]);}
                        else if(a== 3 && b==3){G2[a][b] = 1;}
                        else{G2[a][b] =0;}
                    }
                }
                        
                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        G3[a][b] =0;
                        for(c=0;c<4;c++){
                            G3[a][b]+=G1[a][c]*G2[c][b];
                        }
                    }
                }
                        
                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==b){G2[a][b] =1;}
                        else if(a==3 && b==0){G2[a][b] = -P[1];}
                        else if(a==3 && b==1){G2[a][b] = -P[2];}
                        else if(a==3 && b==2){G2[a][b] = -P[3];}
                        else{G2[a][b] = 0;}
                    }
                }
                        
                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        G1[a][b] = 0;
                        for(c=0;c<4;c++){
                            G1[a][b] += G3[a][b]*G2[c][b];
                        }
                    }
                }
                break;

            case 3:
                fscanf(one,"%lf %lf %lf %lf",&P[0],&P[1],&P[2],&P[3]);
                P[0] *= M_PI / 180.0;

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==b){G1[a][b]=1;}
                        else if(a==3 && b==0){G1[a][b] = P[1];}
                        else if(a==3 && b==1){G1[a][b] = P[2];}
                        else if(a==3 && b==2){G1[a][b] = P[3];}
                        else{G1[a][b] = 0;}
                    }
                }

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if (2 == 0 && b == 0){G2[a][b] = cos(P[0]);}
                        else if (a == 0 && b == 2){G2[a][b]=sin(P[0]);}
                        else if (a == 1 && b == 1) { G2[a][b] = 1;}
                        else if (a == 2 && b == 0) { G2[a][b] = - sin(P[0]); }
                        else if (a == 2 && b == 2) { G2[a][b] = cos (P[0]);}
                        else if (a == 3 && b == 3) { G2[a][b] = 1; }
                        else { G1[a][b] = 0; }
                    }
                }

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        G3[a][b]=0;
                        for(c=0;c<4;c++){
                            G3[a][b] += G1[a][c]* G2[c][b];
                        }
                    }
                }

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==b){G2[a][b]=1;}
                        else if(a==3 && b==0){G2[a][b] = -P[1];}
                        else if(a==3 && b==1){G2[a][b] = -P[2];}
                        else if(a==3 && b==2){G2[a][b] = -P[3];}
                        else{G2[a][b] =0;}
                    }
                }

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        G1[a][b] = 0;
                        for(c=0;c<4;c++){
                            G1[a][b] += G3[a][c]*G2[c][b];
                        }
                    }
                }
                break;

            case 4:
                fscanf(one,"%lf %lf %lf %lf",&P[0],&P[1],&P[2],&P[3]);
                P[0]+=M_PI / 180.0;

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==b){G1[a][b] =1;}
                        else if(a==3 && b == 0){G1[a][b] = P[1];}
                        else if(a==3 && b == 1){G1[a][b] = P[2];}
                        else if(a==3 && b == 2){G1[a][b] = P[3];}
                        else{G1[a][b] = 0;}

                    }
                }

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==0 && b==0){G2[a][b] = cos(P[0]);}
                        else if(a==0 && b==1){G2[a][b] = -sin(P[0]);}
                        else if(a==0 && b==1){G2[a][b] = sin(P[0]);}
                        else if(a==0 && b==1){G2[a][b] = cos(P[0]);}
                        else if(a==0 && b==1){G2[a][b] = 1;}
                        else if(a==0 && b==1){G2[a][b] = 1;}
                        else{G2[a][b] = 0;}
                    }
                }

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        G3[a][b] = 0;
                        for(c=0;c<4;c++){
                            G3[a][b] += G1[a][c]*G2[c][b];
                        }
                    }
                }

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a==b){G2[a][b] =1;}
                        else if(a==3 && b == 0){G2[a][b] = -P[1];}
                        else if(a==3 && b == 1){G2[a][b] = -P[2];}
                        else if(a==3 && b == 2){G2[a][b] = -P[3];}
                        else{G2[a][b] =0;}
                    }
                }

                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        G1[a][b] = 0;
                        for(c=0;c<4;c++){
                            G1[a][b] += G3[a][c] * G2[c][b];
                        }
                    }
                }
                break;

            case 5:
                fscanf(one,"%lf %lf %lf",&P[0],&P[1],&P[2]);
                for(a=0;a<4;a++){
                    for(b=0;b<4;b++){
                        if(a == b){G1[a][b] =1;}
                        else if(a==3 && b==0){G1[a][b] = P[0];}
                        else if(a==3 && b==1){G1[a][b] = P[1];}
                        else if(a==3 && b==2){G1[a][b] = P[2];}
                    }
                }
                break;

            case 0:
                break;

        }

        for(a=0;a<4;a++){
            for(b=0;b<4;b++){
                XYZT[b][a] = 0;

                for(c=0;c<4;c++){
                    XYZT[b][a] += G1[b][c]* XYZ[c][a];
                }
            }
        }

        for(a=0;a<n;a++){
            fprintf(three,"%lf %lf %lf\n",XYZT[0][a],XYZT[1][a],XYZT[2][a]);
        }
        fprintf(three,"\n");

        for(a=0;a<4;a++){
            for(b=0;b<4;b++){
                GA[a][b] = 0;
                for(c=0;c<4;c++){
                    GA[a][b] += G1[a][c]* GZ[c][b];
                }
            }
        }

        for(a=0;a<4;a++){
            for(b=0;b<4;b++){
                GZ[a][b] = GA[a][b];
            }
        }
        if(mode == 0){break;}
    }

    for(a=0;a<4;a++){
            for(b=0;b<4;b++){
                XYZA[b][a] = 0;
                for(c=0;c<4;c++){
                    XYZA[b][a] += GA[b][c] * XYZ[c][a];
                }
            }
        }

    for(a=0;a<4;a++){
        printf("|");
            for(b=0;b<4;b++){
                if(GA[a][b] >=0){printf(" ");}
                if(0<= GA[a][b] && GA[a][b]<10){printf(" ");}
                if(-10<=GA[a][b] && GA[a][b]<0){printf(" ");}

                printf("%.1lf ",GA[a][b]);
            }
            printf("|\n");
        }

        for(a=0;a<4;a++){
            fprintf(four,"%lf %lf %lf\n",XYZA[0][a],XYZA[1][a],XYZA[2][a]);
        }

        fclose(one);
        fclose(two);
        fclose(three);
        fclose(four);

        return 0;
}