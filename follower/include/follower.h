#ifndef follower_h
#define follower_h

#include "ros/ros.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/Image.h"
#include "image_transport/image_transport.h"
#include <vector>
#include <signal.h>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <librealsense2/rs.hpp>

using namespace std;
using namespace cv;
using namespace ros;

Mat image_second;
Mat depth_second;

Publisher steeringPub, throttlePub;

void SigintHandler(int sig);
Mat loadFrame(const sensor_msgs::ImageConstPtr& msg);
Mat loadDepthFrame(const sensor_msgs::ImageConstPtr& msg);
void depthCallback(const sensor_msgs::ImageConstPtr& msg);
void imageCallbackRGB(const sensor_msgs::ImageConstPtr& msg);


#endif
