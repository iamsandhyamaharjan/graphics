#include<stdio.h>
#include<conio.h>
#include<graphics.h>
draw(int X, int Y, int xc, int yc)
{
    putpixel(X+xc,Y+yc,1);
    putpixel(-X+xc,Y+yc,2);
    putpixel(-X+xc,-Y+yc,3);
    putpixel(X+xc,-Y+yc,4);
    putpixel(Y+xc,X+yc,5);
    putpixel(-Y+xc,X+yc,6);
    putpixel(-Y+xc,-X+yc,9);
    putpixel(Y+xc,-X+yc,4);

}
int main()
{

    int xc, yc, X,Y,r,p,X0,Y0,i;
    int gm, gd=DETECT;
    printf("Enter the center of the circle");
    scanf("%d %d",&xc,&yc);
    printf("Enter the radius of the circle");
    scanf("%d",&r);
    X0=r;
    Y0=0;
    p=1-r;
    X=X0;
    Y=Y0;
    initgraph(&gd,&gm,"");
    draw(X,Y,xc,yc);
    printf("K\t\t\tP\t\t\t(X,Y)\n");
    for(i=1;Y<X;i++)
    {
       printf("K\t\t\tP\t\t\t(X,Y)\n");
       for(i=1;Y<X;i++)
       {

           if(p<0)
           {
               Y=Y+1;
               p=p+2*Y+1;

           }
           else
            {
            X=X-1;
           Y=Y+1;
           p=p+2*Y-2*X+1;

           }
                          printf("%d\t\t\t%d\t\t\t(%d,%d)\n",i,p,X,Y);
                          draw(X,Y,xc,yc);

       }


    }
    getch();
    return 0 ;

}

