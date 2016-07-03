#include <graphics.h>
#include <conio.h>
#include <stdio.h> 
#include <stdlib.h>

int cells[4][4]={{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,0}};

int cur_i, cur_j;


void cell(int i,int j, int k){
	char s[4];
	bar3d( i*100+300, j*100+100, 90+i*100+300, 90+j*100+100, 10, 0);
	itoa(k,s,10);
	setcolor(YELLOW);
	outtextxy(325+i*100,125+j*100,s);

}



void DrawField(){
	setfillstyle(SOLID_FILL, BLACK);
	bar(0,0,1000,600);
	setfillstyle(SOLID_FILL, WHITE);

	
	for(int j=0;j<4;j++)
		for(int i=0;i<4;i++){
			if(cells[j][i]) cell(i,j,cells[j][i]);
	}
}

void Start(){
	
	int k, ki,kj, li,lj, tmp;
	for(k=0;k<100;k++){
		ki=rand()%4;
		kj=rand()%4;
		li=rand()%4;
		lj=rand()%4;
		tmp=cells[li][lj];
		cells[li][lj]=cells[ki][kj];
		cells[ki][kj]=tmp;
	}
	DrawField();	
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	if(!cells[i][j]) {cur_i=j;cur_j=i;break;}
}

void fon(){
int y, c, k,d;
d=rand()%16;

for (y=0; y<540; y++)
	for(c=0;c<5400-y*10;c+=5){
	putpixel(y+rand()%(1920-2*y),y, YELLOW);
	putpixel(y+rand()%(1920-2*y),1080-y, RED);
	putpixel(y, y+rand()%(1080-2*y), LIGHTBLUE);
	putpixel(1920-y,y+rand()%(1080-2*y), d);
	//circle(rand()%1800,rand()%1000,rand()%240);
}
}


int main(){
	int k,c;
	int exitOk=0;
	int tmp;

	initwindow(1000, 600);
	settextstyle(2,0,25);
	Start();
	DrawField();

	while(!exitOk){
		c=getch();
		switch(c){
			case 27: exitOk=1;
			case 75: if(cur_i<3) {cells[cur_j][cur_i]=cells[cur_j][cur_i+1]; cells[cur_j][cur_i+1]=0; cur_i++;} break;
			case 77: if(cur_i>0) {cells[cur_j][cur_i]=cells[cur_j][cur_i-1]; cells[cur_j][cur_i-1]=0; cur_i--;}  break;
			case 72: if(cur_j<3) {cells[cur_j][cur_i]=cells[cur_j+1][cur_i]; cells[cur_j+1][cur_i]=0; cur_j++;}  break;
			case 80: if(cur_j>0) {cells[cur_j][cur_i]=cells[cur_j-1][cur_i]; cells[cur_j-1][cur_i]=0; cur_j--;}  break;
			default: break;
		}
		DrawField();
	}
	closegraph();
	return 0;
}
