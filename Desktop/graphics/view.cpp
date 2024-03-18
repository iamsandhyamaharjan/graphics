//to implement window-to-viewport coordinate transformation
//window={10,10,500,400}
//viewport={800,200,1000,700}
//object={50,300,85,130,120,300}
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
{
    int Xwmin=10, Ywmin=10, Xwmax=500, Ywmax=400;
    int Xvmin=800, Yvmin=200, Xvmax=1000, Yvmax=700;

    float Sx,Sy;
    Sx=(Xvmax-Xvmin)/float(Xwmax-Xwmin);
    Sy=(Yvmax-Yvmin)/float(Ywmax-Ywmin);

    int Window[]={10,10,500,10,500,400,10,400,10,10};
    int Viewport[]={800,200,1000,200,1000,700,800,700,800,200};
    int object[]={50,300,85,130,120,300,50,300};

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
setlinestyle(1,2,1);


    drawpoly(5,Window);
    outtextxy(255,410,"WINDOW");

    drawpoly(5,Viewport);
    outtextxy(900,710,"VIEWPORT");
setlinestyle(0,2,1);
    drawpoly(4,object);


    //Step 1; Translate window along with object such that its lower left corner coincides with origin. That is I(-Xwmin,-Ywmin)=T(-10,-10)
    for(int i=0;i<8;i++)
    {

        if(i%2==0)
        {
            object[i]=object[i]-Xwmin;
        }
        else{
            object[i]=object[i]-Ywmin;
        }
    }

    //Step 2: Scale window such that it has the same size as that of viewport. S(Sx,Sy);
        for(int i=0;i<8;i++)
    {

        if(i%2==0)
        {
            object[i]=object[i]*Sx;
        }
        else{
            object[i]=object[i]*Sy;
        }
    }

    //Step 3: Translate window such that it reaches to the position of viewport. T(Xvmin,Yvmin)
        for(int i=0;i<8;i++)
    {

        if(i%2==0)
        {
            object[i]=object[i]+Xvmin;
        }
        else{
            object[i]=object[i]+Yvmin;
        }
    }

    drawpoly(4,object);
    getch();
    return 0;
}



