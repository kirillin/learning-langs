#include <iostream>
#include <iomanip>

using namespace std;

void cycles() {
  int cnt = 0;
  int n = 5;

  // snake print:
  // 0   1   2   3   4
  // 9   8   7   6   5
  // 10  11  12  13  14
  // 19  18  17  16  15
  // 20  21  22  23  24
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if ((i+1) % 2 == 0) {
        cout << setw(4) << cnt + n - 1;
        cnt--;
      } else {
        cout << setw(4) << cnt;
        cnt++;
      }
    }
    cout << endl;
    cnt = n * (i + 1);
  }

  cout << endl;

  // spiral print:
  //  0   1   2   3   4
  // 15  16  17  18   5
  // 14  23  24  19   6
  // 13  22  21  20   7
  // 12  11  10   9   8
  int s[n][n];
  cnt = 0;
  int j = 0;
  while (cnt < n * n) {
    // row up
    for(int i = j; i < n-j; i++) {
      s[j][i] = cnt;
      cnt++;
    }
    // right col
    for(int i = j+1; i < n-j; i++) {
      s[i][n-1-j] = cnt;
      cnt++;
    }
    // row down
    for(int i = n-j-2; i >= j; i--) {
      s[n-1-j][i] = cnt;
      cnt++;
    }
    // left col
    for(int i = n-2-j; i > j; i--) {
      s[i][j] = cnt;
      cnt++;
    }
    j++;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << setw(4) << s[i][j];
    }
    cout << endl;
  }
}

void keyboard() {
  char ch;
  while (cin >> ch) {
    switch(ch) {
      case 'w': {
        cout << "w\r";
        break;
      }
      case 's': {
        cout << "s\r";
        break;
      }
      case 'a': {
        cout << "a\r";
        break;
      }
      case 'd': {
        cout << "d\r";
        break;
      }
    }
  }
}

int main() {
  // cycles();
  keyboard();

  return 0;
}
