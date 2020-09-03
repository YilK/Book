### P19 launch启动文件的使用方法

#### 1⃣️launch文件：通过XML文件实现多节点的配置和启动（可自动启动ROS Master）

#### 2⃣️launch文件语法

**\<launch\>** :launch文件中的根元素采用\<launch\>定义

\<node\> :

启动节点

```xml
<node pkg="package-name" type="executable-name" name="node- name" />
```

- pkg:节点所在的功能包的名称
- type:节点的可执行文件
- name:节点运行时的名称
- out、respawn、required、ns、args

#### 3⃣️launch文件语法

**参数设置**

\<param\>/\<rosparam\>:

设置ros系统中的参数，存储在参数服务器中。

```xml
<param name="output_frame" value="odom"/>
```

- name：参数命
- value：参数值

加载参数文件中的多个参数：

```xml
<rosparam file="params.yaml" command="load" ns=“params" />x
```

\<arg\>:

launch文件内部的局部变量，仅限于launch文件使用

```xml
<arg name="arg-name" default="arg-value" />
```

- name：参数命	
- value：参数值

调用:

```xml
<param name="foo" value="$(arg arg-name)" />
<node name="node" pkg="package" type="type " args="$(arg arg-name)" />
```

**重映射**

\<remap\>

重映射ROS计算图资源的命名。

```xml
<remap from="/turtlebot/cmd_vel" to="/cmd_vel"/>
```

- from：原命名
- to：映射之后的命名

**嵌套**

\<include\>

包含其他launch文件，类似C语言中的头文件包含。

```xml
<include file="$(dirname)/other.launch" />
```

 file:包含的其他launch文件路径

