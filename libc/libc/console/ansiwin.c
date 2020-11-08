//--------------------------------------------------------------------------------------------
// ansiwin.c - ansi windows.
// (C) 1999-2003 by Jari Tuominen
//--------------------------------------------------------------------------------------------
#include <stdio.h>
#include "ansiwin.h"

/////////////////////////////////////////////////////////////////////////////
//DRAWANSIWINDOW
//
//Description :
//
//This function is a very nice function to draw Windows,
//it can also setup window arrays, if requested.
//
//      ***************
//      ***************
//      *************** <-- First of all, if fill is set to TRUE (!=0),
//      ***************     it'll fill window area with empty character.
//      ***************
//
//
//   x1,y1
//      ---------------
//      |             |
//      |             | <-- Type&127
//      |             |
//      ---------------
//                  x2,y2
//
//
//      Type :
//
//              1 = Inactive window
//              2 = Active window
//              3 = Inactive window + headline
//              4 = Active window + headline
//
//      If you "OR" 128 to the TYPE then drawansiwindow function will
//      call function "window" to setup window borders.
//
//      Notice: Drawansiwindow moves cursor inside the window, if not
//              requested to not to do it.
//
//
void DrawAnsiWindow(int x1,int y1,int x2,int y2,
		int type, char *headline,int fill)
{
	char stringi[100];
	register unsigned x,y;

	//
	for(x=0; x<(x2-x1); x++)stringi[x]=' '; stringi[x]=0;
	for(x=0; x<(x2-x1); x++)stringi[x]=' '; stringi[x]=0;
//	window(1,1,80,25);

	//
	if(fill!=0)
	{
		for(y=y1; y<y2; y++)
		{
			gotoxy(x1,y);
			printf("%s", stringi);
		}
	}

	//
	if((type&127)==0)
	{
		//
		gotoxy(x1,y1); printf("�");
		gotoxy(x2,y1); printf("�");
		gotoxy(x1,y2); printf("�");
		gotoxy(x2,y2); printf("�");
		for(x=x1+1; x<x2; x++){gotoxy(x,y1); printf("�");}
		for(x=x1+1; x<x2; x++){gotoxy(x,y2); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x1,y); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x2,y); printf("�");}
//		if((type&128)!=0) window(x1+1,y1+1,x2-1,y2-1);
	}

	//
	if((type&127)==1)
	{
		//
		gotoxy(x1,y1); printf("�");
		gotoxy(x2,y1); printf("�");
		gotoxy(x1,y2); printf("�");
		gotoxy(x2,y2); printf("�");
		for(x=x1+1; x<x2; x++){gotoxy(x,y1); printf("�");}
		for(x=x1+1; x<x2; x++){gotoxy(x,y2); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x1,y); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x2,y); printf("�");}
//		if((type&128)!=0) window(x1+1,y1+1,x2-1,y2-1);
	}

	//
	if((type&127)==2)
	{
		//
		gotoxy(x1,y1); printf("�");
		gotoxy(x2,y1); printf("�");
		gotoxy(x1,y2); printf("�");
		gotoxy(x2,y2); printf("�");
		gotoxy(x1+1,y1+1); printf("%s", headline);
		for(x=x1+1; x<x2; x++){gotoxy(x,y1+2); printf("�");}
		for(x=x1+1; x<x2; x++){gotoxy(x,y1); printf("�");}
		for(x=x1+1; x<x2; x++){gotoxy(x,y2); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x1,y); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x2,y); printf("�");}
		gotoxy(x1,y1+2); printf("�");
		gotoxy(x2,y1+2); printf("�");
//		if((type&128)!=0) window(x1+1,y1+3,x2-1,y2-1);
	}

	//
	if((type&127)==3)
	{
		//
		gotoxy(x1,y1); printf("�");
		gotoxy(x2,y1); printf("�");
		gotoxy(x1,y2); printf("�");
		gotoxy(x2,y2); printf("�");
		gotoxy(x1+1,y1+1); printf("%s",headline);
		for(x=x1+1; x<x2; x++){gotoxy(x,y1+2); printf("�");}
		for(x=x1+1; x<x2; x++){gotoxy(x,y1); printf("�");}
		for(x=x1+1; x<x2; x++){gotoxy(x,y2); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x1,y); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x2,y); printf("�");}
		gotoxy(x1,y1+2); printf("�");
		gotoxy(x2,y1+2); printf("�");
//		if((type&128)!=0) window(x1+1,y1+3,x2-1,y2-1);
	}

	//
	if((type&127)==4)
	{
		//
		gotoxy(x1,y1); printf("�");
		gotoxy(x2,y1); printf("�");
		gotoxy(x1,y2); printf("�");
		gotoxy(x2,y2); printf("�");
		gotoxy(x1+1,y1+1); printf("                                                                           ");
		gotoxy(x1+1,y1+1); printf(headline);
		for(x=x1+1; x<x2; x++){gotoxy(x,y1+2); printf("�");}
		for(x=x1+1; x<x2; x++){gotoxy(x,y1); printf("�");}
		for(x=x1+1; x<x2; x++){gotoxy(x,y2); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x1,y); printf("�");}
		for(y=y1+1; y<y2; y++){gotoxy(x2,y); printf("�");}
		gotoxy(x1,y1+2); printf("�");
		gotoxy(x2,y1+2); printf("�");
//		if((type&128)!=0) window(x1+1,y1+3,x2-1,y2-1);

		//
		if(((type&127)==2 || (type&127)==4) && (type&128)==0 )gotoxy(x1+1,y1+3);
		if(((type&127)==1 && (type&128)==0))gotoxy(x1+1,y1+1);
		//
		if(((type&127)==2 || (type&127)==4) && (type&128)!=0 )gotoxy(1,1);
		if(((type&127)==1 && (type&128)!=0))gotoxy(1,1);
	}
}
