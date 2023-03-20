#include "ros/ros.h"
#include <iostream>
#include "unicyclesim/Spawn.h"
#include "unicyclesim/Pose.h"
#include "geometry_msgs/Twist.h"

#include "li_controller.h"

unicyclesim::Pose pose1, pose2, pose3, pose4;
void callback_robot1pose(const unicyclesim::Pose::ConstPtr& msg);
void callback_robot2pose(const unicyclesim::Pose::ConstPtr& msg);
void callback_robot3pose(const unicyclesim::Pose::ConstPtr& msg);
void callback_robot4pose(const unicyclesim::Pose::ConstPtr& msg);



int main(int argc, char **argv)
{

  ros::init(argc, argv, "followrobot_node");
  ros::NodeHandle n;

  float abstand = 0.6;
  float phi270 = 4.712389;
  float phi225 = 3.929908;
  float phi180 = 3.141593;
  float phi90 = phi180/2;
  float ld2 = abstand;
  float ld3 = abstand * sqrt(2);
  float ld4 = abstand;
  float distance = 0.05;

  //Lila
  float r2k1 = 1.2;
  float r2k2 = 1.2;
  //Grün
  float r3k1 = 1.3;
  float r3k2 = 1.3;
  //Gelb
  float r4k1 = 1.4;
  float r4k2 = 1.4;

  // publish data with type geometry_msgs::Twist on topic "/robotX/cmd_vel" with queque size 1
  ros::Publisher pubTwist1 = n.advertise<geometry_msgs::Twist>("/robot1/cmd_vel", 1);
  ros::Publisher pubTwist2 = n.advertise<geometry_msgs::Twist>("/robot2/cmd_vel", 1);
  ros::Publisher pubTwist3 = n.advertise<geometry_msgs::Twist>("/robot3/cmd_vel", 1);
  ros::Publisher pubTwist4 = n.advertise<geometry_msgs::Twist>("/robot4/cmd_vel", 1);

  // subscribe pose data with type unicyclesim::Pose on topic "/robotX/pose" with queque size 1
  ros::Subscriber subPose1 = n.subscribe("/robot1/pose", 1, callback_robot1pose);
  ros::Subscriber subPose2 = n.subscribe("/robot2/pose", 1, callback_robot2pose);
  ros::Subscriber subPose3 = n.subscribe("/robot3/pose", 1, callback_robot3pose);
  ros::Subscriber subPose4 = n.subscribe("/robot4/pose", 1, callback_robot4pose);

  // client to create a new robot in unicyclesim
  ros::ServiceClient servSpawn = n.serviceClient<unicyclesim::Spawn>("/sim/spawn");

  
  // refresh rate in Hz
  ros::Rate loop_rate(50);
  

  while (ros::ok()) // while roscore is running
  {

      geometry_msgs::Twist twist1, twist2, twist3, twist4;


      //Li_controller robot2 --> lila
      twist2.linear.x = vF(r2k1, r2k2, pose2.x, pose1.x, pose2.y, pose1.y, phi270, ld2, pose1.theta, pose2.theta, distance, twist1.angular.z, twist1.linear.x);
      twist2.angular.z = wF(r2k1, r2k2, pose2.x, pose1.x, pose2.y, pose1.y, phi270, ld2, pose1.theta, pose2.theta, distance, twist1.angular.z, twist1.linear.x);
      //Li_controller robot3 --> grün
      twist3.linear.x = vF(r3k1, r3k2, pose3.x, pose1.x, pose3.y, pose1.y, phi225, ld3, pose1.theta, pose3.theta, distance, twist1.angular.z, twist1.linear.x);
      twist3.angular.z = wF(r3k1, r3k2, pose3.x, pose1.x, pose3.y, pose1.y, phi225, ld3, pose1.theta, pose3.theta, distance, twist1.angular.z, twist1.linear.x);
      //Li_controller robot4 --> gelb
      twist4.linear.x = vF(r4k1, r4k2, pose4.x, pose1.x, pose4.y, pose1.y, phi180, ld4, pose1.theta, pose4.theta, distance, twist1.angular.z, twist1.linear.x);
      twist4.angular.z = wF(r4k1, r4k2, pose4.x, pose1.x, pose4.y, pose1.y, phi180, ld4, pose1.theta, pose4.theta, distance, twist1.angular.z, twist1.linear.x);


      // publish robot2 commands
      pubTwist2.publish(twist2);
      // publish robot3 commands
      pubTwist3.publish(twist3);
      // publish robot4 commands
      pubTwist4.publish(twist4);


    
    // let ROS Process services and publishers
    ros::spinOnce();

    // wait until rate is reached
    loop_rate.sleep();

  }


  return 0;
}

void callback_robot1pose(const unicyclesim::Pose::ConstPtr& msg){
  pose1.x = msg->x;
  pose1.y = msg->y;
  pose1.theta = msg->theta;
}

void callback_robot2pose(const unicyclesim::Pose::ConstPtr& msg){
  pose2.x = msg->x;
  pose2.y = msg->y;
  pose2.theta = msg->theta;
}

void callback_robot3pose(const unicyclesim::Pose::ConstPtr& msg){
  pose3.x = msg->x;
  pose3.y = msg->y;
  pose3.theta = msg->theta;
}

void callback_robot4pose(const unicyclesim::Pose::ConstPtr& msg){
  pose4.x = msg->x;
  pose4.y = msg->y;
  pose4.theta = msg->theta;
}