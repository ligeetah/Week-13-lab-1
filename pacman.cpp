#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<fstream>
using namespace std;
int X=9,Y=31;
int score=0;
bool ft=1,st=0;
int gx=19 ,gy=25 ;
char maze[24][71]={
  
{"######################################################################"},
{"||.. .....................................................  ......  ||"}, 
{"||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%%  |%|..   %%%%   ||"}, 
{"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"}, 
{"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"}, 
{"||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%%%     ..   %%%%.  ||"}, 
{"||..        |%|       . . |%|...    ............... |%| ..       .  ||"}, 
{"||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| ..   %%%%.  ||"}, 
{"||..               |%|.             |%|......       |%| ..    |%|.  ||"}, 
{"||..     ......... |%|.        P    |%|......|%|        ..    |%|.  ||"}, 
{"||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%| |%|.  ||"}, 
{"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|         .|%|.      ||"}, 
{"||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||"}, 
{"||..|%|            .           ...|%|               |%| ..|%|.      ||"}, 
{"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"}, 
{"||...............................................   |%| ..........  ||"}, 
{"||   ............................................          .......  ||"}, 
{"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"}, 
{"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"}, 
{"||..|%|            .     G     ...|%|               |%| ..|%|.      ||"}, 
{"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"}, 
{"||...............................................   |%| ..........  ||"}, 
{"||  .............................................          .......  ||"}, 
{"######################################################################"}
};
void display()
{
    for (int x=0;x< 24;x++)
    {
        for(int m=0;m<70;m++)
        {
            cout<<maze[x][m];
        }
        cout<<endl;
    }
    cout<<"Score :"<<score;
}
int ghostDirection()
{
    srand(time(0));
    int result = 1 + (rand() % 4);
    return result;
}
void moveup()
{
    if (maze[X-1][Y] == '.')
    {
        score++;
        maze[X-1][Y] = ' ';
    }
    if (maze[X - 1][Y] != '#' && maze[X - 1][Y] != '%' && maze[X - 1][Y] != '|')
    {
        swap(maze[X][Y], maze[X - 1][Y]);
        X--;
    }
}
void movedown()
{
    if (maze[X+1][Y] == '.')
    {
        score++;
        maze[X+1][Y] = ' ';
    }
    if(maze[X+1][Y] != '#' && maze[X+1][Y] != '%' && maze[X+1][Y] != '|')
    {
        swap(maze[X][Y], maze[X + 1][Y]);
        X++;
    }
}
void moveright()
{
    if (maze[X][Y+1] == '.')
    {
        score++;
        maze[X][Y+1] = ' ';
    }
    if(maze[X][Y+1] != '#' && maze[X][Y+1] != '%' && maze[X][Y+1] != '|')
    {
        swap(maze[X][Y],maze[X][Y+1]);
        Y++;
    }
}
void moveleft()
{
    if (maze[X][Y - 1] == '.')
    {
        score++;
        maze[X][Y - 1] = ' ';
    }
    if (maze[X][Y - 1] != '#' && maze[X][Y - 1] != '%' && maze[X][Y - 1] != '|')
    {
        swap(maze[X][Y], maze[X][Y - 1]);
        Y--;
    }
}
bool ghost()
{
    int value = ghostDirection();
    if (value == 1)
    {
        if(maze[gx - 1][gy] == 'P')
        {return 1;}
        if (maze[gx - 1][gy] == ' ' || maze[gx - 1][gy] == '.')
        {
            swap(maze[gx][gy], maze[gx - 1][gy]);
            gx--;
        }
    }
    if (value == 2)
    {
        if( maze[gx + 1][gy] == 'P')
            {return 1;}
        if (maze[gx + 1][gy] == ' ' || maze[gx + 1][gy] == '.')
        {
            
            swap(maze[gx][gy], maze[gx + 1][gy]);
            gx++;
        }
    }
    if (value == 3)
    {
        if(maze[gx][gy + 1] == 'P')
        {return 1;}
        if (maze[gx][gy + 1] == ' ' || maze[gx][gy + 1] == '.')
        {
            
            swap(maze[gx][gy], maze[gx][gy + 1]);
            gy++;
        }
        
    }
    if (value == 4)
    {
        if(maze[gx - 1][gy] == 'P')
        {return 1;}
        if (maze[gx][gy - 1] == ' ' || maze[gx - 1][gy] == '.')
        {
            
            swap(maze[gx][gy], maze[gx][gy - 1]);
            gy--;
        }
    }
}
main()
{
    while(1)
    {
        // Sleep(100);
        system("cls");
        display();
        
        if(GetAsyncKeyState(VK_LEFT))
        {
            moveleft();
        }
        else if(GetAsyncKeyState(VK_RIGHT))
        {
            moveright();
        }
        else if(GetAsyncKeyState(VK_UP))
        {
            moveup();
        }
        else if(GetAsyncKeyState(VK_DOWN))
        {
            movedown();
        }
        else if(GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
        bool yt=0;
        yt = ghost();
        if(yt == 1) break;
    }
    cout<<"Game Over";
}