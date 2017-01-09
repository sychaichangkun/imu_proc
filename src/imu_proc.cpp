#include "ros/ros.h"
#include "std_msgs/String.h"
#include "imu_proc/MadgwickAHRS.h"
#include "imu_proc/MahonyAHRS.h"
#include "xbot_msgs/ImuNine.h"
#include <tf/transform_datatypes.h>

#include <iostream>
using namespace std;

//void imudata_proc(const std_msgs::String::ConstPtr& msg)
void imudata_proc(const xbot_msgs::ImuNine& msg)
{
  //test
  float acce_x=((short)msg.accex)/16432.0;  //g
  float acce_y=((short)msg.accey)/16432.0;
  float acce_z=((short)msg.accez)/16432.0;
  float gyro_x=((short)msg.gyrox)/65.728;  //degree/s
  float gyro_y=((short)msg.gyroy)/65.728;
  float gyro_z=((short)msg.gyroz)/65.728;
  float mag_x=((short)msg.magx)/1.0;    //gauss
  float mag_y=((short)msg.magy)/1.0;    //devide by 1370  ,  get the original data
  float mag_z=((short)msg.magz)/1.0;
//      cout<<acce_x<<"   "<<acce_y<<"   "<<acce_z<<"    "<<gyro_x<<"    "<<gyro_y<<"    "<<gyro_z<<"    "<<
//            mag_x<<"    "<<mag_y<<"    "<<mag_z<<endl;
   //  MadgwickAHRSupdate(acce_x,acce_y,acce_z,gyro_x,gyro_y,gyro_z,mag_x,mag_y,mag_z);
   MahonyAHRSupdate(acce_x,acce_y,acce_z,gyro_x,gyro_y,gyro_z,mag_x,mag_y,mag_z);

    geometry_msgs::Quaternion q;
   q.x=q0;
   q.y=q1;
   q.z=q2;
   q.w=q3;
   double yaw=tf::getYaw(q);
   cout<<"yaw:  "<<yaw<<endl;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/mobile_base/sensors/imu_data_raw", 1000, imudata_proc);

  ros::spin();

  return 0;
}
