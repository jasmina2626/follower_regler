#pragma once
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"




/**
 * @brief Funktion, um die lineare Geschwindigkeit des Roboters zu Regeln (entspricht linear.x)
 * 
 * @param[in] k1 positiv einstellbarer Parameter
 * @param[in] k2 positiv einstellbarer Parameter
 * @param[in] XF Globale X-Koordinate des Followers
 * @param[in] XL Globale X-Koordinate des Leaders
 * @param[in] YF Globale Y Koordinate des Followers
 * @param[in] YL Globale Y Koordinate des Leaders
 * @param[in] phid Orientiergungswinkel von Leader zu Followers, orientiert sich am Ausrichtungswinkel Theta vom Leader
 * @param[in] ld Konstanter Abstand von Leader zu Follower
 * @param[in] thetaL Ausrichtungswinkel des Leaders, an der X-Achse orientiert
 * @param[in] thetaF Ausrichtungswinkel des Followers, an der X-Achse orientiert
 * @param[in] d Abstand von der Vorderachse zur Hinterachse (Achtung: Maßstab!!!)
 * @param[in] wL Winkelgeschwindigkeit Leader
 * @param[out] vL Lineare Geschwindigkeit Leader
 * 
 * @return Am Ende wird v_F zurückgegeben, das entspricht der linearen Geschwindigkeit des jeweiligen Follower-Roboters
*/
float vF(float k1, float k2, float XF, float XL, float YF, float YL, float phid, float ld, float thetaL, float thetaF, float d, float wL, float vL);


/**
 * @brief Funktion, um die angulare Geschwindigkeit des Roboters zu Regeln (entspricht angular.z)
 * 
 * @param[in] k1 positiv einstellbarer Parameter
 * @param[in] k2 positiv einstellbarer Parameter
 * @param[in] XF Globale X-Koordinate des Followers
 * @param[in] XL Globale X-Koordinate des Leaders
 * @param[in] YF Globale Y Koordinate des Followers
 * @param[in] YL Globale Y Koordinate des Leaders
 * @param[in] phid Orientiergungswinkel von Leader zu Followers, orientiert sich am Ausrichtungswinkel Theta vom Leader
 * @param[in] ld Konstanter Abstand von Leader zu Follower
 * @param[in] thetaL Ausrichtungswinkel des Leaders, an der X-Achse orientiert
 * @param[in] thetaF Ausrichtungswinkel des Followers, an der X-Achse orientiert
 * @param[in] d Abstand von der Vorderachse zur Hinterachse (Achtung: Maßstab!!!)
 * @param[in] wL Winkelgeschwindigkeit Leader
 * @param[out] vL Lineare Geschwindigkeit Leader
 * 
 * @return Am Ende wird w_F zurückgegeben, das entspricht der angularen Geschwindigkeit des jeweiligen Follower-Roboters
*/
float wF(float k1, float k2, float XF, float XL, float YF, float YL, float phid, float ld, float thetaL, float thetaF, float d, float wL, float vL);