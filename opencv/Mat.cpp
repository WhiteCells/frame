#include "opencv2/highgui.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    cv::Mat m1(4, 4, CV_8UC1, cv::Scalar(255));
    std::cout << m1 << "\n\n";

    cv::Mat m2(cv::Size(4, 4), CV_8UC3, cv::Scalar(0, 0, 255));
    std::cout << m2 << "\n\n";

    cv::Mat m3(cv::Size(4, 4), CV_8UC3, cv::Scalar::all(255));
    std::cout << m3 << "\n\n";

    // 支持 MatLab zeros ones eyes 等
    cv::Mat m4 = cv::Mat::zeros(cv::Size(4, 4), CV_8UC3);
    std::cout << m4 << "\n\n";

    cv::Mat m5 = cv::Mat::ones(cv::Size(4, 4), CV_8UC3);
    std::cout << m5 << "\n\n";

    cv::Mat m6 = cv::Mat::eye(cv::Size(4, 4), CV_8UC3);
    std::cout << m6 << "\n\n";

    // clone
    cv::Mat m7 = m6.clone();
    std::cout << m7 << "\n\n";

    // copyTo
    cv::Mat m8;
    m7.copyTo(m8);
    std::cout << m8 << "\n\n";

    // 列表方式初始化
    cv::Mat m9 = (cv::Mat_<double>(3, 3) << 0, 1, 0, 1, 0, 1, 0, 1, 0);
    std::cout << m9 << "\n\n";

    return 0;
}