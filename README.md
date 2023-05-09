# ROS package for official YOLOv7

![YOLOv7 Berkeley DeepDrive](berkeley_example.png)

This repo contains a ROS noetic package for the official YOLOv7. It wraps the 
[official implementation](https://github.com/WongKinYiu/yolov7) into a ROS node (so most credit 
goes to the YOLOv7 creators).

## Installation

```bash
sudo apt install ros-noetic-vision-msgs ros-noetic-geometry-msgs
pip install typing cast_control
mkdir ~/yoloros_ws/src -p
cd ~/yoloros_ws/src
git clone https://github.com/jebiio/yolov7-ros.git
cd ~/yoloros_ws/src/yolov7-ros
pip install -r requirements.txt
cd ~/yoloros_ws
catkin build
```

## Run
* [master branch](https://github.com/jebiio/yolov7-ros) 참조

```bash
source ~/yoloros_ws/devel/setup.bash
# yolov7.launch 파라미터 수정 후,
roslaunch yolov7_ros yolov7.launch
```
* output topic name
  * yolov7/<out_topic> : vision/msgs/Detection2DArray
  * yolov7/<out_topic>/visualization : sensor_msgs/Image

## rouble shooting
* 빌드 실패 시, msg 폴더 만들기
* 원본이랑 똑같은 사진만 나올 때, detect.py 35line half = False로 수정
