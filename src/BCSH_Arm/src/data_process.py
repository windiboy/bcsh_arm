#!/usr/bin/env python2.7
# coding:utf-8

import serial, rospy, time
import serial.tools.list_ports
from std_msgs.msg import String
import re
import math
from BCSH_Arm.msg import *


class DataProcess():

    #初始化
    def __init__(self,com,bps,timeout):
        self.port = com
        self.bps = bps
        self.timeout =timeout
        self.motro_id = '10'
        rospy.init_node("data_process",anonymous=True)
        self.msg_puber = rospy.Publisher("BCSH_Arm/" + self.motro_id + "/msg",ArmControlMsg,queue_size=10)
        self.ratio = 40
        self.current = 0.
        self.velocity = 0.
        self.position = 0.
        try:
            # 打开串口，并得到串口对象
            self.main_engine= serial.Serial(self.port,self.bps,timeout=self.timeout)
            # 判断是否打开成功
            if (self.main_engine.is_open):
                self.Ret = True
                print "serial connected!"
        except Exception as e:
            print("---异常---：", e)
        self.run()

    #打开串口
    def Open_Engine(self):
        self.main_engine.open()

    #关闭串口
    def Close_Engine(self):
        self.main_engine.close()
        print(self.main_engine.is_open)  # 检验串口是否打开

    #发数据
    def Send_data(self,data):
        self.main_engine.write(data.replace(" ", "").decode('hex'))

    def str_to_hex(self,s):
        #return ' '.join([hex(ord(c)).replace('0x', '') for c in s])
        return ' '.join(['{:0>2x}'.format(ord(c)) for c in s])

    def msg_process(self):
        # data = 'FE EF '+self.motro_id+' 04 02 AA 02 '+self.check(self.motro_id+' 04 02 AA 02 ')
        # self.Send_data(data)
        # temp = self.str_to_hex(self.main_engine.readline())
        # if temp[12:14] == 'e0':
        #     self.velocity = int(temp[18:20],16)+int(temp[21:23],16)*256
        #
        # data = 'FE EF '+self.motro_id+' 04 02 B0 02 '+self.check(self.motro_id+' 04 02 B0 02 ')
        # self.Send_data(data)
        # temp = self.str_to_hex(self.main_engine.readline())
        # if temp[12:14] == 'e0' and len(temp)==26:
        #     #print 'current'+temp
        #     self.current = int(temp[18:20],16)+int(temp[21:23],16)*256

        data = 'FE EF '+self.motro_id+' 04 02 AC 04 '+self.check(self.motro_id+' 04 02 AC 04 ')
        self.Send_data(data)
        #data FE EF 10 04 02 AC 04 39
        temp = self.str_to_hex(self.main_engine.readline())
        #temp = 'fe ef 10 07 e0 ac d9 78 71 00 9a'
        if temp[12:14] == 'e0' and len(temp)==32:
            self.position = (int(temp[18:20],16)+int(temp[21:23],16)*256+int(temp[24:26],16)*256*256+int(temp[27:29],16)*256*256*256)%26144

        #print 'motor {} velocity is {} rpm, current is {}, position is {}'.format(self.motro_id,self.velocity,self.current,self.position)

    def msg_publish(self):
        msg = ArmControlMsg()
        # msg.current = self.current
        # msg.velocity = self.velocity
        msg.position = self.position
        self.msg_puber.publish(msg)

    def check(self,data):
        #data为字符串
        return '{:0>2x}'.format((sum([int(i,16) for i in re.split(' ', data) if i != '' ])&0xff)^0xff)


    def run(self):
        while not rospy.is_shutdown():
            self.msg_process()
            self.msg_publish()
            time.sleep(0.01)
        self.Close_Engine()

if __name__ == '__main__':
    motor_driver = DataProcess("/dev/ttyUSB0",1000000,0.5)


