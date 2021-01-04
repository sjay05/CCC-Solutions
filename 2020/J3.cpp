#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int right = 0, left = 0, top = 0, bottom = 0;

  for (int a = 0; a < N; ++a) {
    int inX, inY;
    cin >> inX;
    cin.ignore(1);
    cin >> inY;
    
    if (a == 0) {
      right = inX + 1;
      left = inX - 1;
      top = inY + 1;
      bottom = inY - 1;
    }
    else {
      if (inX <= left)
        left = inX - 1;
      else if (inX >= right)
        right = inX + 1;
      
      if (inY >= top)
        top = inY + 1;
      else if (inY <= bottom)
        bottom = inY - 1;
    }
  }

  cout << left << "," << bottom << "\n";
  cout << right << "," << top;
}
