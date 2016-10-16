#include<iostream>
#include<math.h>
using namespace std;


int main()
{
  float points[12][3];   // considering 7 points
  float centroids[2][3];  //  considering 2 centroids
  float oldCentroids[2][3];
  int clusterCount[2];    // clusterCount[0] = no. of points in cluster 0, clusterCount[1] = no. of points in cluster 1
  /* first column               second column                 third column */
  /*     ^                             ^                            ^         */
  /* all x co-ordinates         all y co-ordinates            all cluster IDs*/

  // initializing the x&y co-ordinates of all points (the cluster IDs will be assigned later)

  points[0][0] = 185;
  points[0][1] = 72;

  points[1][0] = 170;
  points[1][1] = 56;

  points[2][0] = 168;
  points[2][1] = 60;

  points[3][0] = 179;
  points[3][1] = 68;

  points[4][0] = 182;
  points[4][1] = 72;

  points[5][0] = 188;
  points[5][1] = 77;

  points[6][0] = 180;
  points[6][1] = 71;

  points[7][0] = 180;
  points[7][1] = 70;

  points[8][0] = 183;
  points[8][1] = 84;

  points[9][0] = 180;
  points[9][1] = 88;

  points[10][0] = 180;
  points[10][1] = 67;

  points[11][0] = 177;
  points[11][1] = 76;

  // initializing the x&y co-ordinates of the 2 chosen centroids (randomly chosen from points)

  centroids[0][0] = 185; // first centroid is point 0
  centroids[0][1] = 72;
  centroids[0][2] = 0;            // first centroid belongs to cluster 0

  centroids[1][0] = 170; // second centroid is point 3
  centroids[1][1] = 56;
  centroids[1][2] = 1;            // second centroid belongs to cluster 1

  cout<<"\nThe original centroids are -> \n";
  cout<<"("<<centroids[0][0]<<","<<centroids[0][1]<<") and ("<<centroids[1][0]<<","<<centroids[1][1]<<") !!!";

  bool hasAchievedPerfectCentroids = false;
  while(!hasAchievedPerfectCentroids)
  {
    for(int i=0;i<2;i++)
    {
      oldCentroids[i][0] = centroids[i][0];
      oldCentroids[i][1] = centroids[i][1];
      oldCentroids[i][2] = centroids[i][2];
    }

    for(int i=0;i<12;i++)
    {
      float min = 10000.0;
      for(int j=0;j<2;j++)
      {
        float distance = sqrtf((powf((centroids[j][1] - points[i][1]),2))+(powf((centroids[j][0]) - points[i][0],2)));
        if(distance < min)
        {
          min = distance;
          points[i][2] = j;
        }
      }
    }

    for(int i=0;i<2;i++)
    {
      centroids[i][0] = 0;
      centroids[i][1] = 0;
    }

    clusterCount[0] = 0;
    clusterCount[1] = 0;

    for(int i=0;i<12;i++)
    {
      if(points[i][2] == 0)
      {
        clusterCount[0]++;
        centroids[0][0] += points[i][0];
        centroids[0][1] += points[i][1];
      }
      else
      {
        clusterCount[1]++;
        centroids[1][0] += points[i][0];
        centroids[1][1] += points[i][1];
      }
    }

    centroids[0][0] = (centroids[0][0] / clusterCount[0]);
    centroids[0][1] = (centroids[0][1] / clusterCount[0]);

    centroids[1][0] = (centroids[1][0] / clusterCount[1]);
    centroids[1][1] = (centroids[1][1] / clusterCount[1]);

    hasAchievedPerfectCentroids = true;

    for(int i=0;i<2;i++)
    {
      if((centroids[i][0] != oldCentroids[i][0]) || (centroids[i][1] != oldCentroids[i][1]))
      {
        hasAchievedPerfectCentroids = false;
        break;
      }
    }

  }


    cout<<"\n\nPoint"<<"\t\t"<<"Cluster ID"<<"\n";

    for(int i=0;i<12;i++)
      cout<<(i+1)<<"\t\t"<<points[i][2]<<"\n";

    cout<<"\n\nAnd the new centroids are -> \n";
    cout<<"("<<centroids[0][0]<<","<<centroids[0][1]<<") and ("<<centroids[1][0]<<","<<centroids[1][1]<<") !!!\n\n";

    return 0;
  }
