## [05_使用rosed编辑ROS中的文件](http://wiki.ros.org/cn/ROS/Tutorials/UsingRosEd)

**Description:** 本教程将展示如何使用[rosed](http://wiki.ros.org/rosbash)来简化编辑过程。

### 1.使用rosed

- rosed是rosbash 的一部分。
- 利用它可以直接通过package名来获取到待编辑的文件而无需指定该文件的存储路径了。

使用方法：

```
$ rosed [package_name] [filename]
```

```
$ rosed roscpp Logger.msg
```

这个实例展示了如何编辑roscpp package里的Logger.msg文件。

如果该实例没有运行成功，那么很有可能是你没有安装`vim`编辑器。请参考[编辑器](http://wiki.ros.org/cn/ROS/Tutorials/UsingRosEd#Editor)部分进行设置。

如果文件名在package里不是唯一的，那么会呈现出一个列表，让你选择编辑哪一个文件。

### 2.使用Tab键补全文件名

使用方法：

```
$ rosed [package_name] <tab>
```

### 3.编辑器

- rosed默认的编辑器是vim。
- 如果想要将其他的编辑器设置成默认的，你需要修改你的 ~/.bashrc 文件，增加如下语句:

```
export EDITOR='emacs -nw'
```

 这将emacs设置成为默认编辑器。

- 注意: .bashrc文件的改变，只会在新的终端才有效。已经打开的终端不受环境变量的影响。

	打开一个新的终端，看看那是否定义了EDITOR:

	```
	$ echo $EDITOR
	显示
	emacs -nw  //成功设置rosed
	```

