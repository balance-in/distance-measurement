#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  Mat imgSrc = imread("test.png");
  Mat imgDst, gray, edge;

  cvtColor(imgSrc, gray, COLOR_BGR2GRAY);
  blur(gray, gray, Size(3, 3));
  Canny(gray, edge, 3, 9, 3);  //边缘提取

  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;
  findContours(edge, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE,
               Point());  //提取轮廓点集
  Vec4f lines;            //存放拟合后的直线
  fitLine(contours[0], lines, DIST_L1, 0, 0.01, 0.01);  //拟合直线
  imshow("canny", edge);

  waitKey(0);
  return 0;
}