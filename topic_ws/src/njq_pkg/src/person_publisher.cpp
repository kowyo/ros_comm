#include "ros/ros.h"
#include "njq_pkg/PersonNongjinqi.h"  // for PersonNongjinqi message
#include "njq_pkg/GroupNongjinqi.h"   // for GroupNongjinqi message

int main(int argc, char **argv) {
    ros::init(argc, argv, "person_publisher");
    ros::NodeHandle nh;
    ros::Publisher person_publisher = nh.advertise<njq_pkg::PersonNongjinqi>("person_topic", 10);
    ros::Rate rate(1);  // 1 Hz

    while (ros::ok()) {
        njq_pkg::PersonNongjinqi person_msg;
        person_msg.name = "Nongjinqi";
        person_msg.pos_x = 10;
        person_msg.pos_y = 5.5;

        ROS_INFO("Name: %s, X: %d, Y: %f", person_msg.name.c_str(), person_msg.pos_x, person_msg.pos_y);
        person_publisher.publish(person_msg);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
