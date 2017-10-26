#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Inverser les valeurs pour la roue droite

import rospy
import time
from sensor_msgs.msg import Joy
from std_msgs.msg import Float64

def callback(data):
	left_speed = rospy.Publisher('/left_controller/command', Float64, queue_size=10)
	right_speed = rospy.Publisher('/right_controller/command', Float64, queue_size=10)
	stop_speed = rospy.Publisher('/stop_move', Float64, queue_size=10)
	rate = rospy.Rate(10) # 10hz



	#DEPLACEMENT JOYSTICK
	if data.axes[3]==1.0:
		rospy.loginfo("Déplacement haut")
		left_speed.publish(512)
		right_speed.publish(-512)
		
    	elif data.axes[3]==-1.0:
    		rospy.loginfo("Déplacement bas")
		left_speed.publish(-512)
		right_speed.publish(512)


    	elif data.axes[0]>0.7:
    		rospy.loginfo("Déplacement gauche")
		left_speed.publish(0)
		right_speed.publish(-512)


    	elif data.axes[0]<-0.7:
    		rospy.loginfo("Déplacement droite")
		left_speed.publish(512)
		right_speed.publish(0)

	elif data.buttons[2] == 1:
		stop_speed.publish(123)
		

	#Pas de déplacement dans tous les autres cas
	else:
		left_speed.publish(0)
		right_speed.publish(0)

	rate.sleep()

def detection_touches():

	    rospy.init_node('detection_touches', anonymous=True)
	    rospy.Subscriber("joy", Joy, callback)
	    rospy.spin()

if __name__ == '__main__':
    detection_touches()

