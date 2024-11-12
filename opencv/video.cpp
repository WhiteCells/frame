#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <unistd.h>

int main(int argc, char *argv[])
{
    chdir("../");
    cv::VideoCapture capture;

    // 读取摄像头
    // Windows cv::DSHOW
    // Linux cv::CAP_V4L2 或 cv::CAP_ANY
    // if (!capture.open(0, cv::CAP_V4L2)) {
    //     printf("could not open camera\n");
    //     return 1;
    // }

    // cv::CAP_FFMPEG
    // cv::CAP_IMAGES
    // cv::CAP_DSHOW
    // 读取视频文件或视频流
    // avi、mp4、wav 等
    capture.open("./test.mp4", cv::CAP_FFMPEG);

    // 从 URL 中读取
    // capture.open("https://xxx.xxx", cv::CAP_ANY);

    int height = capture.get(cv::CAP_PROP_FRAME_HEIGHT); // 帧高度
    int width = capture.get(cv::CAP_PROP_FRAME_WIDTH);   // 帧宽度
    double fps = capture.get(cv::CAP_PROP_FPS);          // 帧率

    // cv::VideoWriter writer("./out.avi", capture.get(cv::CAP_PROP_FOURCC), fps, cv::Size(width, height));
    cv::VideoWriter writer("./out.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));

    cv::Mat frame;
    while (true) {
        bool ret = capture.read(frame);
        if (!ret) {
            break;
        }
        int height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);  // 帧高度
        int width = capture.get(cv::CAP_PROP_FRAME_WIDTH);    // 帧宽度
        double fps = capture.get(cv::CAP_PROP_FPS);           // 帧率
        double count = capture.get(cv::CAP_PROP_FRAME_COUNT); // 总帧数
        printf("h: %d, w: %d, fps: %.2lf, count: %.2lf\n", height, width, fps, count);
        std::string text = "Resolution: " + std::to_string(width) + "x" + std::to_string(height) +
                           " | FPS: " + std::to_string(fps);
        cv::putText(frame, text, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 2);
        cv::imshow("frame", frame);
        writer.write(frame);
        char c = cv::waitKey(100);
        if (c == 27) {
            break;
        }
    }

    // 释放 cv::VideoCapture 对象
    capture.release();
    // 释放 cv::VideoWriter 对象
    writer.release();
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}