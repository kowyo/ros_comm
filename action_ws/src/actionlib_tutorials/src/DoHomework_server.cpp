#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <actionlib_tutorials/DoHomeworkAction.h>

typedef actionlib::SimpleActionServer<actionlib_tutorials::DoHomeworkAction> Server;

void execute(const actionlib_tutorials::DoHomeworkGoalConstPtr& goal, Server* as)  // Note: "Action" is not appended to DoHomework here
{
    ros::Rate r(1);
    actionlib_tutorials::DoHomeworkFeedback feedback;
    ROS_INFO("Student %d is working.", goal->student_id);
    for (int i=1; i<=10; i++){
        feedback.percent_complete = i * 10;
        as->publishFeedback (feedback);
        r.sleep();
    }
    ROS_INFO ("Student %d finish working.", goal->student_id);
    as->setSucceeded();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "do_homework_server");
  ros::NodeHandle n;
  Server server(n, "do_homework", boost::bind(&execute, _1, &server), false);
  server.start();
  ros::spin();
  return 0;
}
// void execute (const actionlib_tutorials::DoHomeworkGoalConstPtr& goal, Server* as)
// {
//     ros::Rate r(1);
//     actionlib_tutorials::DoHomeworkFeedback feedback;
//     ROS_INFO("Student %d is working.", goal->student_id);
//     for (int =1; i<=10; i++){
//         feedback.percent_complete = i * 10;
//         as->publishFeedback (feedback);
//         r.sleep();
//     }
//     ROS_INFO ("Student %d finish working.", goal->student_id);
//     as->setSucceeded();
// }
// int main (int arg, char** argv){
//     ros::init(argc, argv, "do_homework_server")
//     ros::NodeHandle n;
//     Server server (n, "do_homework", boost::bind(&execute, _1, &server), false);
//     server.start;
//     ros::spin();
//     return 0;
// }
