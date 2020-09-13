## [01_理解ROS节点](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingNodes)

### 1.节点

​	[Nodes](http://wiki.ros.org/Nodes):节点,一个节点即为一个可执行文件，它可以通过ROS与其它节点进行通信。

​	一个节点其实只不过是ROS程序包中的一个可执行文件。ROS节点可以使用ROS客户库与其他节点通信。节点可以发布或接收一个话题。节点也可以提供或使用某种服务。

​	**例子理解：**例如，咱们有一个机器人，和一个遥控器，那么这个机器人和遥控器开始工作后，就是两个节点。遥控器起到了下达指 令的作用；机器人负责监听遥控器下达的指令，完成相应动作。从这里我们可以看出，节点是一个能执行特定工作任 务的工作单元，并且能够相互通信，从而实现一个机器人系统整体的功能。在这里我们把遥控器和机器人简单定义为两个节点，实际上在机器人中根据控制器、传感器、执行机构等不同组成模块，还可以将其进一步细分为更多的节点，这个是根据用户编写的程序来定义的。

### 2.roscore

​	`roscore` 是你在运行所有ROS程序前首先要运行的命令。

### 3.rosnode

​	`rosnode`显示当前运行的ROS节点信息。

​	`rosnode list`指令列出当前活跃的节点。

​	`rosnode info`命令返回的是关于一个特定节点的信息。

​		如`rosnode info /rosout`返回有关于rosout的信息。

### 4.rosrun

​	`rosrun`允许用户使用包名直接运行一个包内的节点（不需要知道包的路径）。

```
$ rosrun [package_name] [node_name]

$ rosrun turtlesim turtlesim_node

$ rosrun turtlesim turtlesim_node __name:=my_turtle //改变节点名称
```

