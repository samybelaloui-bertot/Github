#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Inverser les valeurs pour la roue droite

import rospy
import time
from sensor_msgs.msg import Joy
from std_msgs.msg import Float64

global stop
stop = False

def callback_auto(data):
	global stop
	left_speed = rospy.Publisher('/left_controller/command', Float64, queue_size=10)
	right_speed = rospy.Publisher('/right_controller/command', Float64, queue_size=10)
	askScan = rospy.Publisher('/scanOn', Float64, queue_size = 10)
	rate = rospy.Rate(5) # 5hz

	
	#COMPORTEMENT AUTONOME
	if data.buttons[1] == 1:
		#timeStart = time.time()
		while stop == False:
			rate.sleep()
			#Avance
			left_speed.publish(512)
			right_speed.publish(-512)
			rospy.loginfo("[Autonome] AVANCE")
			if stop == True:
				break
			rate.sleep()
			time.sleep(3)

			#Gauche
			left_speed.publish(-512)
			right_speed.publish(-512)
			rospy.loginfo("[Autonome] GAUCHE")
			if stop == True:
				break
			rate.sleep()
			time.sleep(1.8)
			
			#Scan
			left_speed.publish(0)
			right_speed.publish(0)
			rospy.loginfo("[Autonome] SCAN")
			if stop == True:
				break
			askScan.publish(123)
			rate.sleep()
			time.sleep(8)

		stop = False
		left_speed.publish(0)
		right_speed.publish(0)
		rospy.loginfo("[Autonome] ARRET D'URGENCE")	

def callback_stop(data):
	global stop

	stop = True


def autonomy():

	    rospy.init_node('autonomy', anonymous=True)
	    rospy.Subscriber("joy", Joy, callback_auto)
	    rospy.Subscriber("stop_move", Float64, callback_stop)
	    rospy.spin()

if __name__ == '__main__':
    autonomy()

