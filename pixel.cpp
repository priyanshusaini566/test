#include<graphics.h>
#include<math.h>
#include<conio.h>

int main(){
    int gd = DETECT, gm;
    float x,y,dx,dy,steps,xinc,yinc;
    int x1=2,y1=2,x2=8,y2=5,i;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy)){
        steps=abs(dx);
    }
    else{
        steps=abs(dy);
    }
    xinc=dx/steps;
    yinc=dy/steps;

    x=x1;
    y=y1;

    for(i=0;i<=steps;i++){
        x=x+xinc;
        y=y+yinc;
    }
    getch();
    closegraph();
    return 0;
}