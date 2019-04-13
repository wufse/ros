#include "ros/ros.h"
#include "std_msgs/String.h"


void Callback(const std_msgs::String::ConstPtr &msg)
{   
    ROS_INFO("I heard:[%s]",msg->data.c_str);
}



int main(int argc,char **argv)
{
    ros::init(argc,argv,"sub_node");
    ros::NodeHandle nh;
    ros::Subscriber chatter_sub=nh.subscribe("chatter",1000,Callback);
    ros::spin();
    
    return 0;
}

