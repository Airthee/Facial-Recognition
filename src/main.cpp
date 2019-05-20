#include <opencv2/opencv.hpp>
#include <string.h>

using namespace std;

int main () {
  try {
    // Ouverture caméra
    cv::VideoCapture videoOpenCv;
    bool test = videoOpenCv.open(0);
    if (test == false) {
      throw -101;
    }
    // Allocation mémoire image
    cv::Mat imgBW;
    cv::Mat imgColor;

    cv::namedWindow("window2", cv::WINDOW_AUTOSIZE);
    int key;

    // Training with camera
    for (int i = 0; i < 10; i++) {
      key = cv::waitKey(1000);
      string filename = "s" + to_string(i) + ".png";
      videoOpenCv.read(imgColor);
      cv::imshow("window2", imgColor);
      cvtColor(imgColor, imgBW, CV_RGB2GRAY);
      cv::imwrite(filename, imgBW);
    }

    // while (true) {
    //   // count++;
    //   videoOpenCv.read(img);
    //   cv::imshow("window2", img);
    //   key = cv::waitKey(1000/25);
    //   if(key==(int)'q'){
    //     cv::imwrite("test.png", img);
    //     break;
    //   }
    //   // count = calculationFPS(&start, count);
    // }
  }

  catch (int e) {
    return e;
  }

  return 0;
}