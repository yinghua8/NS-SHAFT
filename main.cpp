#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
int x=10,y=90;
int X=1, Y=80;
const int len=45,wid=155;//邊界為35 154
const int LEN = 10, WID = 155;
int sx1=rand()%90+50,sy1=45;
int sx2=rand()%90+50,sy2=39;
int sx3=rand()%90+50,sy3=32;
int sx4=rand()%90+50,sy4=26;
int sx5=rand()%90+50,sy5=19;
int sx6=rand()%90+50,sy6=13;
int sx7=rand()%90+50,sy7=6;
int RL1=0;
int RL2=0;
int RL3=0;
int RL4=0;
int RL5=0;
int RL6=0;
int RL7=0;
int down=1;
int ral=1;
int dc=-1;
int dr=-1;
int c=0;
int MOVE = 1;
int s/*123*/;
int m_flag=0;
int speed;
int blood = 10;
int k=0;
int score=0;
int interval=50;
int level=1;
int cx1=rand()%90+50,cy1=rand()%30+7;
int cx2=rand()%90+50,cy2=rand()%30+7;
int cx3=rand()%90+50,cy3=rand()%30+7;
int cx4=rand()%90+50,cy4=rand()%30+7;
int cx5=rand()%90+50,cy5=rand()%30+7;
int cx6=rand()%90+50,cy6=rand()%30+7;
int cx7=rand()%90+50,cy7=rand()%30+7;
int cx8=rand()%90+50,cy8=rand()%30+7;
int person=0;
int record=0;
int rint[10][2];
char rchar[10][5];
char T;//A B C D E
char A='#',B='=',C='=',D='"',E='#',F='"',G='#';
char b[LEN][WID];
char a[len][wid];
char p[15][155];
char again;
char start='z';
string name;
void data();
void personA(char a[len][wid]);
void personB(char a[len][wid]);
void personC(char a[len][wid]);
void personD(char a[len][wid]);
void person2(char b[len][wid]);
void ster(char a[len][wid]);
void begin_move();
void direction();
void RL();
void wall(char a[len][wid]);
void print(char a[len][wid]);
void step1(char a[len][wid]);
void swit(int s,char a[len][wid]);
void step2(char a[len][wid]);
void step3(char a[len][wid]);
void step4(char a[len][wid]);
void step5(char a[len][wid]);
void step6(char a[len][wid]);
void step7(char a[len][wid]);
void touch(char a[len][wid]);
void start_game();
void blood_add();
void candy(char s[len][wid]);
void SetColor(int color = 7);
void colorchange(int i,int j,char a[len][wid]);
void chooseperson();
void temp();
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void SetColor(int color )
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}
void data()
{
    x=10;y=90;
    X=1;Y=80;
    sx1=rand()%90+50;sy1=45;
    sx2=rand()%90+50;sy2=39;
    sx3=rand()%90+50;sy3=32;
    sx4=rand()%90+50;sy4=26;
    sx5=rand()%90+50;sy5=19;
    sx6=rand()%90+50;sy6=13;
    sx7=rand()%90+50;sy7=6;
    RL1=0;
    RL2=0;
    RL3=0;
    RL4=0;
    RL5=0;
    RL6=0;
    RL7=0;
    down=1;
    ral=1;
    dc=-1;
    dr=-1;
    c=0;
    MOVE = 1;
    m_flag=0;
    blood = 10;
    k=0;
    score=0;
    cx1=rand()%90+50;cy1=rand()%30+7;
    cx2=rand()%90+50;cy2=rand()%30+7;
    cx3=rand()%90+50;cy3=rand()%30+7;
    cx4=rand()%90+50;cy4=rand()%30+7;
    cx5=rand()%90+50;cy5=rand()%30+7;
    cx6=rand()%90+50;cy6=rand()%30+7;
    cx7=rand()%90+50,cy7=rand()%30+7;
    cx8=rand()%90+50,cy8=rand()%30+7;
    person=0;
    A='#';B='=';C='=';D='"';E='=';F='"';G='#';
    start='z';
    return;
}
void begin_move()
{
    if(Y == 150)
    {
        MOVE = MOVE * (-1);
    }
    if(Y == 36)
    {
        MOVE = MOVE * (-1);
    }
    Y = Y + MOVE;

    return;
}
void person2(char b[LEN][WID])
{

    b[X][Y] = '_';
    b[X][Y - 1] = '_';
    b[X][Y + 1] = '_';
    b[X][Y + 3] = '_';
    b[X][Y + 2] = '_';  //top of the head
    b[X + 1][Y] = '#';
    b[X + 1][Y + 1] = '#'; //eyes
    b[X + 1][Y - 1] = '|';
    b[X + 2][Y - 1] = '|';//left side head
    b[X + 2][Y] = '-';
    b[X + 2][Y + 1] = '-';
    b[X + 2][Y + 2] = '-'; //chin
    b[X + 1][Y + 3] = '|';
    b[X + 2][Y + 3] = '|';// right side head
    b[X + 3][Y] = 'N';
    b[X + 3][Y + 1] = 'N';//clothes
    b[X + 3][Y - 1] = '-';
    b[X + 3][Y + 2] = '-'; // hands
    b[X + 4][Y] = '|';
    b[X + 4][Y + 1] = '|'; // legs
    return;
}
void chooseperson()
{
    int xa=5,ya=60;
    int xb=5,yb=85;
    int xc=5,yc=110;
    int xd=5,yd=135;
    for(int pi=0;pi<15;pi++)
    {
        for(int pj=0;pj<155;pj++)
            p[pi][pj]=' ';
    }
    p[xa][ya] = '_';
    p[xa][ya - 1] = '_';
    p[xa][ya + 1] = '_';
    p[xa][ya + 3] = '_';
    p[xa][ya + 2] = '_';  //top of the head
    p[xa + 1][ya] = 'O';
    p[xa + 1][ya + 2] = 'O';
    p[xa + 1][ya - 1] = '|';
    p[xa + 2][ya - 1] = '|';
    p[xa + 2][ya] = '-';
    p[xa + 2][ya + 1] = '-';
    p[xa + 2][ya + 2] = '-'; //chin
    p[xa + 1][ya + 3] = '|';
    p[xa + 2][ya + 3] = '|';
    p[xa + 3][ya] = 'N';
    p[xa + 3][ya + 1] = 'N';
    p[xa + 3][ya - 1] = '~';
    p[xa + 3][ya + 2] = '~'; // hands
    p[xa + 4][ya] = '|';
    p[xa + 4][ya + 1] = '|'; // legs
    p[xa + 6][ya] = '1';

    p[xb][yb] = '_';
    p[xb][yb + 1] = '_';
    p[xb][yb + 2] = '_';
    p[xb + 1][yb - 1] = '/';
    p[xb + 1][yb + 3] = '\\'; //head(double slash in order to output the backslash)
    p[xb + 1][yb] = '$';
    p[xb + 1][yb + 1] = '$'; //eyes
    p[xb + 2][yb - 1] = '|';//left side head
    p[xb + 2][yb] = '-';
    p[xb + 2][yb + 1] = '-';
    p[xb + 2][yb + 2] = '-'; //chin
    p[xb + 2][yb + 3] = '|';// right side head
    p[xb + 3][yb] = 'U';
    p[xb + 3][yb + 1] = 'U';
    p[xb + 3][yb - 1] = '-';
    p[xb + 3][yb + 2] = '-';
    p[xb + 4][yb] = '|';
    p[xb + 4][yb + 1] = '|'; // legs
    p[xb + 6][yb+1] = '2';

    p[xc][yc] = '_';
    p[xc][yc + 1] = '_';
    p[xc][yc + 2] = '_';
    p[xc][yc - 1] = '_';
    p[xc][yc + 3] = '_';
    p[xc + 1][yc - 1] = '\\'; //head(double slash in order to output the backslash)
    p[xc + 1][yc + 3] = '/';
    p[xc + 2][yc] = '\\';
    p[xc + 2][yc + 2] = '/';//left side head
    p[xc + 2][yc + 1] = '-';//chin
    p[xc + 3][yc + 1] = 'M';// right side head
    p[xc + 3][yc] = '-';
    p[xc + 3][yc + 2] = '-';
    p[xc + 4][yc + 1] = '^';
    p[xc + 1][yc] = '>';
    p[xc + 1][yc + 2] = '<'; // eyes
    p[xc + 6][yc + 1] = '3';

    p[xd][yd] = '_';
    p[xd][yd + 1] = '_';
    p[xd][yd + 2] = '_';
    p[xd][yd - 1] = '_';
    p[xd + 1][yd - 1] = '\\'; //head(double slash in order to output the backslash)
    p[xd + 1][yd + 2] = '/';
    p[xd + 2][yd + 2] = '\\';
    p[xd + 2][yd - 1] = '/';//left side head
    p[xd + 3][yd - 1] = '-';
    p[xd + 2][yd] = '-';// right side head
    p[xd + 2][yd + 1] = '-';
    p[xd + 3][yd + 2] = '-';
    p[xd + 3][yd + 1] = 'W';
    p[xd + 4][yd + 1] = '|';
    p[xd + 4][yd] = '|'; // legs
    p[xd + 3][yd] = 'W';
    p[xd + 1][yd] = '*';
    p[xd + 1][yd + 1] = '*'; // eyes
    p[xd + 6][yd] = '4';
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    for(int pi=0;pi<15;pi++)
    {
        for(int pj=0;pj<155;pj++)
            cout<<p[pi][pj];
        cout<<endl;
    }
    cout<<"                                                   請選擇角色:";
    cin>>person;
    if(person!=1&&person!=2&&person!=3&&person!=4)
    {
        cout<<endl<<"錯誤!"<<endl;
        cout<<"請選擇角色(1/2/3/4)";
        cin>>person;
    }
    return;
}
void start_game()
{
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                                                                                       遊戲說明" << endl << endl;
    cout << "                                                               小建和小男從小就是非常要好的玩伴。有一次他們相約一起" << endl;
    cout << "                                                               到美國滑雪，然而在滑雪的過程中，小男突然消失了 ! 當小" << endl;
    cout << "                                                               建著急的坐上纜車尋找小男的身影時，他赫然發現 : 小男竟" << endl;
    cout << "                                                               然在地面上一動也不動，生死未卜 ! 但小建此時已經到達山" << endl;
    cout << "                                                               的頂端，要下去只能走下一階又一階危險的樓梯，究竟小建" << endl;
    cout << "                                                               和小男能不能再度重逢呢 ?" << endl << endl;
    cout << "                                                               遊戲操作規則說明 :" << endl;
    cout << "                                                               1.按下 A 開始遊戲" << endl;
    cout << "                                                               2.按下 B 結束遊戲" << endl;
    cout << "                                                               3.用 Z , X 操作小建左右移動" << endl;
    cout << "                                                               4.踩到帶刺的階梯會使小建血量減少，當小建血量為零時，任" << endl;
    cout << "                                                                 務即失敗，遊戲結束" << endl;
    cout << "                                                               5.碰到上方的刺即失敗，遊戲結束" << endl;
    cout << "                                                               6. ====== 為一般階梯" << endl;
    cout << "                                                                  ------ 為只能踩一次的階梯" << endl;
    cout << "                                                                  ###### 為有刺的階梯，會使小建血量減少" << endl;
    cout << "                                                               7.掉下台階到地面即贏得遊戲、找到小男!" << endl;
    cout << endl << "                                                                    請盡你的全力幫助小建找到小男 ! ! !" << endl;
    for(int I = 0; I < LEN; I++)
    {
        for(int J = 0; J < WID; J++)
        {
            b[I][J]=' ';
        }

    }
    person2(b);
    SetColor(11);
    for(int I = 0; I < LEN; I++)
    {
        for(int J = 0; J < WID; J++)
        {
            cout << b[I][J];
        }
        cout<<endl;
    }
    SetColor();
    begin_move();

    return;
}
int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
    srand(time(NULL));
    start_game();

    do
    {
        data();
        gotoxy(0,0);
        while(true)
        {
            gotoxy(0,0);
            start_game();
            if(kbhit())
            {
                start = getch();
                if(start == 'a' || start == 'A')
                {
                    break;
                }

            }

        }
        PlaySound(TEXT("music.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        cout<<"                                                               請輸入玩家名稱:";
        cin>>name;
        system("cls");
        chooseperson();
        system("cls");
        blood=10;
             while(blood>0&&x+4<44&&x>=2)
            {
                wall(a);//圍牆
                ster(a);
                touch(a);
                if(person==1)
                    personA(a);
                else if(person==2)
                    personB(a);
                else if(person==3)
                    personC(a);
                else if(person==4)
                    personD(a);
                candy(a);
                print(a);
                direction();
                blood_add();
                RL();
                Sleep(interval);
                gotoxy(0,0);
                if(kbhit())
                {
                    start=getch();
                    if(start == 'b' || start == 'B')
                    {
                        gotoxy(0,0);

                        break;
                    }
                }
            }
            PlaySound(NULL, NULL, SND_FILENAME);
             if(start == 'b' || start == 'B')
            {
                cout<<"end the game"<<endl;
                break;
            }

            else
            {
                cout<<"Game over"<<"  c="<<c<<endl;
                cout<<"分數 : "<<score+c<<endl;
                cout<<"Do you want to try again ?(y/n)"<<endl;
                cin>>again;
            }

            rint[record][0]=record+1;

            for(int k=0;k<name.length();k++)
            {
                rchar[record][k]=name[k];
            }
            rint[record][1]=score+c;

            record++;
            system("cls");
    }
    while(again=='y'||again=='Y');
    temp();
    cout<<"名次      玩家名稱      分數"<<endl<<endl;
    for(int k=0;k<record;k++)
    {
        cout<<"  "<<rint[k][0]<<"         ";

        for(int w=0;w<5;w++)
            cout<<rchar[k][w];

        cout<<"        "<<rint[k][1]<<endl<<endl;
    }
    return 0;
}
void temp()
{
    for(int e=0;e<=record;e++)
        {
            for(int k=0;k<=record;k++)
                {

                    if(rint[k][1]<rint[k+1][1])
                    {
                        int tempint=rint[k][1];
                        rint[k][1]=rint[k+1][1];
                        rint[k+1][1]=tempint;
                        char tempchar[5];
                        for(int w=0;w<5;w++)
                        {
                            tempchar[w]=rchar[k][w];
                            rchar[k][w]=rchar[k+1][w];
                            rchar[k+1][w]=tempchar[w];
                        }

                    }
                }
        }

    return;
}
void colorchange(int i,int j,char a[len][wid])
{
    if(a[i][j]=='W'||a[i][j]=='>'||a[i][j]=='<'||a[i][j]=='^'||a[i][j]=='M'||a[i][j]=='U'||a[i][j]=='$'||a[i][j]=='\\'||a[i][j]=='/'||a[i][j]=='-'||a[i][j]=='O'||a[i][j]=='|'||a[i][j]=='_'||a[i][j]=='N'||a[i][j]=='~')
    {
        SetColor(11);
    }
    else if((i==x+1)&&(j==y||j==y+1))
    {
        SetColor(11);
    }
    else if(a[i][j]=='#'||a[i][j]=='T')
    {
        SetColor(12);
    }
    else if(a[i][j]=='"')
    {
        SetColor(6);
    }
    else if(a[i][j]=='=')
    {
        SetColor(9);
    }
    else if(a[i][j]=='B'||a[i][j]=='@'||a[i][j]=='!'||a[i][j]=='+')
    {
        SetColor();
    }
    else
        SetColor();
    return;
}
void RL()
{
    c++;
    if(c==60)//60回合後左右移動
    {
        RL1=1;
        RL2=1;
        RL3=-1;
        RL4=-1;
        RL5=1;
        RL6=-1;
        RL7=-1;
    }
    dc--;
    if(dc==0)
        down=1;
    dr--;
    if(dr==0)
        ral=1;
    if(c==70)
    {
        interval=45;
        level=2;
    }


    if(c==140)
    {
        interval=40;
        level=3;
    }

    if(c==210)
    {
        interval=35;
        level=4;
    }


    if(c==280)
    {
        interval=30;
        level=5;
    }


    if(c==350)
    {
        interval=40;
        level=6;
    }


    return;
}
void candy(char a[len][wid])//1 2 3 分數 //4血量恢復
{

    if(a[cy1][cx1]=='W'||a[cy1][cx1]=='>'||a[cy1][cx1]=='<'||a[cy1][cx1]=='^'||a[cy1][cx1]=='M'||a[cy1][cx1]=='U'||a[cy1][cx1]=='$'||a[cy1][cx1]=='\\'||a[cy1][cx1]=='/'||a[cy1][cx1]=='-'||a[cy1][cx1]=='O'||a[cy1][cx1]=='|'||a[cy1][cx1]=='_'||a[cy1][cx1]=='N'||a[cy1][cx1]=='~')
    {
        score+=10;
        cx1=rand()%90+50;
        cy1=rand()%30+7;
    }
    else if((cy1==x+1)&&(cx1==y||cx1==y+1))
    {
        score+=10;
        cx1=rand()%90+50;
        cy1=rand()%30+7;
    }
    a[cy1][cx1]='+';

    if(a[cy2][cx2]=='W'||a[cy2][cx2]=='>'||a[cy2][cx2]=='<'||a[cy2][cx2]=='^'||a[cy2][cx2]=='M'||a[cy2][cx2]=='U'||a[cy2][cx2]=='$'||a[cy2][cx2]=='\\'||a[cy2][cx2]=='/'||a[cy2][cx2]=='-'||a[cy2][cx2]=='O'||a[cy2][cx2]=='|'||a[cy2][cx2]=='_'||a[cy2][cx2]=='N'||a[cy2][cx2]=='~')
    {
        score+=10;
        cx2=rand()%90+50;
        cy2=rand()%30+7;
    }
    else if((cy2==x+1)&&(cx2==y||cx2==y+1))
    {
        score+=10;
        cx2=rand()%90+50;
        cy2=rand()%30+7;
    }
    a[cy2][cx2]='+';

    if(a[cy3][cx3]=='W'||a[cy3][cx3]=='>'||a[cy3][cx3]=='<'||a[cy3][cx3]=='^'||a[cy3][cx3]=='M'||a[cy3][cx3]=='U'||a[cy3][cx3]=='$'||a[cy3][cx3]=='\\'||a[cy3][cx3]=='/'||a[cy3][cx3]=='-'||a[cy3][cx3]=='O'||a[cy3][cx3]=='|'||a[cy3][cx3]=='_'||a[cy3][cx3]=='N'||a[cy3][cx3]=='~')
    {
        score+=10;
        cx3=rand()%90+50;
        cy3=rand()%40+3;
    }
    else if((cy3==x+1)&&(cx3==y||cx3==y+1))
    {
        score+=10;
        cx3=rand()%90+50;
        cy3=rand()%30+7;
    }
    a[cy3][cx3]='+';

    if(a[cy4][cx4]=='W'||a[cy4][cx4]=='>'||a[cy4][cx4]=='<'||a[cy4][cx4]=='^'||a[cy4][cx4]=='M'||a[cy4][cx4]=='U'||a[cy4][cx4]=='$'||a[cy4][cx4]=='\\'||a[cy4][cx4]=='/'||a[cy4][cx4]=='-'||a[cy4][cx4]=='O'||a[cy4][cx4]=='|'||a[cy4][cx4]=='_'||a[cy4][cx4]=='N'||a[cy4][cx4]=='~')
    {
        blood+=2;
        if(blood>10)
            blood=10;
        cx4=rand()%90+50;
        cy4=rand()%30+7;
    }
    else if((cy4==x+1)&&(cx4==y||cx4==y+1))
    {
        blood+=2;
        cx4=rand()%90+50;
        cy4=rand()%30+7;
    }
    a[cy4][cx4]='B';

    if(a[cy5][cx5]=='W'||a[cy5][cx5]=='>'||a[cy5][cx5]=='<'||a[cy5][cx5]=='^'||a[cy5][cx5]=='M'||a[cy5][cx5]=='U'||a[cy5][cx5]=='$'||a[cy5][cx5]=='\\'||a[cy5][cx5]=='/'||a[cy5][cx5]=='-'||a[cy5][cx5]=='O'||a[cy5][cx5]=='|'||a[cy5][cx5]=='_'||a[cy5][cx5]=='N'||a[cy5][cx5]=='~')
    {
        down=2;
        dc=5;
        cx5=rand()%90+50;
        cy5=rand()%30+7;
    }
    else if((cy5==x+1)&&(cx5==y||cx5==y+1))
    {
        down=2;
        dc=5;
        cx5=rand()%90+50;
        cy5=rand()%30+7;

    }
    a[cy5][cx5]='!';

    if(a[cy6][cx6]=='W'||a[cy6][cx6]=='>'||a[cy6][cx6]=='<'||a[cy6][cx6]=='^'||a[cy6][cx6]=='M'||a[cy6][cx6]=='U'||a[cy6][cx6]=='$'||a[cy6][cx6]=='\\'||a[cy6][cx6]=='/'||a[cy6][cx6]=='-'||a[cy6][cx6]=='O'||a[cy6][cx6]=='|'||a[cy6][cx6]=='_'||a[cy6][cx6]=='N'||a[cy6][cx6]=='~')
    {
        y=cx7;
        x=cy7;
        cx7=rand()%90+50;
        cy7=rand()%40+3;
        cx6=rand()%90+50;
        cy6=rand()%30+7;
    }
    else if((cy6==x+1)&&(cx6==y||cx6==y+1))
    {
        y=cx7;
        x=cy7;
        cx7=rand()%90+50;
        cy7=rand()%40+3;
        cx6=rand()%90+50;
        cy6=rand()%30+7;

    }
    a[cy6][cx6]='@';

    if(a[cy7][cx7]=='W'||a[cy7][cx7]=='>'||a[cy7][cx7]=='<'||a[cy7][cx7]=='^'||a[cy7][cx7]=='M'||a[cy7][cx7]=='U'||a[cy7][cx7]=='$'||a[cy7][cx7]=='\\'||a[cy7][cx7]=='/'||a[cy7][cx7]=='-'||a[cy7][cx7]=='O'||a[cy7][cx7]=='|'||a[cy7][cx7]=='_'||a[cy7][cx7]=='N'||a[cy7][cx7]=='~')
    {
        y=cx6;
        x=cy6;
        cx7=rand()%90+50;
        cy7=rand()%40+3;
        cx6=rand()%90+50;
        cy6=rand()%30+7;
    }
    else if((cy7==x+1)&&(cx7==y||cx7==y+1))
    {
        y=cx6;
        x=cy6;
        cx7=rand()%90+50;
        cy7=rand()%40+3;
        cx6=rand()%90+50;
        cy6=rand()%30+7;

    }
    a[cy7][cx7]='@';

    if(a[cy8][cx8]=='W'||a[cy8][cx8]=='>'||a[cy8][cx8]=='<'||a[cy8][cx8]=='^'||a[cy8][cx8]=='M'||a[cy8][cx8]=='U'||a[cy8][cx8]=='$'||a[cy8][cx8]=='\\'||a[cy8][cx8]=='/'||a[cy8][cx8]=='-'||a[cy8][cx8]=='O'||a[cy8][cx8]=='|'||a[cy8][cx8]=='_'||a[cy8][cx8]=='N'||a[cy8][cx8]=='~')
    {
        ral=2;
        dr=5;
        cx8=rand()%90+50;
        cy8=rand()%30+7;
    }
    else if((cy8==x+1)&&(cx8==y||cx8==y+1))
    {
        ral=2;
        dr=5;
        cx8=rand()%90+50;
        cy8=rand()%30+7;

    }
    a[cy8][cx8]='X';
    return;
}
void ster(char a[len][wid])
{
        if(sy1==2)
        {
            sy1=45;
            sx1=rand()%90+50;
            s=rand()%3+1;
            A=T;
        }

        if(sx1-12==36||sx1+12==153)
        RL1=(-1)*RL1;
        sx1+=RL1;
        sy1--;
        swit(s,a);//隨機產生一種樓梯
        step1(a);

        if(sy2==2)
        {
            sy2=45;
            sx2=rand()%90+50;
            s=rand()%3+1;
            B=T;
        }
        if(sx2-12==36||sx2+12==153)
        RL2=(-1)*RL2;
        sx2+=RL2;
        sy2--;
        swit(s,a);
        step2(a);

        if(sy3==2)
        {
            sy3=45;
            sx3=rand()%90+50;
            s=rand()%3+1;
            C=T;
        }
        if(sx3-12==36||sx3+12==153)
        RL3=(-1)*RL3;
        sx3+=RL3;
        sy3--;
        swit(s,a);
        step3(a);

        if(sy4==2)
        {
            sy4=45;
            sx4=rand()%90+50;
            s=rand()%3+1;
            D=T;
        }
        if(sx4-12==36||sx4+12==153)
        RL4=(-1)*RL4;
        sx4+=RL4;
        sy4--;
        swit(s,a);
        step4(a);

        if(sy5==2)
        {
            sy5=45;
            sx5=rand()%90+50;
            s=rand()%3+1;
            E=T;
        }
        if(sx5-12==36||sx5+12==153)
        RL5=(-1)*RL5;
        sx5+=RL5;
        sy5--;
        swit(s,a);
        step5(a);

        if(sy6==2)
        {
            sy6=45;
            sx6=rand()%90+50;
            s=rand()%3+1;
            F=T;
        }
        if(sx6-12==36||sx6+12==153)
        RL6=(-1)*RL6;
        sx6+=RL6;
        sy6--;
        swit(s,a);
        step6(a);

        if(sy7==2)
        {
            sy7=45;
            sx7=rand()%90+50;
            s=rand()%3+1;
            G=T;
        }
        if(sx7-12==36||sx7+12==153)
        RL7=(-1)*RL7;
        sx7+=RL7;
        sy7--;
        swit(s,a);
        step7(a);

    return;
}
void touch(char a[len][wid])
{

    if(a[x + 4][y] == '#' || a[x + 4][y + 1] == '#')
    {
        blood--;
         x = x -2;
    }
    else if(a[x + 4][y] == '=' || a[x + 4][y + 1] == '=')
    {
        x = x - 1;
    }

    else if(a[x + 4][y] == '"' || a[x + 4][y + 1] == '"')
    {
        k++;
        if(k%2!=0)
            x = x - 1;
    }
    else
    {
        m_flag++;
        //if(m_flag % 2 == 0)
        x+=down;
        if(a[x + 4][y-1] == '#' || a[x + 4][y + 2] == '#')
        {
            blood--;
            x = x -1;
        }
        else if(a[x + 4][y-1] == '=' || a[x + 4][y + 2] == '=')
        {
            x = x - 1;

        }

        else if(a[x + 4][y-1] == '"' || a[x + 4][y + 2] == '"')
        {
            x = x - 1;
        }
    }
    return;
}
void blood_add()
{
    if((blood > 0)&&(blood < 10))
    {
        m_flag++;
        if(m_flag % 5 == 0)
            {
                blood++;
            }
    }
    return;
}
void direction()
{
    if((y-1)>36&&(y+3)<153)
    {
        while(kbhit())
        {
            char g;
            g = getch();
            switch(g)
            {
                case 'z':
                case 'Z':
                    y-=ral;
                    break;

                case 'x':
                case 'X':
                    y+=ral;
                    break;
            }
        }
    }
    if((y-1)==36)
    {
        char g;
        g = getch();
        if(g=='x')
            y++;
    }
    if((y+3)==153)
    {
        char g;
        g = getch();
        if(g=='z')
            y--;
    }

    return;
}
void personA(char a[len][wid])
{
    a[x][y] = '_';
    a[x][y - 1] = '_';
    a[x][y + 1] = '_';
    a[x][y + 3] = '_';
    a[x][y + 2] = '_';  //top of the head
    a[x + 1][y] = 'O';
    a[x + 1][y + 2] = 'O'; //eyes

    a[x + 1][y - 1] = '|';
    a[x + 2][y - 1] = '|';//left side head
    //a[x + 3][y - 1] = '|';
    a[x + 2][y] = '-';
    a[x + 2][y + 1] = '-';
    a[x + 2][y + 2] = '-'; //chin
    a[x + 1][y + 3] = '|';
    a[x + 2][y + 3] = '|';// right side head
    //a[x + 3][y + 3] = '|';
    a[x + 3][y] = 'N';
    a[x + 3][y + 1] = 'N';
    //a[x + 4][y] = 'N';
    //a[x + 4][y + 1] = 'N'; //clothes
    a[x + 3][y - 1] = '~';
    a[x + 3][y + 2] = '~'; // hands
    //a[x + 5][y] = '|';
    //a[x + 5][y + 1] = '|'; // legs
    a[x + 4][y] = '|';
    a[x + 4][y + 1] = '|'; // legs
    return;
}
void personB(char a[len][wid])
{
    a[x][y] = '_';
    a[x][y + 1] = '_';
    a[x][y + 2] = '_';
    a[x + 1][y - 1] = '/';
    a[x + 1][y + 3] = '\\'; //head(double slash in order to output the backslash)
    a[x + 1][y] = '$';
    a[x + 1][y + 1] = '$'; //eyes
    a[x + 2][y - 1] = '|';//left side head
    a[x + 2][y] = '-';
    a[x + 2][y + 1] = '-';
    a[x + 2][y + 2] = '-'; //chin
    a[x + 2][y + 3] = '|';// right side head
    a[x + 3][y] = 'U';
    a[x + 3][y + 1] = 'U';
    //a[x + 4][y] = 'N';
    //a[x + 4][y + 1] = 'N'; //clothes
    a[x + 3][y - 1] = '-';
    a[x + 3][y + 2] = '-'; // hands
    //a[x + 5][y] = '|';
    //a[x + 5][y + 1] = '|'; // legs
    a[x + 4][y] = '|';
    a[x + 4][y + 1] = '|'; // legs
    return;
}
void personC(char a[len][wid])
{
    a[x][y] = '_';
    a[x][y + 1] = '_';
    a[x][y + 2] = '_';
    a[x][y - 1] = '_';
    a[x][y + 3] = '_';
    a[x + 1][y - 1] = '\\'; //head(double slash in order to output the backslash)
    a[x + 1][y + 3] = '/';
    a[x + 2][y] = '\\';
    a[x + 2][y + 2] = '/';//left side head
    a[x + 2][y + 1] = '-';//chin
    a[x + 3][y + 1] = 'M';// right side head
    a[x + 3][y] = '-';
    a[x + 3][y + 2] = '-';
    a[x + 4][y + 1] = '^';
    //a[x + 4][y + 2] = '|'; // legs
    a[x + 1][y] = '>';
    a[x + 1][y + 2] = '<'; // eyes
    return;
}
void personD(char a[len][wid])
{
    a[x][y] = '_';
    a[x][y + 1] = '_';
    a[x][y + 2] = '_';
    a[x][y - 1] = '_';
    a[x + 1][y - 1] = '\\'; //head(double slash in order to output the backslash)
    a[x + 1][y + 2] = '/';
    a[x + 2][y + 2] = '\\';
    a[x + 2][y - 1] = '/';//left side head
    a[x + 3][y - 1] = '-';
    a[x + 2][y] = '-';// right side head
    a[x + 2][y + 1] = '-';
    a[x + 3][y + 2] = '-';
    a[x + 3][y + 1] = 'W';
    a[x + 4][y + 1] = '|';
    a[x + 4][y] = '|'; // legs
    a[x + 3][y] = 'W';
    a[x + 1][y] = '*';
    a[x + 1][y + 1] = '*'; // eyes
    return;
}
void swit(int s,char a[len][wid])
{
    switch(s)
    {
    case 1:
        {
            T='=';
            break;
        }
    case 2:
        {
            T='"';
            break;
        }
    case 3:
        {
            T='#';
            break;
        }

    }

    return;
}
void wall(char a[len][wid])
{
    int i,j;
    for (i=0;i<len;i++)
    {
        for(j=0;j<wid;j++)
        {

            if(i==0)
                a[i][j]='*';
            else if((j==35)||(j==154))
                a[i][j]='*';
            else
                a[i][j]=' ';
            if(j<35)
                a[i][j]=' ';
            if((i==1)&&(35<j)&&(j<154))
                a[i][j]='T';
        }
    }
    return;
}
void print(char a[len][wid])
{
    int I=blood;
    {
        cout<<"\n                                   玩家名稱 : "<<name
        <<"                                                                                   level="<<level
        <<"       分數 : "<<score+c+1<<endl<<endl
        <<"                                   Blood: ";

    }
   for(I;I>0;I--)
   {
       cout<<"* ";
   }
   cout<<"                            ";
    cout<< endl;

    int i=0,j;
    //cout<<endl<<endl;
    for (i;i<len;i++)
    {
        for(j=0;j<wid;j++)
        {
            colorchange(i,j,a);
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return;
}
void step1(char a[len][wid])//一般型,以sx1,sy1為中心點
{
    a[sy1][sx1-12]=A;
    a[sy1][sx1-11]=A;
    a[sy1][sx1-10]=A;
    a[sy1][sx1-9]=A;
    a[sy1][sx1-8]=A;
    a[sy1][sx1-7]=A;
    a[sy1][sx1-6]=A;
    a[sy1][sx1-5]=A;
    a[sy1][sx1-4]=A;
    a[sy1][sx1-3]=A;
    a[sy1][sx1-2]=A;
    a[sy1][sx1-1]=A;
    a[sy1][sx1]=A;
    a[sy1][sx1+1]=A;
    a[sy1][sx1+2]=A;
    a[sy1][sx1+3]=A;
    a[sy1][sx1+4]=A;
    a[sy1][sx1+5]=A;
    a[sy1][sx1+6]=A;
    a[sy1][sx1+7]=A;
    a[sy1][sx1+8]=A;
    a[sy1][sx1+9]=A;
    a[sy1][sx1+10]=A;
    a[sy1][sx1+11]=A;
    a[sy1][sx1+12]=A;

    return;
}
void step2(char a[len][wid])//一般型,以sx2,sy2為中心點
{
    a[sy2][sx2-12]=B;
    a[sy2][sx2-11]=B;
    a[sy2][sx2-10]=B;
    a[sy2][sx2-9]=B;
    a[sy2][sx2-8]=B;
    a[sy2][sx2-7]=B;
    a[sy2][sx2-6]=B;
    a[sy2][sx2-5]=B;
    a[sy2][sx2-4]=B;
    a[sy2][sx2-3]=B;
    a[sy2][sx2-2]=B;
    a[sy2][sx2-1]=B;
    a[sy2][sx2]=B;
    a[sy2][sx2+1]=B;
    a[sy2][sx2+2]=B;
    a[sy2][sx2+3]=B;
    a[sy2][sx2+4]=B;
    a[sy2][sx2+5]=B;
    a[sy2][sx2+6]=B;
    a[sy2][sx2+7]=B;
    a[sy2][sx2+8]=B;
    a[sy2][sx2+9]=B;
    a[sy2][sx2+10]=B;
    a[sy2][sx2+11]=B;
    a[sy2][sx2+12]=B;

    return;
}
void step3(char a[len][wid])//一般型,以sx3,sy3為中心點
{
    a[sy3][sx3-12]=C;
    a[sy3][sx3-11]=C;
    a[sy3][sx3-10]=C;
    a[sy3][sx3-9]=C;
    a[sy3][sx3-8]=C;
    a[sy3][sx3-7]=C;
    a[sy3][sx3-6]=C;
    a[sy3][sx3-5]=C;
    a[sy3][sx3-4]=C;
    a[sy3][sx3-3]=C;
    a[sy3][sx3-2]=C;
    a[sy3][sx3-1]=C;
    a[sy3][sx3]=C;
    a[sy3][sx3+1]=C;
    a[sy3][sx3+2]=C;
    a[sy3][sx3+3]=C;
    a[sy3][sx3+4]=C;
    a[sy3][sx3+5]=C;
    a[sy3][sx3+6]=C;
    a[sy3][sx3+7]=C;
    a[sy3][sx3+8]=C;
    a[sy3][sx3+9]=C;
    a[sy3][sx3+10]=C;
    a[sy3][sx3+11]=C;
    a[sy3][sx3+12]=C;

    return;
}
void step4(char a[len][wid])//一般型,以sx4,sy4為中心點
{
    a[sy4][sx4-12]=D;
    a[sy4][sx4-11]=D;
    a[sy4][sx4-10]=D;
    a[sy4][sx4-9]=D;
    a[sy4][sx4-8]=D;
    a[sy4][sx4-7]=D;
    a[sy4][sx4-6]=D;
    a[sy4][sx4-5]=D;
    a[sy4][sx4-4]=D;
    a[sy4][sx4-3]=D;
    a[sy4][sx4-2]=D;
    a[sy4][sx4-1]=D;
    a[sy4][sx4]=D;
    a[sy4][sx4+1]=D;
    a[sy4][sx4+2]=D;
    a[sy4][sx4+3]=D;
    a[sy4][sx4+4]=D;
    a[sy4][sx4+5]=D;
    a[sy4][sx4+6]=D;
    a[sy4][sx4+7]=D;
    a[sy4][sx4+8]=D;
    a[sy4][sx4+9]=D;
    a[sy4][sx4+10]=D;
    a[sy4][sx4+11]=D;
    a[sy4][sx4+12]=D;

    return;
}
void step5(char a[len][wid])//一般型,以sx5,sy5為中心點
{
    a[sy5][sx5-12]=E;
    a[sy5][sx5-11]=E;
    a[sy5][sx5-10]=E;
    a[sy5][sx5-9]=E;
    a[sy5][sx5-8]=E;
    a[sy5][sx5-7]=E;
    a[sy5][sx5-6]=E;
    a[sy5][sx5-5]=E;
    a[sy5][sx5-4]=E;
    a[sy5][sx5-3]=E;
    a[sy5][sx5-2]=E;
    a[sy5][sx5-1]=E;
    a[sy5][sx5]=E;
    a[sy5][sx5+1]=E;
    a[sy5][sx5+2]=E;
    a[sy5][sx5+3]=E;
    a[sy5][sx5+4]=E;
    a[sy5][sx5+5]=E;
    a[sy5][sx5+6]=E;
    a[sy5][sx5+7]=E;
    a[sy5][sx5+8]=E;
    a[sy5][sx5+9]=E;
    a[sy5][sx5+10]=E;
    a[sy5][sx5+11]=E;
    a[sy5][sx5+12]=E;

    return;
}
void step6(char a[len][wid])//一般型,以sx6,sy6為中心點
{
    a[sy6][sx6-12]=F;
    a[sy6][sx6-11]=F;
    a[sy6][sx6-10]=F;
    a[sy6][sx6-9]=F;
    a[sy6][sx6-8]=F;
    a[sy6][sx6-7]=F;
    a[sy6][sx6-6]=F;
    a[sy6][sx6-5]=F;
    a[sy6][sx6-4]=F;
    a[sy6][sx6-3]=F;
    a[sy6][sx6-2]=F;
    a[sy6][sx6-1]=F;
    a[sy6][sx6]=F;
    a[sy6][sx6+1]=F;
    a[sy6][sx6+2]=F;
    a[sy6][sx6+3]=F;
    a[sy6][sx6+4]=F;
    a[sy6][sx6+5]=F;
    a[sy6][sx6+6]=F;
    a[sy6][sx6+7]=F;
    a[sy6][sx6+8]=F;
    a[sy6][sx6+9]=F;
    a[sy6][sx6+10]=F;
    a[sy6][sx6+11]=F;
    a[sy6][sx6+12]=F;

    return;
}
void step7(char a[len][wid])//一般型,以sx7,sy7為中心點
{
    a[sy7][sx7-12]=G;
    a[sy7][sx7-11]=G;
    a[sy7][sx7-10]=G;
    a[sy7][sx7-9]=G;
    a[sy7][sx7-8]=G;
    a[sy7][sx7-7]=G;
    a[sy7][sx7-6]=G;
    a[sy7][sx7-5]=G;
    a[sy7][sx7-4]=G;
    a[sy7][sx7-3]=G;
    a[sy7][sx7-2]=G;
    a[sy7][sx7-1]=G;
    a[sy7][sx7]=G;
    a[sy7][sx7+1]=G;
    a[sy7][sx7+2]=G;
    a[sy7][sx7+3]=G;
    a[sy7][sx7+4]=G;
    a[sy7][sx7+5]=G;
    a[sy7][sx7+6]=G;
    a[sy7][sx7+7]=G;
    a[sy7][sx7+8]=G;
    a[sy7][sx7+9]=G;
    a[sy7][sx7+10]=G;
    a[sy7][sx7+11]=G;
    a[sy7][sx7+12]=G;

    return;
}
