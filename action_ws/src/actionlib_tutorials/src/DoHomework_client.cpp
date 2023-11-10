#include <actionlib/client/simple_action_client.h>
#include <actionlib_tutorials/DoHomeworkAction.h>

typedef actionlib::SimpleActionClient<actionlib_tutorials::DoHomeworkAction> Client;

void doneCb(const actionlib::SimpleClientGoalState& state, const actionlib_tutorials::DoHomeworkResultConstPtr& result){
    ROS_INFO("Yay! The homework are now done");
    ros::shutdown();
}

void activeCb(){
    ROS_INFO("Goal just went active");
}

void feedbackCb(const actionlib_tutorials::DoHomeworkFeedbackConstPtr& feedback){
    ROS_INFO("percent_complete: %f", feedback->percent_complete);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "do_homework_client");
  Client client("do_homework", true); // true -> don't need ros::spin()
  ROS_INFO("Wait for action server to start.");
  client.waitForServer();
  ROS_INFO("Action server started, sending goal.");

  actionlib_tutorials::DoHomeworkGoal goal;
  goal.student_id = 6;
  // Fill in goal here
  client.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);
  ros::spin(); // spin() needed since we are not using ros::spinOnce()
  return 0;
}