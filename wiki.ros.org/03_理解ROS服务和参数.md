## [03_理解ROS服务和参数](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingServicesParams)

### 1.ROS Services

​	服务（services）是节点之间通讯的另一种方式。服务允许节点发送**请求（request）** 并获得一个**响应（response）**

### 2.使用rosservice

​	`rosservice`可以很轻松的使用 ROS 客户端/服务器框架提供的服务。`rosservice`提供了很多可以在topic上使用的命令，如下所示：

​	使用方法：

```
rosservice list         输出可用服务的信息
rosservice call         调用带参数的服务
rosservice type         输出服务类型
rosservice find         依据类型寻找服务find services by service type
rosservice uri          输出服务的ROSRPC uri
```

#### 	2.1rossevice list 输出可用服务的信息

```
$ rosservice list
显示结果

/clear
/kill
/reset
/rosout/get_loggers
/rosout/set_logger_level
/spawn
/teleop_turtle/get_loggers
/teleop_turtle/set_logger_level
/turtle1/set_pen
/turtle1/teleport_absolute
/turtle1/teleport_relative
/turtlesim/get_loggers
/turtlesim/set_logger_level
```

​		`list` 命令显示turtlesim节点提供了9个服务：

```
重置（reset）
清除（clear）
再生（spawn）
终止（kill）
turtle1/set_pen
/turtle1/teleport_absolute
/turtle1/teleport_relative
turtlesim/get_loggers
turtlesim/set_logger_level

另外两个rosout节点提供的服务:

/rosout/get_loggers
/rosout/set_logger_level

```

#### 	2.2rosservice type 输出服务类型

​		使用方法

```
rosservice type [service]
```

​		查看clear服务的类型

```
$ rosservice type clear
显示
std_srvs/Empty
```

​		服务的类型为空（empty),这表明在调用这个服务是不需要参数（比如，请求不需要发送数据，响应也没有数据）。

#### 	2.3rosservice call 调用带参数的服务

​		使用方法：

```
rosservice call [service] [args]

$ rosservice call clear //因为clear的服务类型是空的所以不需要带参数。
服务清除了turtlesim_node的背景上的轨迹。
```

​		通过查看再生（spawn）服务的信息，我们来了解带参数的服务:

```
$ rosservice type spawn
turtlesim/Spawn

$ rosservice type spawn | rossrv show

float32 x     //以下是参数
float32 y
float32 theta
string name
---
string name
```

​		这个服务使得我们可以在给定的位置和角度生成一只新的乌龟。名字参数是可选的，这里我们不设具体的名字，让turtlesim自动创建一个。

```
$ rosservice call spawn 2 2 0.2 ""
```

### 3.使用rosparam

​	rosparam使得我们能够存储并操作ROS参数服务器（Parameter Server）上的数据。

​	参数服务器能够存储整型、浮点、布尔、字符串、字典和列表等数据类型。

​	rosparam使用YAML标记语言的语法。

​	一般而言，YAML的表述很自然：

- 1是整型
- 1.0是浮点型
- one是字符串
- true是布尔
- [1,2,3]是整型列表
- {a:b,c:d}是字典

rosparam有很多指令可以用来操作参数，如下所示:

```
rosparam set            设置参数
rosparam get            获取参数
rosparam load           从文件读取参数
rosparam dump           向文件中写入参数
rosparam delete         删除参数
rosparam list           列出参数名
```

#### 	3.1rosparam list 列出参数名

```
$ rosparam list

/background_b
/background_g
/background_r
/roslaunch/uris/aqy:51932
/run_id
```

#### 	3.2rosparam set and rosparam get  设置参数和获取参数

​		使用方法：

```
rosparam set [param_name]
rosparam get [param_name]

$ rosparam get /     显示参数服务器上的所有内容。
```

