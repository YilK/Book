# 04_校正IMU、角速度与线速度

**校正IMU**

1. 打开终端登录树莓派

2. 在此终端下输入

	```
	roslaunch rikirobot bringup.launch
	```

3. 查看值

	```
	rostopic echo /imu/data
	```

	找到`angular_velocity`的z值

	调整速度，登录树莓派，输入：

	```
	sudo nano ~/catkin_ws/src/rikirobot_project/rikirobot/launch/bringup.launch
	```

	找到`imu/gyroscope_bias`中的z值并修改（这个小车中的z值应该修改为：0.016997比较好）

	如何修改：ctrl+o 回车修改，ctrl+x->y->回车保存退出。

**校正角速度**

1. 登录树莓派，输入

	```
	roslaunch rikirobot bringup.launch
	```

	新建一个终端（需登录树莓派），输入

	```
	rosrun rikirobot_nav calibrate_angular.py
	```

	等待`[INFO]`提示出现

2. 新建一个终端（不用登录树莓派），输入

	```
	rosrun rqt_reconfigure rqt_reconfigure
	```

	等待界面的出现。界面出现之后，点击左侧`calibrate_angular`条目。之后进行如下操作：

	a）将`start_test`打勾，观察小车是否能原地旋转360度。

	b）如果不能，则调整`odom_angular_scake_correction`的值。

	c）重复上述步骤，直到小车能原地旋转360度。

3. 校正角速度

	登录树莓派

	```
	sudo nano ~/catkin_ws/src/rikirobot_project/rikirobot/launch/bringup.launch
	```

	找到 `angular_scale` 修改其value为刚刚调整的值。

**校正线速度**

1. 登录树莓派，输入

	```
	roslaunch rikirobot bringup.launch
	```

	新建一个终端（需登录树莓派），输入

	```
	rosrun rikirobot_nav calibrate_angular.py
	```

	等待`[INFO]`提示出现

2. 新建一个终端（不用登录树莓派），输入

	```
	rosrun rqt_reconfigure rqt_reconfigure
	```

	等待界面的出现。界面出现之后，点击左侧`calibrate_liner`条目。之后进行如下操作：

	a）将`start_test`打勾，观察小车是否能够直线的走1m的距离。

	b）如果不能，则调整`odom_liner_scake_correction`的值。

	c）重复上述步骤，直到小车能原地走1m的距离。

3. 校正线速度

	登录树莓派

	```
	sudo nano ~/catkin_ws/src/rikirobot_project/rikirobot/launch/bringup.launch
	```

	找到 `linear_scale` 修改其value为刚刚调整的值。

