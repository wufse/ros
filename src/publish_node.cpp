#include "ros/ros.h"
#include "std_msgs/String.h"




int main()
{
    ros::init(argc,argv,"publish_node");
    ros::NodeHandle nh;
    ros::Publisher chatter_pub=nh.advertise<std_msgs::String>("chatter",1000);
    ros::Rate loop_rate(10);
    int cnt=0;
    while(ros::ok())
    {   
        std_msgs::String msg;
        std::stringstream ss;
        ss<<"how are you"<<cnt;
        msg.data=ss.str();
        ROS_INFO("%s",msg.data.c_str());
        chatter_pub.Publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        cnt++;
    
    }
}

