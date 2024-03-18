//To implement area filling algorithm(Boundary Fill & Flood Fill)

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

    void Boundary_Fill4C(int x,int y,int Boundary_Color,int Fill_Color)
    {
        printf("%d,%d\n",x,y);
        int CC=getpixel(x,y);
        if(CC!=Boundary_Color&&CC!=Fill_Color)
        {
            putpixel(x,y,Fill_Color);
            delay(10);
            Boundary_Fill4C(x-1,y,Boundary_Color,Fill_Color);
            Boundary_Fill4C(x,y-1,Boundary_Color,Fill_Color);
            Boundary_Fill4C(x+1,y,Boundary_Color,Fill_Color);
            Boundary_Fill4C(x,y+1,Boundary_Color,Fill_Color);

        }
    }

    int main(){
    int gd=DETECT,gm;
    int vertices[]={100,100,400,10,600,100,400,200,100,100};
    initgraph(&gd,&gm,"");
    drawpoly(5,vertices);

    int Boundary_Color=WHITE;
    int Old_Color=BLACK;
    int Fill_Color=RED;
        int x=350 ,y=105; ////Seed pixel(x,y)
        printf("SEED TABLE\n");

         Boundary_Fill4C( x, y, Boundary_Color, Fill_Color);
            /*Flood_Fill8C(x,y,Old_Color,Fill_Color);*/

    getch();
    return 0;

}
