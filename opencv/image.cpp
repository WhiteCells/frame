#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <unistd.h>

int main(int argc, char *argv[])
{
    chdir("../");

    // 实现图像的加载
    // 支持灰度、彩色、原始图像的加载
    // 默认情况下图像都是三通道 BGR 彩色图像
    cv::Mat img = cv::imread("./test.png");

    // 以灰度图像的形式加载
    // cv::Mat img = cv::imread("./test.png", cv::IMREAD_GRAYSCALE);
    // 加载具有透明通道的图像
    // cv::Mat img = cv::imread("./test.png", cv::IMREAD_UNCHANGED);
    if (img.empty()) {
        printf("could not load image ...\n");
        return 1;
    }
    cv::namedWindow("img", cv::WINDOW_AUTOSIZE);
    cv::imshow("img", img); // 显示图片会阻塞

    // imwrite 保存图像
    // 一般只需要设置保存文件的路径和 Mat 对象，也添加第三个参数
    // 用于调整保存图像的压缩质量、位图深度和通道数目

    // 保存为单道灰度图像
    cv::Mat gray_img;
    cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
    cv::imwrite("./out_gray.png", gray_img);

    // std::vector<int> opts1 {cv::IMWRITE_PAM_FORMAT_GRAYSCALE};
    // cv::imwrite("./out_gayscale.png", img, opts1);

    // 保存为默认 BGR 图像
    cv::imwrite("./out_default.png", img);

    // 保存为 PNG 彩色压缩图像
    std::vector<int> opts2 {cv::IMWRITE_PNG_COMPRESSION, 9}; // 0-9 值越大，压缩时间越长，图像大小越小
    cv::imwrite("./out_png_compression.png", img, opts2);

    // 保存为 JPG 高压压缩比图像
    std::vector<int> opts3 {cv::IMWRITE_JPEG_QUALITY, 50 /* 0-100 */, cv::IMWRITE_JPEG_OPTIMIZE, 1};
    cv::imwrite("./out_jpeg_compression.jpg", img, opts3);

    // 保存为 PNG 格式，且带透明通道
    cv::Mat img_alpha;
    if (img.channels() == 3) {
        cv::cvtColor(img, img_alpha, cv::COLOR_BGR2BGRA); // 转换为 BGRA 格式
    }
    else {
        img_alpha = img;
    }
    cv::imwrite("./out_png_rgb.png", img_alpha);

    cv::waitKey(0); // 参数大于 0 时，表示阻塞的毫秒数
    return 0;
}