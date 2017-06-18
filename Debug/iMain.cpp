/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
#include "iGraphics.h"

int x[100],y[100],xp[100];
int len=0;
int i,j,num=1,val=1,dx=7,dy=7;
int leftup_x=0,leftdown_x=0,upleft_x=0,upright_x=0,rightup_x=0,rightdown_x=0,downleft_x=0,downright_x=0;
int up=0,down=0,left=0,right=1;

int ex=7; // snake lenth

int x1,y2,k;

int se = 120;


int game_x=0,game_y=0;

void SnakeMove()
{
	for(i=0;i<ex;i++)
	{
		x[i] = x[i] + dx;
	}
}
void Moveleftup()
{
      if(leftup_x==1)
	  {
		  for(int i=val;i<ex;i++)
		  {
			  x[i] = x[i] - dx;
		  }
		  val++;
	  }
	  for(int i=0;i<num;i++)
	  {
		  y[i] = y[i] + dy;
	  }
	  
	  num++;
	  
	  if(num==ex+1){num=ex;leftup_x=0;}	  
}
void Moveleftdown()
{
      if(leftdown_x==1)
	  {
		  for(int i=val;i<ex;i++)
		  {
			  x[i]=x[i]-dx;
		  }
		  val++;
	  }
	  for(int i=0;i<num;i++)
	  {
		  y[i]=y[i]-dy;		  
	  }
	  num++;
	  if(num==ex+1){num=ex;leftdown_x=0;}	
}
void Moveupleft()
{
      if(upleft_x==1)
	  {
		  for(int i=val;i<ex;i++)
		  {
			  y[i]=y[i]+dy;
		  }
		  val++;
	  }
	  for(int i=0;i<num;i++)
	  {
		  x[i]=x[i]-dx;		  
	  }
	  num++;
	  if(num==ex+1){num=ex;upleft_x=0;}	
}
void Moveupright()
{
      if(upright_x==1)
	  {
		  for(int i=val;i<ex;i++)
		  {
			  y[i]=y[i]+dy;
		  }
		  val++;
	  }
	  for(int i=0;i<num;i++)
	  {
		  x[i]=x[i]+dx;		  
	  }
	  num++;
	  if(num==ex+1){num=ex;upright_x=0;}	
}
void Moverightdown()
{
      if(rightdown_x==1)
	  {
		  for(int i=val;i<ex;i++)
		  {
			  x[i]=x[i]+dx;
		  }
		  val++;
	  }
	  for(int i=0;i<num;i++)
	  {
		  y[i]=y[i]-dy;		  
	  }
	  num++;
	  if(num==ex+1){num=ex;rightdown_x=0;}	
}
void Moverightup()
{
      if(rightup_x==1)
	  {
		  for(int i=val;i<ex;i++)
		  {
			  x[i]=x[i]+dx;
		  }
		  val++;
	  }
	  for(int i=0;i<num;i++)
	  {
		  y[i]=y[i]+dy;		  
	  }
	  num++;
	  if(num==ex+1){num=ex;rightup_x=0;}	
}
void Movedownleft()
{
      if(downleft_x==1)
	  {
		  for(int i=val;i<ex;i++)
		  {
			  y[i]=y[i]-dy;
		  }
		  val++;
	  }
	  for(int i=0;i<num;i++)
	  {
		  x[i]=x[i]-dx;		  
	  }
	  num++;
	  if(num==ex+1)
	  {
		  num=ex;downleft_x=0;
	  }
}
void Movedownright()
{
      if(downright_x==1)
	  {
		  for(int i=val;i<ex;i++)
		  {
			  y[i]=y[i]-dy;
		  }
		  val++;
	  }
	  for(int i=0;i<num;i++)
	  {
		  x[i]=x[i]+dx;		  
	  }
	  num++;
	  if(num==ex+1)
	  {
		  num=ex;downright_x=0;
	  }	
}

