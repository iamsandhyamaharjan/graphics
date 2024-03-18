#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void swap(int &x0,int &xn , int &y0,int &yn)
{
    int temp;
    temp=x0;
    x0=xn;
    xn=temp;
    temp=y0;
    y0=yn;
    yn=temp;
}
int main()
{

    int gm, gd=DETECT ;
    int x0,y0,xn,yn,dx,dy,a,p,X,Y,i;
    printf("Enter the values of x0 and y0");
    scanf("%d %d",&x0,&y0);
    printf("Enter the values of xn and yn");
    scanf("%d %d",&xn,&yn);
    dx=abs(xn-x0);
    dy=abs(yn-y0);
    if(xn-x0>0 && yn-y0<0 || xn-x0<0 && yn-y0>0)
    {
        a=-1;
    }
    else{
        a=1;
    }
    initgraph(&gd,&gm,"");
    if(dx>=dy)
    {
printf("when dx is greater than dy\n");
        if(x0>xn)
        {

            swap(x0,xn,y0,yn);
        }
        X=x0;
        Y=y0;
        putpixel(X,Y,RED);
        p=2*dy-dx;
        printf("k\t\t\tP\t\t\t(X,Y)\n");
        for(i=0;i<dx;i++)
        {

            if(p<0)
            {

                X=X+1;
                putpixel(X,Y,RED);
                p=p+2*dy;
                printf("%d\t\t\t%d\t\t\t(%d,%d)\n",i,p,X,Y);
            }
            else{
                X=X+1;
                Y=Y+a;
                putpixel(X,Y,RED);
                p=p+2*dy-2*dx;
                printf("%d\t\t\t%d\t\t\t(%d,%d)\n",i,p,X,Y);
            }
        }
    }
    else{
       printf("when dy is greater than dx\n");

      if(y0>yn)
        {

            swap(x0,xn,y0,yn);
        }
        X=x0;
        Y=y0;
        putpixel(X,Y,RED);
        p=2*dx-dy;
        printf("k\t\t\tP\t\t\t(X,Y)\n");
        for(i=0;i<dy;i++)
        {

            if(p<0)
            {

                Y=Y+1;
                putpixel(X,Y,RED);
                p=p+2*dx;
                printf("%d\t\t\t%d\t\t\t(%d,%d)\n",i,p,X,Y);
            }
            else{
                X=X+a;
                Y=Y+1;
                putpixel(X,Y,RED);
                p=p+2*dx-2*dy;
                printf("%d\t\t\t%d\t\t\t(%d,%d)\n",i,p,X,Y);
            }
        }
    }

    getch();
    return 0 ;
}
