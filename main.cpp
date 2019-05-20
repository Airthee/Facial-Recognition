#include <opencv2/opencv.hpp>

int main () {
  try {
    // Ouverture caméra
    cv::VideoCapture videoOpenCv;
    bool test = videoOpenCv.open(0);
    if (test == false) {
      throw -101;
    }
    // Allocation mémoire image
    cv::Mat img;

    // Ouerture caméra en difect
    // int count = 0;

    // time_t start;
    // time(&start);

    cv::namedWindow("Window2", cv::WINDOW_AUTOSIZE);
    while (true) {
      // count++;
      videoOpenCv.read(img);
      int key = cv::waitKey(1000/25);
      if (key == (int)'q') {
        break;
      }
      // count = calculationFPS(&start, count);
    }

    videoOpenCv.read(img);
    cv::imwrite("test.png", img);
  }

  catch (int e) {
    return e;
  }

  return 0;
}