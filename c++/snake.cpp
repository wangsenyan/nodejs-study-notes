#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define H 22
#define W 22
using namespace std;

class chessboard
{
public:
  char qp[H][W];
  int i, j, x1, y1;
  chessboard();
  void food();
  void prt(int grade, int score, int gamespeed);
};
chessboard::chessboard()
{
  for (i = 1; i <= H - 2; i++)
    for (j = 1; j <= W - 2; j++)
      qp[i][j] = ' ';
  for (i = 0; i <= H - 1; i++)
    qp[0][i] = qp[H - 1][i] = '|';
  for (i = 1; i <= H - 2; i++)
    qp[i][0] = qp[i][W - 1] = '|';
  food();
}
void chessboard::food()
{
  srand(time(0));
  do
  {
    x1 = rand() % W - 2 + 1;
    y1 = rand() % H - 2 + 1;
  } while (qp[x1][y1] != ' ');
  qp[x1][y1] = '$';
}
void chessboard::prt(int grade, int score, int gamespeed)
{
  system("cls");
  cout << endl;
  for (i = 0; i < H; i++)
  {
    cout << "\t";
    for (j = 0; j < W; j++)
      cout << qp[i][j] << ' ';
    if (i == 0)
      cout << "\tGrade:" << grade;
    if (i == 2)
      cout << "\tScore:" << score;
    if (i == 4)
      cout << "\tAutomatic forward";
    if (i == 5)
      cout << "\ttime interval:" << gamespeed << "ms";
    cout << endl;
  }
}
class snake : public chessboard
{
public:
  int zb[2][100];
  long start;
  int head, tail, grade, score, gamespeed, length, timeover, x, y;
  char direction;
  snake();
  void move();
};
snake::snake()
{
  cout << "\n\n\t\tThe game is about to begin!" << endl;
  for (i = 3; i >= 0; i--)
  {
    start = clock();
    while (clock() - start <= 1000)
      ;
    system("cls");
    if (i > 0)
      cout << "\n\n\t\tCountdown:" << i << endl;
  }
  for (i = 1; i <= 3; i++)
    qp[1][i] = '*';
  qp[1][4] = '@';
  for (i = 0; i < 4; i++)
  {
    zb[0][i] = 1;
    zb[1][i] = i + 1;
  }
}
void snake::move()
{
  score = 0;
  head = 3, tail = 0;
  grade = 1, length = 4;
  gamespeed = 5000;
  direction = 77;
  while (1)
  {
    timeover = 1;
    start = clock();
    //kbhit() 检查当前是否有键盘输入，若有则返回一个非0值，否则返回0  int kbhit(void);  include <conio.h>
    while ((timeover = (clock() - start <= gamespeed)) && !kbhit())
      ;
    if (timeover)
    {
      getch();             //getch()函数不将读入的字符回显在显示屏幕上
      direction = getch(); //低八位存ascii码，高八位存扫描码 72 77 80 75即表示方向键 上 右 下 左
    }
    switch (direction)
    {
    case 72:
      x = zb[0][head] - 1;
      y = zb[1][head];
      break;
    case 80:
      x = zb[0][head] + 1;
      y = zb[1][head];
      break;
    case 75:
      x = zb[0][head];
      y = zb[1][head] - 1;
      break;
    case 77:
      x = zb[0][head];
      y = zb[1][head] + 1;
      break;
    }
    if (x == 0 || x == W - 1 || y == 0 || y == H - 1)
    {
      cout << "\tGame over!" << endl;
      break;
    }
    if (qp[x][y] != ' ' && !(x == x1 && y == y1))
    {
      cout << "\tGame over!" << endl;
      break;
    }
    if (x == x1 && y == y1)
    {
      length++;
      score = score + 100;
      if (length >= 8)
      {
        length -= 8;
        grade++;
        if (gamespeed >= 200)
          gamespeed = 550 - grade * 50;
      }
      qp[x][y] = '@';
      qp[zb[0][head]][zb[1][head]] = '*';
      head = (head + 1) % 100;
      zb[0][head] = x;
      zb[1][head] = y;
      food();
      prt(grade, score, gamespeed);
    }
    else
    {
      qp[zb[0][tail]][zb[1][tail]] = ' ';
      tail = (tail + 1) % 100;
      qp[zb[0][head]][zb[1][head]] = '*';
      head = (head + 1) % 100;
      zb[0][head] = x;
      zb[1][head] = y;
      qp[zb[0][head]][zb[1][head]] = '@';
      prt(grade, score, gamespeed);
    }
  }
}
int main()
{
  chessboard cb;
  snake s;
  s.move();
}