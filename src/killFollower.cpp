#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "math.h"

#include "unicyclesim/Spawn.h"
#include "unicyclesim/Kill.h"
#include "unicyclesim/SetPen.h"



#include <sstream>

//kill Follower
//Aufruf mit "rosrun follower_regler killFollower"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "kill_Follower");
  
  ros::NodeHandle m_node;
  ros::Publisher pub = m_node.advertise<std_msgs::String>("killFollower", 1000);


  //Killen, falls Follower schon vorhanden
  ros::ServiceClient servKill2 = m_node.serviceClient<unicyclesim::Kill>("/sim/kill");
  ros::ServiceClient servKill3 = m_node.serviceClient<unicyclesim::Kill>("/sim/kill");
  ros::ServiceClient servKill4 = m_node.serviceClient<unicyclesim::Kill>("/sim/kill");


  unicyclesim::Kill killMsg2, killMsg3, killMsg4;
  killMsg2.request.name = "robot2";
  servKill2.call(killMsg2);
  killMsg3.request.name = "robot3";
  servKill3.call(killMsg3);
  killMsg4.request.name = "robot4";
  servKill4.call(killMsg4);

    
  //unicyclesim::Reset r;
  //ros::ServiceVlient reset = m_node.serviceClient<unicyclesim::Reset>("/sim/reset");
  //reset.call(r)

  return 0;
}