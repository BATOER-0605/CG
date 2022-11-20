#include <stdio.h>
#include<math.h>



int main() {
	int i, j, k;
	int n;
	int com;

	double XYZ[4][5];
	double XYZc[4][5];
	double XYZe[4][5];
	double p[4];

	double T1[4][4];
	double T2[4][4];
	double T3[4][4];
	double TK[4][4];
	double TE[4][4];
	
	FILE* fp1;
	FILE* fp2;
	FILE* fp3;
	FILE* fp4;

	fp1 = fopen("file1.txt", "r");
	fp2 = fopen("file2.txt", "r");
	fp3 = fopen("fi3.txt", "w");
	fp4 = fopen("file4.txt", "w");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {

			if (i == j) { TK[i][j] = 1; }
			else { TK[i][j] = 0; }
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (i == j) { T1[i][j] = 1; }
			else { T1[i][j] = 0; }
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (i == j) { T2[i][j] = 1; }
			else { T2[i][j] = 0; }
		}
	}
	fscanf(fp2, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(fp2, "%lf %lf %lf", &XYZ[0][i], &XYZ[1][i], &XYZ[2][i]);
		XYZ[3][i] = 1;
	}

	for (;;) {
		fscanf(fp1, "%d", &com);
		switch (com) {

		case 1:
			fscanf(fp1, "%lf %lf %lf", &p[0], &p[1], &p[2]);

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == j) {

						switch (i) {

						case 0:T1[i][j] = p[0]; break;
						case 1:T1[i][j] = p[1]; break;
						case 2:T1[i][j] = p[2]; break;
						case 3:T1[i][j] =1; break;
						}
					}
					else { T1[i][j] = 0; }
				}
			}
			break;
		case 2:
			fscanf(fp1, "%lf %lf %lf %lf", &p[0], &p[1], &p[2], &p[3]);
			p[0] = p[0] * M_PI / 180.0;

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == j) { T1[i][j] = 1; }
					else if (i == 3 && j == 0) { T1[i][j] = p[1]; }
					else if (i == 3 && j == 1) { T1[i][j] = p[2]; }
					else if (i == 3 && j == 2) { T1[i][j] = p[3]; }
					else { T1[i][j] = 0; }
				}
			}

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == 0 && j == 0) { T2[i][j] = 1; }
					else if (i == 1 && j == 1) { T2[i][j] = cos(p[0]); }
					else if (i == 1 && j == 2) { T2[i][j] = -sin(p[0]); }
					else if (i == 2 && j == 1) { T2[i][j] = sin(p[0]); }
					else if (i == 2 && j == 2) { T2[i][j] = cos(p[0]); }
					else if (i == 3 && j == 3) { T2[i][j] =1; }
					else { T1[i][j] = 0; }
				}
			}

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					T3[i][j] = 0;

					for (k = 0; k < 4; k++) {
						T3[i][j] += T1[i][k] * T2[k][j];
					}
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == j) { T2[i][j] = 1; }
					else if (i == 3 && j == 0) { T2[i][j] = -p[1]; }
					else if (i == 3 && j == 1) { T2[i][j] = -p[2]; }
					else if (i == 3 && j == 2) { T2[i][j] = -p[3]; }
					else { T2[i][j] = 0; }
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					T1[i][j] = 0;

					for (k = 0; k < 4; k++) {
						T1[i][j] += T3[i][k] * T2[k][j];
					}
				}
			}

			break;
		case 3:
			fscanf(fp1, "%lf %lf %lf %lf", &p[0], &p[1], &p[2], &p[3]);
			p[0] = p[0] * M_PI / 180.0;

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == j) { T1[i][j] = 1; }
					else if (i == 3 && j == 0) { T1[i][j] = p[1]; }
					else if (i == 3 && j == 1) { T1[i][j] = p[2]; }
					else if (i == 3 && j == 2) { T1[i][j] = p[3]; }
					else { T1[i][j] = 0; }
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == 0 && j == 0) { T2[i][j] = cos(p[0]); }
					else if (i == 0 && j == 2) { T2[i][j] = sin(p[0]); }
					else if (i == 1 && j == 1) { T2[i][j] = 1; }
					else if (i == 2 && j == 0) { T2[i][j] = -sin(p[0]); }
					else if (i == 2 && j == 2) { T2[i][j] = cos(p[0]); }
					else if (i == 3 && j == 3) { T2[i][j] = 1; }
					else { T1[i][j] = 0; }
				}
			}

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					T3[i][j] = 0;

					for (k = 0; k < 4; k++) {
						T3[i][j] += T1[i][k] * T2[k][j];
					}
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == j) { T2[i][j] = 1; }
					else if (i == 3 && j == 0) { T2[i][j] = -p[1]; }
					else if (i == 3 && j == 1) { T2[i][j] = -p[2]; }
					else if (i == 3 && j == 2) { T2[i][j] = -p[3]; }
					else { T2[i][j] = 0; }
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					T1[i][j] = 0;

					for (k = 0; k < 4; k++) {
						T1[i][j] += T3[i][k] * T2[k][j];
					}
				}
			}

			break;
		case 4:
			fscanf(fp1, "%lf %lf %lf %lf", &p[0], &p[1], &p[2], &p[3]);
			p[0] = p[0] * M_PI / 180.0;

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == j) { T1[i][j] = 1; }
					else if (i == 3 && j == 0) { T1[i][j] = p[1]; }
					else if (i == 3 && j == 1) { T1[i][j] = p[2]; }
					else if (i == 3 && j == 2) { T1[i][j] = p[3]; }
					else { T1[i][j] = 0; }
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == 0 && j == 0) { T2[i][j] = cos(p[0]); }
					else if (i == 0 && j == 1) { T2[i][j] = -sin(p[0]); }
					else if (i == 1 && j == 0) { T2[i][j] = sin(p[0]); }
					else if (i == 1 && j == 1) { T2[i][j] = cos(p[0]); }
					else if (i == 2 && j == 2) { T2[i][j] = 1; }
					else if (i == 3 && j == 3) { T2[i][j] = 1; }
					else { T1[i][j] = 0; }
				}
			}

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					T3[i][j] = 0;

					for (k = 0; k < 4; k++) {
						T3[i][j] += T1[i][k] * T2[k][j];
					}
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == j) { T2[i][j] = 1; }
					else if (i == 3 && j == 0) { T2[i][j] = -p[1]; }
					else if (i == 3 && j == 1) { T2[i][j] = -p[2]; }
					else if (i == 3 && j == 2) { T2[i][j] = -p[3]; }
					else { T2[i][j] = 0; }
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					T1[i][j] = 0;

					for (k = 0; k < 4; k++) {
						T1[i][j] += T3[i][k] * T2[k][j];
					}
				}
			}

			break;

		case 5:
			fscanf(fp1, "%lf %lf %lf", &p[0], &p[1], &p[2]);

			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (i == j) { T1[i][j] = 1; }
					else if (i == 3 && j == 0) { T1[i][j] = p[0]; }
					else if (i == 3 && j == 1) { T1[i][j] = p[1]; }
					else if (i == 3 && j == 2) { T1[i][j] = p[2]; }
				}
			}
			break;

		case 0:
			break;
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < 4; j++) {
				XYZc[j][i] = 0;
				for (k = 0; k < 4; k++) {
					XYZc[j][i] += T1[j][k] * XYZ[k][i];
				}
			}
		}
		for (i = 0; i < n; i++) {	
			fprintf(fp3, "%lf %lf %lf\n", XYZc[0][i], XYZc[1][i], XYZc[2][i]);
				}
			fprintf(fp3, "\n");

			for(i=0;i<4;i++){
				for (j = 0; j < 4; j++) {
					TE[i][j] = 0;
					for (k = 0; k < 4; k++) {
						TE[i][j] += T1[i][k] * TK[k][j];
					}
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					TK[i][j] = TE[i][j];
				}
			}
			if (com == 0) { break; }
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < 4; j++) {
			XYZe[j][i] = 0;

			for (k = 0; k < 4; k++) {
				XYZe[j][i] += TE[j][k] * XYZ[k][i];
			}
		}
	}

	for (i = 0; i < 4; i++) {
		printf("|");
		for (j = 0; j < 4; j++) {
			if (TE[i][j] >= 0) {
				printf(" ");
			}

			if (0 <= TE[i][j] && TE[i][j] < 10) {
				printf(" ");
			}
			if (-10 <= TE[i][j] && TE[i][j] < 0) {
				printf(" ");
			}
			printf("%.1lf ", TE[i][j]);
		}
		printf("|\n");
	}
	for (i = 0; i < n; i++) {
		fprintf(fp4, "%lf %lf %lf\n", XYZe[0][i], XYZe[1][i], XYZe[2][i]);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);

	return 0;
}




