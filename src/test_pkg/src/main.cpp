#include "ros/ros.h"
#include "test_pkg/aabbccddeeffgghhiij.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "abcdefghijklmnopqrstuvw");
  ros::NodeHandle nh{};
  ros::Subscriber pub = nh.subscribe<test_pkg::aabbccddeeffgghhiij>(
      "/abcdefghijklmnopqrstuvwxyzabcdefgh", 1,
      [](const test_pkg::aabbccddeeffgghhiij::ConstPtr &msg) {
        ROS_INFO("Received msg with foo=%d", msg->foo);
      },
      ros::TransportHints().unreliable().reliable()); // must be UDP connection

  ROS_INFO("Waiting for msg....");
  ros::spin();
}
