#include <iostream>
#include <conio.h>

#define clr system("cls")
#define inside(x,y) ((x>0)&&(y>0)&&(x<16)&&(y<16))

using namespace std;

int pan[16][16],nums[4],x,y,oldx,oldy;
bool isBlack;

void instruction(int i)
{
    if(i==1)
    {
        cout<<"------ Welcome to GoBang -------"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"¡¤ This program is PVP five-in-a-row game"<<endl;
        cout<<"¡¤ Enter 'S' to start the game"<<endl;
        cout<<"¡¤ If you need command to control the game, enter '?' look for help"<<endl;
    }
    if(i==2)
    {
        cout<<"---------------------------"<<endl;
        cout<<"Dev-C++ game - command"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Command List£º"<<endl;
        cout<<"¡¤N(blank)x(blank)y   £ºput chess at position(x,y)"<<endl;
        cout<<"Coordinates in board shown by hexadecimal, please enter decimal coordinates(A=10,F=15)"<<endl;
        cout<<"¡¤A(blank)command(blank)n£ºput your chess at distance n unit from current chess"<<endl;
        cout<<"Command: R-right  L-left  U-up  D-down"<<endl;
        cout<<"RD-low right  RU-upper right  LD-low left  LU-upper left"<<endl;
        cout<<"For example:A R 1£ºput your chess at 1 unit on the right of current chess"<<endl;
        cout<<" A LD 3: put your chess a 3 units on the low left of current chess"<<endl;
        cout<<"Tips: you can enter any command with n = 0 at the start of the game to put your chess at center of the chessboard"<<endl;
        cout<<"         For example: A L 0"<<endl;
    }
}

char makech(int n)
{
    if(n<10)
        return (char)n+48;
    return (char)n+55;
}

void print()
{
    cout<<"   ";
    for(int i=1;i<16;i++)
        cout<<makech(i)<<" ";
    cout<<endl<<"  ------------------------------"<<endl;
    for(int i=1;i<16;i++)
    {
        for(int j=1;j<16;j++)
        {
            if(j==1)
                cout<<makech(i)<<"| ";
            switch(pan[i][j])
            {
                case 9:
                    cout<<"- ";
                    break;
                case 0:
                    cout<<"0 ";
                    break;
                case 1:
                    cout<<"1 ";
                    break;
            }
        }
        cout<<endl;
    }
}

void dfs2(int x,int y,int fx)
{
    int trues=isBlack?1:0;
    if(pan[x][y]==trues)
    {nums[fx]++; }
    else
    {return;}
    switch(fx)
    {
        case 0:
            if(inside(x+1,y))
            {dfs2(x+1,y,0);}
            else
            {return;}
            break;
        case 1:
            if(inside(x,y+1))
            {dfs2(x,y+1,1);}
            else
            {return;}
            break;
        case 2:
            if(inside(x+1,y+1))
            {dfs2(x+1,y+1,2);}
            else
            {return;}
            break;
        case 3:
            if(inside(x+1,y-1))
            {dfs2(x+1,y-1,3);}
            else
            {return;}
            break;
    }
}

void dfs1(int x,int y,int fx)//0 up-down 1 left-right 2 £Ü  3£¯
{
    int trues=isBlack?1:0;
    switch(fx)
    {
        case 0:
            if((pan[x-1][y]==trues)&&inside(x-1,y))
            {
                dfs1(x-1,y,0);
                return;
            }else
            {
                dfs2(x,y,0);
            }
            break;
        case 1:
            if((pan[x][y-1]==trues)&&inside(x,y-1))
            {
                dfs1(x,y-1,1);
                return;
            }else
            {
                dfs2(x,y,1);
            }
            break;
        case 2:
            if((pan[x-1][y-1]==trues)&&inside(x-1,y-1))
            {
                dfs1(x-1,y-1,2);
                return;
            }else
            {
                dfs2(x,y,2);
            }
            break;
        case 3:
            if((pan[x-1][y+1]==trues)&&inside(x-1,y+1))
            {
                dfs1(x-1,y+1,3);
                return;
            }else
            {
                dfs2(x,y,3);
            }
            break;
    }
}

void resetAll()
{
    for(int i=1;i<16;i++)
        for(int j=1;j<16;j++)
            pan[i][j]=9;
    x=8;
    y=8;
    isBlack=true;
}

int main()
{
    instruction(1);
    resetAll();
    while(1)
    {
        char t;
        cin>>t;
        oldx=x;oldy=y;
        if(t=='N')
        {

            cin>>x>>y;
        }
        else if(t=='A')
        {
            string act;
            int num;
            cin>>act>>num;
            if(act=="R")
                y+=num;
            if(act=="L")
                y-=num;
            if(act=="U")
                x-=num;
            if(act=="D")
                x+=num;
            if(act=="RU")
                x-=num,y+=num;
            if(act=="RD")
                x+=num,y+=num;
            if(act=="LU")
                y-=num,x-=num;
            if(act=="LD")
                y-=num,x+=num;
        }
        else if(t=='S')
        {
            print();
            continue;
        }
        else if(t=='?')
        {
            instruction(2);
            continue;
        }
        else if(t=='i')
        {
            instruction(3);
            continue;
        }
        else
        {
            cout<<"Unknown command"<<endl;
            continue;
        }
        if((inside(x,y))&&(pan[x][y]==9) )
        {
            pan[x][y]=(isBlack)?1:0;
            clr;
            print();
            for(int i=0;i<4;i++)
            {
                nums[i]=0;
                dfs1(x,y,i);
                if(nums[i]>=5)
                {
                    string winner=!isBlack?"Player 0 ":"Player 1 ";
                    cout<<winner<<"Win£¡"<<endl<<"Restart?(enter Y/N)";
                    string temp;cin>>temp;
                    if(temp=="Y")
                    {
                        resetAll();
                        continue;
                    }else{break;}
                }
            }
            isBlack=!isBlack;
            continue;
        }else
        {
            cout<<"Illegal coordinate or there is already a piece"<<endl;
            x=oldx;y=oldy;
            continue;
        }
    }
    return 0;
}
