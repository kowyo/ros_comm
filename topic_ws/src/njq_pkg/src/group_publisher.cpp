#include "ros/ros.h"
#include "njq_pkg/PersonNongjinqi.h"  // for PersonNongjinqi message
#include "njq_pkg/GroupNongjinqi.h"   // for GroupNongjinqi message

int main(int argc, char **argv) {
    ros::init(argc, argv, "group_publisher");
    ros::NodeHandle nh;
    ros::Publisher group_publisher = nh.advertise<njq_pkg::GroupNongjinqi>("group_topic", 10);
    ros::Rate rate(1);  // 1 Hz

    while (ros::ok()) {
        njq_pkg::GroupNongjinqi group_msg;
        group_msg.group_name = "Group 1";
        group_msg.student_number = 2;
        group_msg.student_names = {"li", "Nongjinqi"};

        ROS_INFO("Group name: %s, Number: %d", group_msg.group_name.c_str(), group_msg.student_number);
        group_publisher.publish(group_msg);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
