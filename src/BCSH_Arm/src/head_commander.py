#!/usr/bin/env python2.7
# coding:utf-8
import rospy
from std_msgs.msg import String
import time

command_dict = {'v':'VEL',
                'p':'POS',
                'e':'ENABLE',
                'd':'DISABLE',
                'm':'MESSAGE'}
rospy.init_node('head_commander',anonymous=True)
command_pubber = rospy.Publisher('BCSH_Arm/state_change',String,queue_size=10)

while not rospy.is_shutdown():
    rospy.logwarn("********* Please Input Command to Change Working State **********")
    rospy.logwarn("'v' to VEL")
    rospy.logwarn("'p' to POS")
    rospy.logwarn("'q' to QUIT")
    command = raw_input(":")
    if command in command_dict:
        command_pubber.publish(String(command_dict[command]))
    elif command == 'q':
        exit()
    else:
        rospy.logwarn('illegal input!')

