# 05_SLAM创建地图

1. 打开一个终端，登录树莓派

	```
	ssh rikirobot@robot.local
	```

	输入

	```
	roslaunch rikirobot bringup.launch
	```

2. 再打开一个终端，启动键盘控制节点

	```
	rosrun teleop_twist_keyboard teleop_twist_keyboard.py
	```

3. 再打开一个终端（需登录树莓派），启动激光雷达

	```
	roslaunch rikirobot lidar_slam.launch
	```

	直到出现`odom received！`字样说明启动成功

4. 再打开一个终端，不用登录树莓派，启动rviz

	```
	rosrun rviz rviz
	```

5. 将rviz界面全屏，点击左上角“File-Open Config”按钮，在弹出的窗口中选择`~/catkin_ws/src/rikirobot_project/rikirobot/rviz/slam.rviz`文件，并打开。

6. 打开slam.rviz文件后，机器人开始创建地图。红色边缘部分是激光雷达当前扫描到的障碍物，黑色部分是已经确定的地图边缘，灰色块状部分则是有效的地图区域。

7. 保存与修正地图

	- 打开一个终端窗口，执行下述命令进入地图保存目录
		- cd catkin_ws/src/rikirobot_project/rikirobot/maps
	- 执行下述命令，运行保存地图脚本文件
		- ./map.sh
		- 可能需要添加权限：chmod +x map.sh
	- 查看地图文件
		- ll -h
		- 其中.pgm和.yaml均为保存后的地图文件，后续实验可直接使用该文件。