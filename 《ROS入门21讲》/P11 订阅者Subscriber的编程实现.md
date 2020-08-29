### P11 订阅者Subscriber的编程实现

#### 1⃣️创建订阅者代码

如何实现一个订阅者

- 初始化ROS节点；
- 订阅需要的话题；
- 循环等待话题消息，接受到消息后进入回调函数；
- 在回调函数中完成消息处理；

pose_subscriber.cpp

```c++
/**
 * 该例程将订阅/turtle1/pose话题，消息类型turtlesim::Pose
 */
 
#include <ros/ros.h>
#include "turtlesim/Pose.h"

// 接收到订阅的消息后，会进入消息回调函数
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "pose_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}

```

#### 2⃣️配置订阅者代码编译规则

找到**功能包**下的CMakeLists.txt

- 设置需要编译的代码和生成的可执行文件
- 设置链接库

```
 add_executable(pose_subscriber src/pose_subscriber.cpp) 
 target_link_libraries(pose_subscriber ${catkin_LIBRARIES})
```

#### 3⃣️编译并运行订阅者

```
$ cd ~/catkin_ws
$ catkin_make 编译工作空间
$ source devel/setup.bash 设置环境变量
运行发布者
$ roscore	
$ rosrun turtlesim turtlesim_node
$ rosrun learning_topic velocity_publisher
```

