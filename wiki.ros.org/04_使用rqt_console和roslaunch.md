## [04_使用rqt_console和roslaunch](http://wiki.ros.org/cn/ROS/Tutorials/UsingRqtconsoleRoslaunch)

### 1.使用rqt_console和rqt_logger_level

​	rqt_console属于ROS日志框架(logging framework)的一部分，用来显示节点的输出信息

​	rqt_logger_level允许我们修改节点运行时输出信息的日志等级（logger levels）

​	logger levels包括 DEBUG、WARN、INFO和ERROR

​	现在让我们来看一下turtlesim在rqt_console中的输出信息，同时在rqt_logger_level中修改日志等级。

​	在启动turtlesim之前先在另外两个新终端中运行rqt_console和rqt_logger_level：

```
$ rosrun rqt_console rqt_console
$ rosrun rqt_logger_level rqt_logger_level
```

​	现在让我们在一个新终端中启动turtlesim：

```
$ rosrun turtlesim turtlesim_node
```

​	我们刷新一下rqt_logger_level窗口并选择Warn将日志等级修改为WARN，

​	我们让turtle动起来并观察rqt_console中的输出

```
rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 0.0]'
```

### 2.日志等级说明

​	日志等级按以下优先顺序排列：

```
Fatal
Error
Warn
Info
Debug
```

- Fatal是最高优先级，Debug是最低优先级。
- 通过设置日志等级你可以获取该等级及其以上优先等级的所有日志消息。
- 比如，将日志等级设为Warn时，你会得到Warn、Error和Fatal这三个等级的所有日志消息。

### 3.roslaunch

​	roslaunch可以用来启动定义在launch文件中的多个节点。

​	用法：

```
$ roslaunch [package] [filename.launch]
```

