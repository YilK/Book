### P13 客户端Client的编程实现

**服务模型（客户端/服务器）**

#### 1⃣️创建功能包

```t
$ cd ~/catkin_ws/src
$ catkin_create_pkg learning_service roscpp rospy std_msgs geometry_msgs turtlesim
```

#### 2⃣️创建客户端代码

​	实现一个客户端

- 初始化ROS节点；
- 创建一个Client实例；
- 发布服务请求数据；
- 等待Server处理之后的应答结果。

```c++
/**
 * 该例程将请求/spawn服务，服务数据类型turtlesim::Spawn
 */

#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv)
{
    // 初始化ROS节点
	ros::init(argc, argv, "turtle_spawn");

    // 创建节点句柄
	ros::NodeHandle node;

    // 发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service
	ros::service::waitForService("/spawn");
	ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

    // 初始化turtlesim::Spawn的请求数据
	turtlesim::Spawn srv;
	srv.request.x = 2.0;
	srv.request.y = 2.0;
	srv.request.name = "turtle2";

    // 请求服务调用
	ROS_INFO("Call service to spwan turtle[x:%0.6f, y:%0.6f, name:%s]", 
			 srv.request.x, srv.request.y, srv.request.name.c_str());

	add_turtle.call(srv);

	// 显示服务调用结果
	ROS_INFO("Spwan turtle successfully [name:%s]", srv.response.name.c_str());

	return 0;
};

```

#### 3⃣️配置客户端代码编译规则

- 设置需要编译的代码和生成的可执行文件
- 设置链接库

```
add_executable(turtle_spawn src/turtle_spawn.cpp) target_link_libraries(turtle_spawn ${catkin_LIBRARIES})
```

#### 4⃣️编译并运行客户端

```
$ cd ~/catkin_ws
$ catkin_make
$ source devel/setup.bash
$ roscore
$ rosrun turtlesim turtlesim_node
$ rosrun learning_service turtle_spawn
```

