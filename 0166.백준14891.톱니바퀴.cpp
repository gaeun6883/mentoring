//mentoring 168. 2022.3.3
//구현

#include <iostream>
#include <cmath>
using namespace std;

int k, wheel[4][8], tmp[4][8];
void roll(int n, int d);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            wheel[i][j] = s[j] - '0';
            tmp[i][j] = wheel[i][j];
        }
    }
    cin >> k;
    while (k--) {
        int n, d;
        cin >> n >> d;
        roll(n, d);
    }

    int result = 0;
    for (int i = 0; i < 4; i++)
        if (wheel[i][0])
            result += pow(2, i);
    cout << result;
    return 0;
}

void roll(int n, int d) {
    if (n == 1) {
        if (d == 1) {
            for (int i = 0; i < 7; i++)
                tmp[0][i + 1] = wheel[0][i];
            tmp[0][0] = wheel[0][7];
        }
        else if (d == -1) {
            for (int i = 0; i < 7; i++)
                tmp[0][i] = wheel[0][i + 1];
            tmp[0][7] = wheel[0][0];
        }

        int pre = wheel[0][2];
        int re_dir = (-1) * d;
        for (int i = 1; i < 4; i++) {
            if (pre == wheel[i][6])
                break;
            if (re_dir == 1) {
                for (int j = 0; j < 7; j++)
                    tmp[i][j + 1] = wheel[i][j];
                tmp[i][0] = wheel[i][7];
            }
            else if (re_dir == -1) {
                for (int j = 0; j < 7; j++)
                    tmp[i][j] = wheel[i][j + 1];
                tmp[i][7] = wheel[i][0];
            }
            pre = wheel[i][2];
            re_dir = (-1) * re_dir;
        }
    }
    else if (n == 2) {
        if (d == 1) {
            for (int i = 0; i < 7; i++)
                tmp[1][i + 1] = wheel[1][i];
            tmp[1][0] = wheel[1][7];
        }
        else if (d == -1) {
            for (int i = 0; i < 7; i++)
                tmp[1][i] = wheel[1][i + 1];
            tmp[1][7] = wheel[1][0];
        }

        int pre = wheel[1][6];
        int re_dir = (-1) * d;
        if (pre != wheel[0][2]) {
            if (re_dir == 1) {
                for (int i = 0; i < 7; i++)
                    tmp[0][i + 1] = wheel[0][i];
                tmp[0][0] = wheel[0][7];
            }
            else if (re_dir == -1) {
                for (int i = 0; i < 7; i++)
                    tmp[0][i] = wheel[0][i + 1];
                tmp[0][7] = wheel[0][0];
            }
        }

        pre = wheel[1][2];
        for (int i = 2; i < 4; i++) {
            if (pre == wheel[i][6])
                break;
            if (re_dir == 1) {
                for (int j = 0; j < 7; j++)
                    tmp[i][j + 1] = wheel[i][j];
                tmp[i][0] = wheel[i][7];
            }
            else if (re_dir == -1) {
                for (int j = 0; j < 7; j++)
                    tmp[i][j] = wheel[i][j + 1];
                tmp[i][7] = wheel[i][0];
            }
            pre = wheel[i][2];
            re_dir = (-1)*re_dir;
        }
    }
    else if (n == 3) {
        if (d == 1) {
            for (int i = 0; i < 7; i++)
                tmp[2][i + 1] = wheel[2][i];
            tmp[2][0] = wheel[2][7];
        }
        else if (d == -1) {
            for (int i = 0; i < 7; i++)
                tmp[2][i] = wheel[2][i + 1];
            tmp[2][7] = wheel[2][0];
        }

        int pre= wheel[2][2];
        int re_dir = (-1)*d;
        if (pre != wheel[3][6]) {
            if (re_dir == 1) {
                for (int i = 0; i < 7; i++)
                    tmp[3][i + 1] = wheel[3][i];
                tmp[3][0] = wheel[3][7];
            }
            else if (re_dir == -1) {
                for (int i = 0; i < 7; i++)
                    tmp[3][i] = wheel[3][i + 1];
                tmp[3][7] = wheel[3][0];
            }
        }
        pre = wheel[2][6];
        for (int i = 1; i >= 0; i--) {
            if (pre == wheel[i][2])
                break;
            if (re_dir == 1) {
                for (int j = 0; j < 7; j++)
                    tmp[i][j + 1] = wheel[i][j];
                tmp[i][0] = wheel[i][7];
            }
            else if (re_dir == -1){
                for (int j = 0; j < 7; j++)
                    tmp[i][j] = wheel[i][j + 1];
                tmp[i][7] = wheel[i][0];
            }
            pre = wheel[i][6];
            re_dir = (-1)*re_dir;
        }
    }
    else if (n == 4) {
        if (d == 1) {
            for (int i = 0; i < 7; i++)
                tmp[3][i + 1] = wheel[3][i];
            tmp[3][0] = wheel[3][7];
        }
        else if (d == -1) {
            for (int i = 0; i < 7; i++)
                tmp[3][i] = wheel[3][i + 1];
            tmp[3][7] = wheel[3][0];
        }

        int pre = wheel[3][6];
        int re_dir = (-1) * d;
        for (int i = 2; i >= 0; i--) {
            if (pre == wheel[i][2])
                break;
            if (re_dir == 1) {
                for (int j = 0; j < 7; j++)
                    tmp[i][j + 1] = wheel[i][j];
                tmp[i][0] = wheel[i][7];
            }
            else if (re_dir == -1) {
                for (int j = 0; j < 7; j++)
                    tmp[i][j] = wheel[i][j + 1];
                tmp[i][7] = wheel[i][0];
            }
            pre = wheel[i][6];
            re_dir = (-1) * re_dir;
        }
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            wheel[i][j] = tmp[i][j];
}

//code.mento
/*int gear[5][8];
int rotated[5];
int T;

void rotate(int gearNumber,int dir) {
   if (rotated[gearNumber])
      return;
   rotated[gearNumber] = true;

   if (gearNumber - 1 >= 1 && gear[gearNumber][6] != gear[gearNumber - 1][2] && !rotated[gearNumber - 1])
      rotate(gearNumber - 1, 0 - dir);
   if (gearNumber + 1 <= 4 && gear[gearNumber][2] != gear[gearNumber + 1][6] && !rotated[gearNumber + 1])
      rotate(gearNumber + 1, 0 - dir);

   if (dir == 1) {//시계방향
      int tmp = gear[gearNumber][7];
      for (int i = 7; i >= 1; i--) {
         gear[gearNumber][i] = gear[gearNumber][i - 1];
      }
      gear[gearNumber][0] = tmp;
   }
   else {//반시계
      int tmp = gear[gearNumber][0];
      for (int i = 0; i <= 6; i++) {
         gear[gearNumber][i] = gear[gearNumber][i + 1];
      }
      gear[gearNumber][7] = tmp;
   }
}*/
