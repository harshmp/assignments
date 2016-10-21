#include <iostream>
#include <math.h>
using namespace std;

int main() {
  float node[7][3];
  float centroid[2][3];
  float old_centroid[2][3];
  int nodes_in_cluster[2];

  node[0][0] = -1.0;
  node[0][1] = -1.0;
  node[1][0] = 1.5;
  node[1][1] = 2.0;
  node[2][0] = 3.0;
  node[2][1] = 4.5;
  node[3][0] = 5.5;
  node[3][1] = 2.5;
  node[4][0] = 6.0;
  node[4][1] = 6.0;
  node[5][0] = 10.0;
  node[5][1] = 8.5;
  node[6][0] = 14.0;
  node[6][1] = 11.5;

  centroid[0][0] = node[0][0];
  centroid[0][1] = node[0][1];
  centroid[0][2] = 0;
  centroid[1][0] = node[3][0];
  centroid[1][1] = node[3][1];
  centroid[1][2] = 1;

  cout << "Original centroids:\n";
  cout << "(" << centroid[0][0] << ", " << centroid[0][1] << ")" << endl;
  cout << "(" << centroid[1][0] << ", " << centroid[1][1] << ")" << endl;

  bool is_centroid_perfect = false;
  int i;

  while (!is_centroid_perfect) {
    for (i = 0; i < 2; i++) {
      old_centroid[i][0] = centroid[i][0];
      old_centroid[i][1] = centroid[i][1];
      old_centroid[i][2] = centroid[i][2];
    }

    float distance;

    for (i = 0; i < 7; i++) {
      float minimum = 10000.0;
      for (size_t j = 0; j < 2; j++) {
        distance = sqrtf(powf(centroid[j][1] - node[i][1], 2) + powf(centroid[j][0] - node[i][0], 2));

        if (distance < minimum) {
          minimum = distance;
          node[i][2] = j;
        }
      }
    }

    for (i = 0; i < 2; i++) {
      centroid[i][0] = 0;
      centroid[i][1] = 0;
    }

    nodes_in_cluster[0] = 0;
    nodes_in_cluster[1] = 0;

    for (i = 0; i < 7; i++) {
      if (node[i][2] == 0) {
        nodes_in_cluster[0]++;
        centroid[0][0] += node[i][0];
        centroid[0][1] += node[i][1];
      }
      else {
        nodes_in_cluster[1]++;
        centroid[1][0] += node[i][0];
        centroid[1][1] += node[i][1];
      }
    }

    for (i = 0; i < 2; i++) {
      centroid[i][0] = centroid[i][0] / nodes_in_cluster[i];
      centroid[i][1] = centroid[i][1] / nodes_in_cluster[i];
    }

    is_centroid_perfect = true;

    for (i = 0; i < 2; i++) {
      if (centroid[i][0] != old_centroid[i][0] || centroid[i][1] != old_centroid[i][1]) {
        is_centroid_perfect = false;
        break;
      }
    }
  }

  for (i = 0; i < 7; i++) {
    cout << "Node " << i << ": (" << node[i][0] << ", " << node[i][1] << ")" << " in cluster " << node[i][2] << "\n";
  }
  cout << "New centroids:\n";
  cout << "(" << centroid[0][0] << ", " << centroid[0][1] << ")" << endl;
  cout << "(" << centroid[1][0] << ", " << centroid[1][1] << ")" << endl;

  return 0;
}
