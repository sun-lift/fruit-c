#include <graphics.h>

#include <stdio.h>

#include <stdlib.h>

#include<dos.h>

#include<conio.h>

int start(void);
int getmouse(int * x, int * y);
int main(void) {
    int m_x, m_y;
    start();
    setbkcolor(GREEN);
    bar(0,0,100,100);
    while (1) {
        
        setcolor(YELLOW);
        getmouse( & m_x, & m_y);
    }
    return 0;
}
int getmouse(int * x, int * y) {
    static union REGS r;
    r.x.ax = 3;
    int86(0x33, & r, & r);
    * x = r.x.cx;
    * y = r.x.dx;
    printf("(%d,%d)\t\r", * x, * y);
    circle(*x,*y,30);
    return 0;
}
int start(void) {

    int gdriver = DETECT, gmode, errorcode;
    initgraph( & gdriver, & gmode, "C:\\BORLANDC\\BGI");
    cleardevice();
    errorcode = graphresult();
    if (errorcode != grOk) {
        printf("Graphics error: %s/n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getchar();
        exit(1);
    }

    return 0;
}