void iDraw()
{	
	iClear();
	iSetColor(0,126,0);	                     // Snake building
	for(i=0;i<ex;i++)
	{
		iFilledRectangle(x[i],y[i],5,5);
	}
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	// place your code here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key== GLUT_KEY_UP)
	{
		if (left==1)
		{
			k = 0;
			leftup_x = 1;
			up=1;
			down=left=right=0;
			num=1;
			val=1;
			iPauseTimer (0);
			iResumeTimer (1);
			iPauseTimer (2);
			iPauseTimer (3);
			iPauseTimer (4);
			iPauseTimer (5);
			iPauseTimer (6);
			iPauseTimer (7);
			iPauseTimer (8);
		}
		else if (right==1)
		{
			rightup_x = 1;
			up=1;
			down=left=right=0;
			num=1;
			val=1;
			iPauseTimer (0);
			iPauseTimer (1);
			iPauseTimer (2);
			iPauseTimer (3);
			iPauseTimer (4);
			iResumeTimer (5);
			iPauseTimer (6);
			iPauseTimer (7);
			iPauseTimer (8);
		}
		while(key!= GLUT_KEY_UP) break;
	}
	
	if(key== GLUT_KEY_DOWN)
	{
		k = 0;
		if (left==1)
		{
			leftdown_x = 1;
			down=1;
			up=left=right=0;
			num=1;
			val=1;
			iPauseTimer (0);
			iPauseTimer (1);
			iResumeTimer (2);
			iPauseTimer (3);
			iPauseTimer (4);
			iPauseTimer (5);
			iPauseTimer (6);
			iPauseTimer (7);
			iPauseTimer (8);
		}
		else if (right==1)
		{
			rightdown_x = 1;
			down=1;
			up=left=right=0;
			num=1;
			val=1;
			iPauseTimer (0);
			iPauseTimer (1);
			iPauseTimer (2);
			iPauseTimer (3);
			iPauseTimer (4);
			iPauseTimer (5);
			iResumeTimer (6);
			iPauseTimer (7);
			iPauseTimer (8);
		}
		while(key!= GLUT_KEY_DOWN) break;
	}
	
	if(key== GLUT_KEY_LEFT)
	{
		k = 0;
		if (up==1)
		{
			upleft_x = 1;	
			left=1;
			up=down=right=0;
			num=1;
			val=1;
			iPauseTimer (0);
			iPauseTimer (1);
			iPauseTimer (2);
			iResumeTimer (3);
			iPauseTimer (4);
			iPauseTimer (5);
			iPauseTimer (6);
			iPauseTimer (7);
			iPauseTimer (8);
		}
		else if (down==1)
		{
			downleft_x = 1;
			left=1;
			up=down=right=0;
			num=1;
			val=1;
			iPauseTimer (0);
			iPauseTimer (1);
			iPauseTimer (2);
			iPauseTimer (3);
			iPauseTimer (4);
			iPauseTimer (5);
			iPauseTimer (6);
			iResumeTimer (7);
			iPauseTimer (8);
		}
		while(key!= GLUT_KEY_LEFT) break;
	}
	
	if(key== GLUT_KEY_RIGHT)
	{
		k = 0;
		if (up==1)
		{
			upright_x = 1;
			right=1;
			up=down=left=0;
			num=1;
			val=1;
			iPauseTimer (0);
			iPauseTimer (1);
			iPauseTimer (2);
			iPauseTimer (3);
			iResumeTimer (4);
			iPauseTimer (5);
			iPauseTimer (6);
			iPauseTimer (7);
			iPauseTimer (8);
		}
		else if (down==1)
		{
			downright_x = 1;
			right=1;
			up=down=left=0;
			num=1;
			val=1;
			iPauseTimer (0);
			iPauseTimer (1);
			iPauseTimer (2);
			iPauseTimer (3);
			iPauseTimer (4);
			iPauseTimer (5);
			iPauseTimer (6);
			iPauseTimer (7);
			iResumeTimer (8);
		}
		while(key!= GLUT_KEY_RIGHT) break;
	} 
	
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

int main()
{
	x[0]=221;
	
	for (i=0;i<ex;i++)
	{
		x[i+1]=x[i]-7;
		y[i]=250;
	}
	iSetTimer (se,SnakeMove);
	iSetTimer (se,Moveleftup);
	iSetTimer (se,Moveleftdown);
	iSetTimer (se,Moveupleft);
	iSetTimer (se,Moveupright);
	iSetTimer (se,Moverightup);
	iSetTimer (se,Moverightdown);
	iSetTimer (se,Movedownleft);
	iSetTimer (se,Movedownright);

	iPauseTimer (0);
	iPauseTimer (1);
	iPauseTimer (2);
	iPauseTimer (3);
	iPauseTimer (4);
	iPauseTimer (5);
	iPauseTimer (6);
	iPauseTimer (7);
	iPauseTimer (8);
	iInitialize(800, 600, "demooo");
	return 0;
}