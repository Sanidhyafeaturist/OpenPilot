#include <iostream>
#include <vector>
#include "opencvlib/include/opencv2/opencv.hpp" // Make sure to link OpenCV in your project

class CameraSensor {
public:
    CameraSensor(int cameraIndex) : cameraIndex(cameraIndex) {
        // Open the camera
        camera.open(cameraIndex);
        if (!camera.isOpened()) {
            std::cerr << "Error: Camera not found!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    ~CameraSensor() {
        // Release the camera when done
        camera.release();
    }

    cv::Mat captureImage() {
        cv::Mat frame;
        camera >> frame; // Capture a frame from the camera
        if (frame.empty()) {
            std::cerr << "Error: Captured frame is empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        return frame;
    }

    void processImage(const cv::Mat& image) {
        // Convert to grayscale
        cv::Mat grayImage;
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
        
        // Example processing: Edge detection
        cv::Mat edges;
        cv::Canny(grayImage, edges, 100, 200);

        // Display the processed image (optional)
        cv::imshow("Edges", edges);
        cv::waitKey(1); // Wait for 1 ms to display
    }

private:
    int cameraIndex;
    cv::VideoCapture camera;
};

extern "C" {
    void load_camera_sensor() {
        CameraSensor cameraSensor(0); // Use the first camera
        while (true) {
            cv::Mat image = cameraSensor.captureImage();
            cameraSensor.processImage(image);
        }
    }
}
