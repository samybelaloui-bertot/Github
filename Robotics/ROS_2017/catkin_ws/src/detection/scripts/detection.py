#!/usr/bin/env python

import rospy
import math
import time
from sensor_msgs.msg import LaserScan
from sensor_msgs.msg import Joy
from std_msgs.msg import String
from std_msgs.msg import Float64

global scanData
scanData = LaserScan()

global scanOn
scanOn = False

def scanEnv():
	rospy.loginfo("button OK")
	global scanData
	
	#Get actual scan values => store as reference	
	originalScanData = scanData
		
	timeStart = time.time()

	#init publisher
	rate = rospy.Rate(10)
	pub = rospy.Publisher('scanInfo', String, queue_size=1)
	pub.publish("--- Scan starting ---")

	while time.time() - timeStart < 5:
		#rate config
		rate = rospy.Rate(5) 
		rate.sleep()
		rate = rospy.Rate(10)

		#Get (new) current ScanData for each loop
		currentScanData = scanData

		rospy.loginfo("time: %.3f", time.time() - timeStart)

		#if no change
		if currentScanData.ranges == originalScanData.ranges:
			rospy.loginfo("identique")
		else:
			rospy.loginfo("different")

			index = 0
			for distance in currentScanData.ranges:
				#max distance checked (m)
				if distance < 1:
					originalDistance = originalScanData.ranges[index]				
					delta = 0.05
					delta2 = 1
					#check current distance with original ones (more delta error)
					#if current distance is really far to the new one:
					if ((distance > originalDistance-delta2 and distance < originalDistance-delta) or (distance > originalDistance+delta and distance < originalDistance+delta2)):
						degree = (currentScanData.angle_min + currentScanData.angle_increment * index)*180 / math.pi
						infoStr = "Detected: " + str(round(degree,1)) + " degree ; " + str(round(distance,2)) + " m" 
						rospy.loginfo(infoStr)

						#Publications	
						pub.publish(infoStr)
				#increment index
				index = index + 1
	pub.publish("--- Scan terminating ---")

def callback_joy(data):
	if data.buttons[0] == 1:
		scanEnv()

def callback_laser(laserdata):
	global scanData	
	scanData = laserdata
	rospy.loginfo("laser OK")

def callback_scan(scandata):
	scanEnv()
    
def detection():
	# Node init
	rospy.loginfo("Initiation detection node")
	rospy.init_node('detection', anonymous=True)

	#Subscriptions
	rospy.Subscriber('joy', Joy, callback_joy)
	rospy.Subscriber('scanOn', Float64, callback_scan)
	rospy.Subscriber('scan', LaserScan, callback_laser)

	# spin() simply keeps python from exiting until this node is stopped
	rospy.spin()

if __name__ == '__main__':
	detection()
