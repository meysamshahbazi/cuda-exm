#include <opencv2/highgui.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <iostream>





int main(int argc, const char** argv)
{   
   
    // cv::Mat img;
    // int64 t1,t2,tick_counter;

    cv::Mat img = cv::imread(argv[1]);
    cv::cuda::GpuMat dst,src;

    
    int64 t1 = cv::getTickCount();
    src.upload(img);
    
    for (int i = 0; i <10000;i++){
        cv::cuda::cvtColor(src,dst,cv::COLOR_BGR2HSV);
        cv::cuda::cvtColor(dst,src,cv::COLOR_HSV2BGR);
    }
    src.download(img);
    int64 t2 = cv::getTickCount();
    

    
    int64 tick_counter = t2 - t1;
    

    std::cout << "Elapsed sec GPU: " << static_cast<double>(tick_counter)*1000 / cv::getTickFrequency() << std::endl;

    
    img = cv::imread(argv[1]);
    cv::Mat img2;
    t1 = cv::getTickCount();
    for (int i = 0; i <10000;i++){
        cv::cvtColor(img,img2,cv::COLOR_BGR2HSV);
        cv::cvtColor(img2,img,cv::COLOR_HSV2BGR);
    }
    
    t2 = cv::getTickCount();

    tick_counter = t2 - t1;

    std::cout << "Elapsed sec CPU: " << static_cast<double>(tick_counter) *1000/ cv::getTickFrequency() << std::endl;






    return 0;
} 

