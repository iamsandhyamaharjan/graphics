#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void draw(int x,int y,int xc,int yc)
{
    putpixel(x+xc,y+yc,1);
    putpixel(-x+xc,y+yc,2);
    putpixel(-x+xc,-y+yc,3);
    putpixel(x+xc,-y+yc,4);
    putpixel(y+xc,x+yc,5);
    putpixel(y+xc,-x+yc,6);
    putpixel(-y+xc,-x+yc,7);
    putpixel(-y+xc,x+yc,8);
}
int main()
{

    int gm,gd=DETECT;
    int x0,y0,xc,yc,X,Y,p,i,r;
    printf("enter the center of the circle");
    scanf("%d %d",&xc,&yc);
    printf("enter the radius of the circle");
    scanf("%d",&r);
    x0=0;
    y0=r;
    p=1-r;
    X=x0;
    Y=y0;
    initgraph(&gd,&gm,"");
    draw(X,Y,xc,yc);
    for(i=1;X<Y;i++)
    {
        if(p<0)
        {

            X=X+1;
            p=p+2*X+1;
            printf("%d\t\t\t%d\t\t\t(%d,%d)\n",i,p,X,Y);
        }
        else{
            X=X+1;
            Y=Y-1;
            p=p+2*X-2*Y+1;
            printf("%d\t\t\t%d\t\t\t(%d,%d)\n",i,p,X,Y);

        }
        draw(X,Y,xc,yc);

    }
    getch();
    return 0;
}
