#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void scaling(int arr[8])
{

    int sx, sy;
    printf("enter sx and sy");
    scanf("%d %d",&sx,&sy);
    int gm , gd= DETECT;
    initgraph(&gd,&gm,"");
    drawpoly(4,arr);
    outtextxy(260,500,"Before Scaling");
    for(int i=0;i<8;i++)
    {

        if(i%2==0){
            arr[i]=arr[i]*sx;
        }
        else{
            arr[i]=arr[i]*sy;
        }
    }
    drawpoly(4,arr);
      int centerX = 0, centerY = 0;
    for (int i = 0; i < 8; i += 2) {
        centerX += arr[i];
        centerY += arr[i + 1];
    }
    centerX /= 4;
    centerY /= 4;

    // Adjust the position of the text after scaling
    outtextxy(centerX - textwidth("After Scaling") / 2, centerY + 20, "After Scaling");
}
void rotation(int arr[8])
{
    float angle;
    float rd;
    printf("Enter the rotation angle");
    scanf("%f",&angle);
    rd=(3.14/180)*angle;
    int gm,gd=DETECT;
    initgraph(&gd,&gm,"");
    drawpoly(4,arr);
    outtextxy(260,500,"Before Rotation");
    for(int i=0;i<8;i++)
    {

        if(i%2==0)
        {

            arr[i]=arr[i]*cos(rd)-arr[i+1]*sin(rd);
        }
        else{
            arr[i]=arr[i-1]*sin(rd)+arr[i]*cos(rd);
        }
        printf("%d\t",arr[i]);
    }
    drawpoly(4,arr);
     int maxX = arr[0], maxY = arr[1], minX = arr[0], minY = arr[1];
    for (int i = 2; i < 8; i += 2) {
        if (arr[i] > maxX) maxX = arr[i];
        if (arr[i] < minX) minX = arr[i];
    }
    for (int i = 3; i < 8; i += 2) {
        if (arr[i] > maxY) maxY = arr[i];
        if (arr[i] < minY) minY = arr[i];
    }
    int centerX = (maxX + minX) / 2;
    int centerY = (maxY + minY) / 2;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(centerX - textwidth("After Rotation") / 2, maxY + 20, "After Rotation");

    // Draw the "Before Rotation" text after rotating the polygon
    outtextxy(260, 500, "Before Rotation");
}

void translation(int arr[8])
{
    int tx,ty;
    printf("Enter the value of tx,ty");
    scanf("%d %d",&tx,&ty);
    int gm, gd=DETECT;
    initgraph(&gd,&gm,"");
    drawpoly(4,arr);
     settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(260,500,"Before Translation");
    for(int i=0;i<8;i++)
    {

        if(i%2==0){
            arr[i]=arr[i]+tx;
        }
        else{
            arr[i]=arr[i]+ty;
        }
    }
    drawpoly(4,arr);
     settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(260+tx+10,500+ty+10,"After translation");
}
int main()
{

    int vertices[]={250,490,400,490,350,300,250,490};
    //translation(vertices);
    //rotation(vertices);
    scaling(vertices);
    getch();
    return 0 ;
}
