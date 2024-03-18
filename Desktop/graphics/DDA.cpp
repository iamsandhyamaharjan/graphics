#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int Round(float V){
if(V-int(V)>=0.5)
    return (int(V)+1);
else
    return (int(V));
}
int main()
{

    int i,gd=DETECT,gm;
    float x0,y0,xn,yn,X,Y,step_lenght,x_inc,y_inc,dx,dy;
    printf("enter x0 and y0: ");
    scanf("%f %f",&x0,&y0);
    printf("enter xn and yn: ");
    scanf("%f %f",&xn,&yn);
    dx=xn-x0;
    dy=yn-y0;
    initgraph(&gd,&gm,"");
    if(fabs(dx)>fabs(dy))
    {
        printf("when dx is greater than dy\n");
        step_lenght=fabs(dx);
    }

    else{
         printf("when dy is greater than dx\n");
         step_lenght=fabs(dy);
    }

    X=x0;
    Y=y0;
    x_inc=dx/step_lenght;
    y_inc=dy/step_lenght;
    printf("k\t\t\t\t(X,Y)\t\t\t\t\tPLOT(X,Y)\n");
    for(i=1;i<=step_lenght;i++)
    {
        putpixel(Round(X),Round(Y),WHITE);
        X=X+x_inc;
        Y=Y+y_inc;
        printf("%d\t\t\t\t(%.02f,%0.2f)\t\t\t\t(%d,%d)\n",i,X,Y,Round(X),Round(Y));


    }
  getch();
  return 0 ;
}
