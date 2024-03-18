
//To implement area filling algorithm(Boundary Fill & Flood Fill)

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

    void Flood_Fill8C(int x,int y,int Old_Color,int Fill_Color)
    {
        printf("%d,%d\n",x,y);
        int CC=getpixel(x,y);
        if(CC==Old_Color)
        {
            putpixel(x,y,Fill_Color);
            Flood_Fill8C(x-1,y,Old_Color,Fill_Color);
            Flood_Fill8C(x,y-1,Old_Color,Fill_Color);
            Flood_Fill8C(x+1,y,Old_Color,Fill_Color);
            Flood_Fill8C(x,y+1,Old_Color,Fill_Color);

            Flood_Fill8C(x-1,y+1,Old_Color,Fill_Color);
            Flood_Fill8C(x+1,y+1,Old_Color,Fill_Color);
            Flood_Fill8C(x+1,y-1,Old_Color,Fill_Color);
            Flood_Fill8C(x-1,y-1,Old_Color,Fill_Color);
        }
    }

    int main(){
    int gd=DETECT,gm;
    int vertices[]={100,100,400,10,600,100,400,200,100,100};
        initgraph(&gd,&gm,"");
        setfillstyle(1,GREEN);
        fillpoly(5,vertices);

    int Old_Color=GREEN;
    int Fill_Color=RED;
    drawpoly(5,vertices);

    /*int Boundary_Color=WHITE;*/

        int x=350 ,y=105; ////Seed pixel(x,y)
        printf("SEED TABLE\n");

         /*Boundary_Fill4C( x, y, Boundary_Color, Fill_Color);*/
            Flood_Fill8C(x,y,Old_Color,Fill_Color);

    getch();
    return 0;

}
