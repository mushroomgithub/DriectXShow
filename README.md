#DriectXShow

>本程序在VS2010 PlatForm采用Micosoft 的DriectXShow9.0b SDK编写的一套实时视频捕捉，采集功能，
并且还提供了视频和单帧图像参数设置界面，采集的视频流和单帧图像都写在文件中，之后使用OpenCV进行音视频的处理，
当然这是我后期要做的事情，前面部分已经完成，前半部分开发使用了因为很多东西要查，
需要学习DXShow如何设计filter graph manger 和filter graph 的创建以及pin 的连接，最后renderstream,产生视频流，
之后，在视频流上捕捉单帧图像数据，加入图像头，写入文件进行保存，
为后期我使用opencv进行处理，然后讲程序移植到linux Platform(Ubuntu LTS 14.04)下重新测试,opencv音视频的处理.

##环境配置:

+  1.安装DriectXShow9.0b,我安装在了C盘根目录下.
+  2.打开VS2010项目,在项目属性中设置项目需要使用的项目需要包含的包含目录和库目录.
