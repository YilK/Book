P10 发布者Publisher的编程实现

1. 创建功能包
2. 创建发布者代码
3. 配置发布者代码编译规则
4. 编译并运行发布者

#### 1⃣️创建功能包

```
$ cd ~/catkin_ws/src
$ catkin_create_pkg learning_topic roscpp rospy std_msgs geometry_msgs turtlesim
```

#### 2⃣️创建发布者代码

如何实现一个发布者

- 初始化ROS节点
- 向ROS Master注册节点信息，包括发布的话题名和话题中的消息类型；
- 创建消息数据
- 按照一定频率循环发布消息

Velocity_publisher.cpp

```c++
/**
 * 该例程将发布turtle1/cmd_vel话题，消息类型geometry_msgs::Twist
 */
 
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
	// ROS节点初始化
	ros::init(argc, argv, "velocity_publisher");

	// 创建节点句柄
	ros::NodeHandle n;

	// 创建一个Publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度10
	ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

	// 设置循环的频率
	ros::Rate loop_rate(10);

	int count = 0;
	while (ros::ok())
	{
	    // 初始化geometry_msgs::Twist类型的消息
		geometry_msgs::Twist vel_msg;
		vel_msg.linear.x = 0.5;
		vel_msg.angular.z = 0.2;

	    // 发布消息
		turtle_vel_pub.publish(vel_msg);
		ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]", 
				vel_msg.linear.x, vel_msg.angular.z);

	    // 按照循环频率延时
	    loop_rate.sleep();
	}

	return 0;
}
```

这段代码放到**功能包**的src文件夹下。

#### 3⃣️配置发布者代码编译规则

找到**功能包**下的CMakeLists.txt

- 设置需要编译的代码和生成的可执行文件
- 设置链接库

```
add_executable(velocity_publisher src/velocity_publisher.cpp)
target_link_libraries(velocity_publisher ${catkin_LIBRARIES})
```

#### 4⃣️编译并运行发布者

```
$ cd ~/catkin_ws  要到工作空间之下。
$ catkin_make 编译工作空间
$ source devel/setup.bash 设置环境变量
运行发布者
$ roscore	
$ rosrun turtlesim turtlesim_node
$ rosrun learning_topic velocity_publisher
```

