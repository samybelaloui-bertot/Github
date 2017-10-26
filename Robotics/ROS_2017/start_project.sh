#!/bin/bash
#commande : gnome-terminal --tab -e 'bash -c "COMMANDE"'


#CONFIG PERIPHERIQUES 
echo "***Config des peripheriques***"
cd
cd /dev
sudo chmod 666 ttyACM0
sudo chmod 666 input/js1
sudo chmod 666 ttyUSB0
sudo chmod 666 ttyUSB1
sudo chmod 666 tty hidraw2
cd
sudo chmod +x catkin_ws/src/detection/scripts/detection.py





#ROSCORE
gnome-terminal --tab -e 'bash -c "
cd
source /opt/ros/indigo/setup.bash
cd ~/catkin_ws
catkin_make
source devel/setup.bash
roscore"'&
#CONTROLLER_MANAGER
gnome-terminal --tab -e 'bash -c "
sleep 8
cd ~/catkin_ws
source devel/setup.bash
roslaunch motors controller_manager.launch
"'&
#START_TILT_CONTROLLER
gnome-terminal --tab -e 'bash -c "
sleep 7
cd ~/catkin_ws
source devel/setup.bash
roslaunch motors start_tilt_controller.launch
read"'&
#JOY_NODE
gnome-terminal --tab -e 'bash -c "
sleep 8
cd ~/catkin_ws
source devel/setup.bash
rosparam set joy_node/dev '/dev/input/js1'
rosrun joy joy_node
read
"'&
#PROGRAMME FINAL
gnome-terminal --tab -e 'bash -c "
sleep 10
cd ~/catkin_ws
source devel/setup.bash
rosrun motors deplacement_robot.py
read
"'&
#AUTONOME
gnome-terminal --tab -e 'bash -c "
sleep 8
cd ~/catkin_ws
source devel/setup.bash
rosrun autonomous autonomy.py
read
"'&
#LIDAR
gnome-terminal --tab -e 'bash -c "
sleep 8
cd ~/catkin_ws
source devel/setup.bash
roslaunch rplidar_ros rplidar.launch
read
"'&
#DETECTION LIDAR
gnome-terminal --tab -e 'bash -c "
sleep 8
cd ~/catkin_ws
source devel/setup.bash
rosrun detection detection.py
read
"'&
#ARDUINO
gnome-terminal --tab -e 'bash -c "
cd ~/catkin_ws
source devel/setup.bash
cd
arduino
#"'&
#CONNEXION ROS-ARDUINO
gnome-terminal --tab -e 'bash -c "
sleep 35
cd ~/catkin_ws
source devel/setup.bash
rosrun rosserial_python serial_node.py /dev/ttyUSB0
#"'



#& xterm -e "echo totu && read"
#xterm -e "sourcer; roscore" & xterm -e "echo totu && read"
#gnome-terminal --tab -e 'bash -c "sourcer; roscore"'& gnome-terminal --tab -e 'bash -c "echo toto"'

