#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "math.h"

#include "unicyclesim/Spawn.h"
#include "unicyclesim/Kill.h"
#include "unicyclesim/SetPen.h"



#include <sstream>

//spawn Follower
//Aufruf mit "rosrun follower_regler spawnFollower"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "spawn_Follower");
  
  ros::NodeHandle m_node;
  ros::Publisher pub = m_node.advertise<std_msgs::String>("spawnFollower", 1000);



  // client to create a new robot in unicyclesim
  ros::ServiceClient servSpawn2 = m_node.serviceClient<unicyclesim::Spawn>("/sim/spawn");

  // spawn a new robot named robot2
  unicyclesim::Spawn spawnMsg;
    spawnMsg.request.x = 2;
    spawnMsg.request.y = 2.5;
    spawnMsg.request.name == "robot2";
  servSpawn2.call(spawnMsg);

  ros::ServiceClient servSpawn3 = m_node.serviceClient<unicyclesim::Spawn>("/sim/spawn");

  // spawn a new turtle named robot3
    spawnMsg.request.x = 2.5;
    spawnMsg.request.y = 2;
    spawnMsg.request.name == "robot3";
  servSpawn3.call(spawnMsg);

  ros::ServiceClient servSpawn4 = m_node.serviceClient<unicyclesim::Spawn>("/sim/spawn");

  // spawn a new turtle named robot4
    spawnMsg.request.x = 2;
    spawnMsg.request.y = 2;
    spawnMsg.request.name == "robot4";
  servSpawn4.call(spawnMsg);


  ros::ServiceClient servPen2 = m_node.serviceClient<unicyclesim::SetPen>("/robot2/set_pen");
  ros::ServiceClient servPen3 = m_node.serviceClient<unicyclesim::SetPen>("/robot3/set_pen");
  ros::ServiceClient servPen4 = m_node.serviceClient<unicyclesim::SetPen>("/robot4/set_pen");
  unicyclesim::SetPen penMsg2, penMsg3, penMsg4;


  //Linienfarben der Follower-Roboter einstellen (rgb)
  //robot2 = lila --- robot3 = grün --- robot4 = gelb
  
  penMsg2.request.r = 204;
  penMsg2.request.g = 153;
  penMsg2.request.b = 255;
  penMsg2.request.width = 3;
  servPen2.call(penMsg2);

  penMsg3.request.g = 255;
  penMsg3.request.width = 3;
  servPen3.call(penMsg3);

  penMsg4.request.r = 255;
  penMsg4.request.g = 255;
  penMsg4.request.width = 3;
  servPen4.call(penMsg4);


  //refresh rate in Hz
  ros::Rate loop_rate(50);

  return 0;
}
