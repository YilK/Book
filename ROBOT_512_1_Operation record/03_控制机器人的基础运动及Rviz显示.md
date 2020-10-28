# 03_控制机器人的基础运动及Rviz显示

**机器人的基础运动**

1. 打开虚拟机，新建一个终端，远程登录树莓派

	```
	ssh rikirobot@robot.local
	```

2. 登录之后，在此终端下输入

	```
	roslaunch rikirobot bringup.launch
	```

3. 新建一个终端（无需登录树莓派），输入

	```
	rosrun teleop_twist_keyboard teleop_twist_keyboard.py
	```

	此命令运行成功之后，便可使用键盘来控制小车的运动。

**Rviz显示**

1. 重复上述机器人基础运动的过程

2. 打开Rviz(不登录树莓派)

	```
	rosrun rviz rviz
	```

	全屏后点击`File`-`Open Config` 

	打开`/home/xxx/catkin_ws/rikirobot_project/rikirobot/rviz/odometry.rviz`

3. 键盘控制

	选中键盘控制的终端，让小车移动，观察Rviz中图形的变化