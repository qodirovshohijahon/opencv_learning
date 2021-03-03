#include <iostream>

#include <opencv2/opencv.hpp>
int main() {
  std::cout << "Hello World~\n";
  std::cout << "Hello OpenCV\n";
  
  cv::Mat image = cv::imread("./spring.jpg");
  cv::Mat grey_image = cv::imread("./spring.jpg", cv::IMREAD_GRAYSCALE);

  if (image.empty()) {
    std::cerr << "Image not found\n";
    return 1;
  }

  const std::string window_name{"spring"};
  const std::string grey_window_name{"spring_grey"};

  cv::namedWindow(window_name);
  cv::namedWindow(grey_window_name);
  cv::imshow(window_name, image);
  cv::imshow(grey_window_name, grey_image);
  cv::waitKey(0);
  return 0;
}