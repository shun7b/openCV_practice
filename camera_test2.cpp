#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
int main(int, char**) {

  	VideoCapture cap(0);
  	if(!cap.isOpened()){ 
		return -1;
	}
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 320);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
    cap.set(cv::CAP_PROP_FPS, 15);
  Mat frame, edges;
  namedWindow("edges", WINDOW_AUTOSIZE);
  for (;;) {
    cap >> frame;

    // 色をグレースケールに
    cvtColor(frame, edges, COLOR_BGR2GRAY);
    // ガウスフィルターで画像をぼかす
    GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);

    // キャニー法によるエッジ抽出
    Canny(edges, edges, 0, 30, 3);

    // ウィンドウを表示
    imshow("edges",frame);
    if(waitKey(30) >= 0) break;
  }

  return 0;
}
