#include "../include/follower.h"
#include "follower_library.cpp"

int main(int argc, char** argv)
{
  init(argc, argv, "cv_bridge_converter", init_options::NoSigintHandler);
  NodeHandle n;

  ROS_INFO_STREAM("CV_BRIDGE converter Node Is Up");
  Subscriber imageSubRGB = n.subscribe("/rgb_image", 1, imageCallbackRGB);
  //Subscriber depthSub = n.subscribe("/align_depth", 1, depthCallback);
  Publisher image_pub = n.advertise<sensor_msgs::Image>("image_bgr8", 2);
  //Publisher align_pub = n.advertise<sensor_msgs::Image>("align_depth_type", 2);

  signal(SIGINT, SigintHandler);
  Rate rate(30); // 30Hz

  sensor_msgs::Image im_msg;
  while (ok())
  {
    // Publishing messages
    cv_bridge::CvImage cv_image;
    cv_image.image = image_second;
    cv_image.encoding = "bgr8";
    sensor_msgs::Image ros_image;
    cv_image.toImageMsg(ros_image);
    image_pub.publish(ros_image);


    //cv_bridge::CvImage cv_depth;
    //cv_depth.image = depth_second;
    //cv_depth.encoding = "16UC1";
    //sensor_msgs::Image ros_depth;
    //cv_depth.toImageMsg(ros_depth);
    //align_pub.publish(ros_depth);

    rate.sleep();
    spinOnce();
  }
  return 0;
}
