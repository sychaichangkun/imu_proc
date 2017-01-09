# A ROS Node For Xbot IMU data fusion.
The yaw read from Xbot controller is not accurate to be used, so we decide decide to compute yaw using the raw imu data/.

Input data:9 axis raw data
Input topic:"/mobile_base/sensors/imu_data_raw"

Output data:Yaw(only)
Output topic:""

Fusion algorithm:
MadgwichAHRS
MahonyAHRS
....
 
