#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delayp(float number_of_seconds)
{
    // Converting time into milli_seconds
    float milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
int poscheck(int rock1[4],int rock2[4],int rock3[4],int rock4[4],int xtop,int xbot,int ytop)
{
    if(xtop<=455||xbot>=1385)
    {
        return 0;
    }
    else if(((rock1[2]>=xtop&&rock1[2]<=xbot)||(rock1[0]>=xtop&&rock1[0]<=xbot))&&(rock1[3]==ytop))
    {
        return 0;
    }
    else if(((rock2[2]>=xtop&&rock2[2]<=xbot)||(rock2[0]>=xtop&&rock2[0]<=xbot))&&(rock2[3]==ytop))
    {
        return 0;
    }
    else if(((rock3[2]>=xtop&&rock3[2]<=xbot)||(rock3[0]>=xtop&&rock3[0]<=xbot))&&(rock3[3]==ytop))
    {
        return 0;
    }
    else if(((rock4[2]>=xtop&&rock4[2]<=xbot)||(rock4[0]>=xtop&&rock4[0]<=xbot))&&(rock4[3]==ytop))
    {
        return 0;
    }
    else
        return 1;
}
int main()
{ int load=219,page=0,track=0;
float score=0;
int go,check;
int xtop=850,ytop=800,xbot=920,ybot=870;
int rock1[4],rock2[4],rock3[4],rock4[4],rockcol[8],mainbox[2];
srand(time(NULL));
rock1[0]=(rand()%(235))+600;
rock1[1]=(rand()%(401))+200;
rock1[2]=rock1[0]+30;
rock1[3]=rock1[1]+30;
rock2[0]=(rand()%(152))+834;
rock2[1]=(rand()%(401))+200;
rock2[2]=rock2[0]+30;
rock2[3]=rock2[1]+30;
rock3[0]=(rand()%(216))+985;
rock3[1]=(rand()%(401))+200;
rock3[2]=rock3[0]+30;
rock3[3]=rock3[1]+30;
rock4[0]=(rand()%(501))+600;
rock4[1]=(rand()%(401))+200;
rock4[2]=rock4[0]+30;
rock4[3]=rock4[1]+30;
rockcol[0]=rock1[0]+5;
rockcol[1]=rock1[1]+5;
rockcol[2]=rock2[0]+5;
rockcol[3]=rock2[1]+5;
rockcol[4]=rock3[0]+5;
rockcol[5]=rock3[1]+5;
rockcol[6]=rock4[0]+5;
rockcol[7]=rock4[1]+5;
mainbox[0]=xtop+5;
mainbox[1]=ytop+5;
char text[20];

gotoxy(51,11);

	{
	cout<<"Loading..."<<endl;
	gotoxy(51,12);
	for(int i=0;i<15;i++)
	{
		delayp(0.2);
		cout<<char(load);
	}
	}
system("cls");

DWORD swidth = GetSystemMetrics(SM_CXSCREEN);
DWORD sheight = GetSystemMetrics(SM_CYSCREEN);
initwindow(1920,1080);
settextstyle(9,0,5);
outtextxy(700,520,"DODGE THE ROCKS");
settextstyle(4,0,2);
outtextxy(600,600,"PRESS THE ARROW KEYS TO DODGE THE ROCKS");
getch();
closegraph();
initwindow(swidth,sheight,"",0,0);
int k=0;
char temp[20];
while(k<3)
{
    sprintf(temp,"STARTING IN : %d",k+1);
    settextstyle(9,0,5);
    outtextxy(700,520,temp);
    ++k;
    delayp(1);
}
while(1)
{

    setactivepage(page);
    setvisualpage(1-page);
    cleardevice();
    if(track==1)
    {
        delayp(3);
        getch();
        exit(0);
    }
    check=poscheck(rock1,rock2,rock3,rock4,xtop,xbot,ytop);
    if(check==0)
    {
        ++track;
        settextstyle(9,0,5);
        outtext("GAME OVER");
    }

    if(kbhit())
    {

        go=getch();

        switch (go)
        {
        case 72:
            ytop=ytop-10;
            ybot=ybot-10;
            break;
        case 80:
            ytop=ytop+10;
            ybot=ybot+10;
            break;
        case 75:
            xtop=xtop-10;
            xbot=xbot-10;
            break;
        case 77:
            xtop=xtop+10;
            xbot=xbot+10;
            break;
        case 27:
            exit(0);
        default:
            break;
        }
    }


    score=score+0.1;
    settextstyle(9,0,3);
    sprintf(text,"SCORE : %0.1f",score);
    outtextxy(1600,50,text);
    setlinestyle(0,4,3);
    line(0,900,682,200);
    line(0,200,swidth,200);
    line(swidth,900,1138,200);
    line(455,sheight,455,430);
    line(1385,sheight,1385,430);
    setlinestyle(1,4,1);
    line(910,sheight,910,200);
    setlinestyle(0,4,2);
    setfillstyle(1,4);
    rectangle(rock1[0],rock1[1]++,rock1[2],rock1[3]++);
    floodfill(rockcol[0],rockcol[1]++,15);
    if(rock1[1]>=sheight)
    {
        rock1[0]=(rand()%(235))+600;
        rock1[1]=(rand()%(401))+200;
        rock1[2]=rock1[0]+30;
        rock1[3]=rock1[1]+30;
        rockcol[0]=rock1[0]+5;
        rockcol[1]=rock1[1]+5;
    }
    setfillstyle(1,4);
    rectangle(rock2[0],rock2[1]++,rock2[2],rock2[3]++);
    floodfill(rockcol[2],rockcol[3]++,15);
    if(rock2[1]>=sheight)
    {
       rock2[0]=(rand()%(152))+834;
       rock2[1]=(rand()%(401))+200;
       rock2[2]=rock2[0]+30;
       rock2[3]=rock2[1]+30;
       rockcol[2]=rock2[0]+5;
       rockcol[3]=rock2[1]+5;
    }
    setfillstyle(1,4);
    rectangle(rock3[0],rock3[1]++,rock3[2],rock3[3]++);
    floodfill(rockcol[4],rockcol[5]++,15);
    if(rock3[1]>=sheight)
    {
       rock3[0]=(rand()%(216))+985;
       rock3[1]=(rand()%(401))+200;
       rock3[2]=rock3[0]+30;
       rock3[3]=rock3[1]+30;
       rockcol[4]=rock3[0]+5;
       rockcol[5]=rock3[1]+5;
    }
    setfillstyle(1,4);
    rectangle(rock4[0],rock4[1]++,rock4[2],rock4[3]++);
    floodfill(rockcol[6],rockcol[7]++,15);
    if(rock4[1]>=sheight)
    {
        rock4[0]=(rand()%(501))+600;
        rock4[1]=(rand()%(401))+200;
        rock4[2]=rock4[0]+30;
        rock4[3]=rock4[1]+30;
        rockcol[6]=rock4[0]+5;
        rockcol[7]=rock4[1]+5;
    }
    setfillstyle(3,14);
    rectangle(xtop,ytop,xbot,ybot);
    mainbox[0]=xtop+5;
    mainbox[1]=ytop+5;
    floodfill(mainbox[0],mainbox[1],15);
    page=1-page;

}

closegraph();

return 0;
}
