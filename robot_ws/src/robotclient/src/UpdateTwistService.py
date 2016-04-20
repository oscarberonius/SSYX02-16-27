#!/usr/bin/env python
PKG = 'robotclient'
import roslib; roslib.load_manifest(PKG)

from robotclient.srv import *

import rospy
from rospy_tutorials.msg import Floats
from rospy.numpy_msg import numpy_msg
from std_msgs.msg import String
from geometry_msgs.msg import Twist
import numpy as np

def handle_update_twist(data):
    ack = 0
    x = data.data[0]
    z = data.data[1]

    twist = Twist()

    twist.linear.x = x
    twist.angular.z = z

    pub = rospy.Publisher("RosAria/cmd_vel", Twist, queue_size=10)
    pub.publish(twist)
    print rospy.get_name(), "Twist Updated"
    ack = 1
    return UpdateTwistResponse(ack)

def update_twist_server():
    rospy.init_node('update_twist_server_1')
    s = rospy.Service('updateTwist1', UpdateTwist, handle_update_twist)
    print rospy.get_name(), "Ready to update twist"
    rospy.spin()


if __name__ == "__main__":
    update_twist_server()