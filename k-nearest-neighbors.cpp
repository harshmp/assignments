#include <iostream>
#include <math.h>
using namespace std;

int main() {
  float points[20][4];

  points[0][0] = 1;
  points[0][1] = 1;
  points[0][2] = 0;

  points[1][0] = 1;
  points[1][1] = 2;
  points[1][2] = 0;

  points[2][0] = 1;
  points[2][1] = 3;
  points[2][2] = 0;

  points[3][0] = 1;
  points[3][1] = 4;
  points[3][2] = 0;

  points[4][0] = 1;
  points[4][1] = 5;
  points[4][2] = 0;

  points[5][0] = 1;
  points[5][1] = 6;
  points[5][2] = 0;

  points[6][0] = 1;
  points[6][1] = 7;
  points[6][2] = 0;

  points[7][0] = 2;
  points[7][1] = 1;
  points[7][2] = 0;

  points[8][0] = 2;
  points[8][1] = 2;
  points[8][2] = 0;

  points[9][0] = 2;
  points[9][1] = 3;
  points[9][2] = 1;

  points[10][0] = 2;
  points[10][1] = 4;
  points[10][2] = 1;

  points[11][0] = 2;
  points[11][1] = 5;
  points[11][2] = 1;

  points[12][0] = 2;
  points[12][1] = 6;
  points[12][2] = 1;

  points[13][0] = 2;
  points[13][1] = 7;
  points[13][2] = 1;

  points[14][0] = 5;
  points[14][1] = 1;
  points[14][2] = 2;

  points[15][0] = 5;
  points[15][1] = 2;
  points[15][2] = 2;

  points[16][0] = 5;
  points[16][1] = 3;
  points[16][2] = 2;

  points[17][0] = 5;
  points[17][1] = 4;
  points[17][2] = 2;

  points[18][0] = 5;
  points[18][1] = 5;
  points[18][2] = 2;

  points[19][0] = 5;
  points[19][1] = 6;
  points[19][2] = 2;

  int knn = 0;
  float x, y;

  cout << "How many nearest neighbors to consider?\n";
  cin >> knn;

  cout << "Enter x coordinate:\n";
  cin >> x;
  cout << "Enter y coordinate:\n";
  cin >> y;

  for (size_t i = 0; i < 20; i++) {
    points[i][3] = sqrtf(powf(y - points[i][1], 2) + powf(x - points[i][0], 2));
  }

  float temp0, temp1, temp2, temp3;
  for (size_t i = 0; i < 20; i++) {
    for (size_t j = 1; j < 20; j++) {
      if (points[j-1][3] > points[j][3]) {
        temp0 = points[j-1][0];
        temp1 = points[j-1][1];
        temp2 = points[j-1][2];
        temp3 = points[j-1][3];

        points[j-1][0] = points[j][0];
        points[j-1][1] = points[j][1];
        points[j-1][2] = points[j][2];
        points[j-1][3] = points[j][3];

        points[j][0] = temp0;
        points[j][1] = temp1;
        points[j][2] = temp2;
        points[j][3] = temp3;
      }
    }
  }

  int shortCount = 0, averageCount = 0, tallCount = 0;

  for (size_t i = 0; i < knn; i++) {
    cout << "(" << points[i][0] << ", " << points[i][1] << ")";
    cout << endl;

    if (points[i][2] == 0) {
      shortCount++;
    }
    if (points[i][2] == 1) {
      averageCount++;
    }
    if (points[i][2] == 2) {
      tallCount++;
    }
  }
  cout << endl;

  if (shortCount > averageCount && shortCount > tallCount) {
    cout << "\nShort!\n";
  }
  else if (averageCount > shortCount && averageCount > tallCount) {
    cout << "\nAverage!\n";
  }
  else if (tallCount > shortCount && tallCount > averageCount) {
    cout << "\nTall!\n";
  }
  return 0;
}
