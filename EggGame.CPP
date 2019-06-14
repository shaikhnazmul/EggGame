#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>




//////function for giving tips//////




void tips(){
 setbkcolor(0);
 printf("                              TIPS                       \n\n\n");
 printf("\n\n\n\nplease move your mouse from left to right or right to left to catch ");
 printf(" the EGGS. \n\n\n");
 printf ("\n While playing please do not press any button from your keyboard just use the \n");
 printf(" mouse, pressing any button from keyboard will cause the game to exit.\n\n\n");
 printf("                       press any key to continue \n\n\n\n\n\n\n\n\n" );
 getch();
}
 union REGS i,o;


 //////main function//////



 main()
 {
   int initmouse();   //// initializing mouse//////
   int restrictmouseptr(int,int,int,int);

   int getmousepos(int *,int *,int *);
   int showmouseptr();

  int gd=DETECT,gm,maxx,maxy,x,y,button;
  initgraph(&gd,&gm,"c://TURBOC3//BGI");   //// initializing graphics driver (default one)

  int count=0;
  maxx=getmaxx();
  maxy=getmaxy();
  setbkcolor(RED);
  outtextxy(200,200,"WELCOME TO OUR PROJECT GAME");
  outtextxy(250,300,"loading.......");
  delay(2000);
  clrscr();
  cleardevice();
  closegraph();
  initgraph(&gd,&gm,"c://TURBOC3//BGI");
  tips();

  initgraph(&gd,&gm,"c://TURBOC3//BGI");

  setbkcolor(BLUE);
  setviewport(0,0,maxx,maxy,1);
  gotoxy(26,1);

  if(initmouse()==0)
   {
    closegraph();
    restorecrtmode();
//to go back to normal graphics mode or deleting viewport.
    printf("mouse driver not loaded");
    exit(1);
   }
  restrictmouseptr(0,getmaxy()-20,maxx,getmaxy()-15);

   int a=30;int b=0;
  setcolor(0);
  setfillstyle(1,15);
  int score=0;
  count=20;
  int s=5;
  int level=0;
  char name[40];
  gotoxy(5,2);
  printf("PLEASE TYPE YOUR NAME AND PRESS enter:");
  gets(name);
  gotoxy(5,2);
  printf("");
   clrscr();
   cleardevice();
    setbkcolor(0);
  while(!kbhit())
   {
     getmousepos(&button,&x,&y);

      setcolor(14);
       setfillstyle(1,15);
       fillellipse(a,b,10,15);
       if((b>getmaxy()-20)&&(b<=getmaxy()-15))
// For checking the egg position.

	{
	 if(a>=(x-20)&&(a<=(x+60)))
	    {
	      score+=10;
	      gotoxy(320,2);
	      textcolor(13);
	      printf("Your Score:%d ",score);

	    }
	}
       if(b>getmaxy()+40)
       {
	b=0;
	a=random(getmaxx()); ///
	gotoxy(10,2);
	printf("Eggs Left:%d ",count);
	count--;
	if(count==-1)
	  {
	   gotoxy(32,10);
	   printf("LEVEL COMPLETED.");
	   level++;
	   if(level==4)
	   {
	   goto varun;
	   }
	   count=10;
	   s++;
	   getch();
	   gotoxy(32,10);
	  printf("                ");
	  }
       }
       setcolor(10);
       line(x,getmaxy(),x+40,getmaxy());
       line(x,getmaxy(),x-20,getmaxy()-20);
       line(x+40,getmaxy(),x+60,getmaxy()-20);
       line(x-20,getmaxy()-20,x+60,getmaxy()-20);
       delay(10);

       setcolor(0);
       line(x,getmaxy(),x+40,getmaxy());
       line(x,getmaxy(),x-20,getmaxy()-20);
       line(x+40,getmaxy(),x+60,getmaxy()-20);
       line(x-20,getmaxy()-20,x+60,getmaxy()-20);
       setfillstyle(1,0);
       fillellipse(a,b,10,15);
	b+=s;
     }
    varun:
    gotoxy(30,12);
    printf("EXCELLENT WORK BY: %s ",name);
    gotoxy(33,15);
    printf("GAME OVER.   ");
    gotoxy(32,18);
    printf("YOUR SCORE: %d",score);
    gotoxy(58,24);
    printf("DEVELOPED BY:");
    gotoxy(54,25);
    printf("Sk Nazmul Islam");
    gotoxy(55,26);
    printf("[161-35-125]");
    printf("                                                     Siddhertho Roy[161-35-138]");
    printf("                                                      Dip Kumar Kundu[161-35-142]");
    gotoxy(30,10);
    printf("GREATEST SCORE: %d", score);


    getch();
    getch();
    return 0;
    }


     initmouse()
    {
     i.x.ax=0;//for  initialising mouse.
     int86(0x33,&i,&o);
     return(o.x.ax);
    }

    showmouseptr()
    {
     i.x.ax=1; // for displaying mouse pointer.
     int86(0x33,&i,&o);
     return 0;
    }
    restrictmouseptr(int x1,int y1,int x2,int y2)
    {
     i.x.ax=7;     //to define the upper left boundry of mouse.
     i.x.cx=x1;
     i.x.dx=x2;
     int86(0x33,&i,&o);
     i.x.ax=8;   //to define the bottom right boundry of mouse.
     i.x.cx=y1;
     i.x.dx=y2;
     int86(0x33,&i,&o);
    }
   getmousepos(int *button,int *x, int *y)
   {
    i.x.ax=3; //to move mouse.
    int86(0x33,&i,&o);
    *button=o.x.bx;
    *x=o.x.cx;
    *y=o.x.dx;
    }

