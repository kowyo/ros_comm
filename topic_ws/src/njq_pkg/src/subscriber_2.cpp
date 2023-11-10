#include "ros/ros.h"
#include "njq_pkg/PersonNongjinqi.h"
#include "njq_pkg/GroupNongjinqi.h"

void personCallback(const njq_pkg::PersonNongjinqi::ConstPtr& person_msg) {
    ROS_INFO("Received PersonNongjinqi: %s, %d, %f", person_msg->name.c_str(), person_msg->pos_x, person_msg->pos_y);
}

void groupCallback(const njq_pkg::GroupNongjinqi::ConstPtr& group_msg) {
    ROS_INFO("Received GroupNongjinqi: %s, %d", group_msg->group_name.c_str(), group_msg->student_number);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "subscriber2");
    ros::NodeHandle nh;

    ros::Subscriber person_subscriber = nh.subscribe("person_topic", 10, personCallback);
    ros::Subscriber group_subscriber = nh.subscribe("group_topic", 10, groupCallback);

    ros::spin();

    return 0;
}
