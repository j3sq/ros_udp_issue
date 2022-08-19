#include "ros/ros.h"
#include "test_pkg/aabbccddeeffgghhiij.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "abcdefghijklmnopqrstuvw"); // must be 23 chars long
  ros::NodeHandle nh{};
  ros::Subscriber pub =
      nh.subscribe<test_pkg::aabbccddeeffgghhiij>(   // Must be 29 chars long
                                                     // (namespace + msg name)
          "/abcdefghijklmnopqrstuvwxyzabcdefgh", 10, // must be 34 chars long
          [](const test_pkg::aabbccddeeffgghhiij::ConstPtr &msg) {
            ROS_INFO("Received msg with foo=%d", msg->foo);
          },
          ros::TransportHints()
              .unreliable()
              .reliable()); // must be UDP connection

  ROS_INFO("Waiting for msg....");
  ros::spin();
}
