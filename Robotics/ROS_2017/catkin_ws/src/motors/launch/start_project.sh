#!/bin/bash
#commande : gnome-terminal --tab -e 'bash -c "COMMANDE"'

sourcer()
{
	cd
	source /opt/ros/indigo/setup.bash
	cd ~/catkin_ws
	catkin_make
	source devel/setup.bash
	echo "Sources OK"

}

#CONFIG PERIPHERIQUES 
echo "***Config des peripheriques***"
cd
cd /dev
sudo chmod 666 ttyACM0
sudo chmod 666 input/js1



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
sleep 5
cd
source /opt/ros/indigo/setup.bash
cd ~/catkin_ws
catkin_make
source devel/setup.bash
roslaunch motors controller_manager.launch
"'&
#START_TILT_CONTROLLER
gnome-terminal --tab -e 'bash -c "
sleep 7
cd
source /opt/ros/indigo/setup.bash
cd ~/catkin_ws
catkin_make
source devel/setup.bash
roslaunch motors start_tilt_controller.launch
read"'&
#JOY_NODE
gnome-terminal --tab -e 'bash -c "
sleep 2
cd
source /opt/ros/indigo/setup.bash
cd ~/catkin_ws
catkin_make
source devel/setup.bash
rosparam set joy_node/dev '/dev/input/js1'
rosrun joy joy_node
read
"'&
gnome-terminal --tab -e 'bash -c "
sleep 10
cd
source /opt/ros/indigo/setup.bash
cd ~/catkin_ws
catkin_make
source devel/setup.bash
rosrun motors deplacement_robot.py
read
"'




#& xterm -e "echo totu && read"
#xterm -e "sourcer; roscore" & xterm -e "echo totu && read"
#gnome-terminal --tab -e 'bash -c "sourcer; roscore"'& gnome-terminal --tab -e 'bash -c "echo toto"'

