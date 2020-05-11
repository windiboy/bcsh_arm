#!/usr/bin/env python2.7
# coding:utf-8

import serial, rospy, time
import serial.tools.list_ports
from std_msgs.msg import String
import binascii
import struct
import re
import math


class Communication():

    #初始化
    def __init__(self,com,bps,timeout):
        self.port = com
        self.bps = bps
        self.timeout =timeout
        self.motro_id = '10'
        rospy.init_node("motor_driver",anonymous=True)
        self.command_sub = rospy.Subscriber('BCSH_Arm/state_change',String,self.command_callback)
        self.ratio = 40
        self.command = ''
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

    def command_callback(self,msg):
        self.command = msg.data

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

    def enable_motor(self):
        data = 'FE EF '+self.motro_id+' 04 03 62 01 '+self.check(self.motro_id+' 04 03 62 01 ')
        # print data
        self.Send_data(data)

    def disable_motor(self):
        data = 'FE EF '+self.motro_id+' 04 03 62 00 '+self.check(self.motro_id+' 04 03 62 00 ')
        # print data
        self.Send_data(data)

    def check(self,data):
        #data为字符串
        return '{:0>2x}'.format((sum([int(i,16) for i in re.split(' ', data) if i != '' ])&0xff)^0xff)

    def pos_control(self,target_pos):
        #target范围0～360度
        #控制范围为0-262144*减速比
        pos = '{:0>8x}'.format(int(target_pos/360.*262144*self.ratio))#转换成16进制角度
        pos = str(pos).decode('hex')[::-1].encode('hex_codec')#大小端转换
        data = 'FE EF '+self.motro_id+' 07 03 A6 '+pos[:2]+' '+pos[2:4]+' '+pos[4:6]+' '+pos[6:]+' '\
               +self.check(self.motro_id+' 07 03 A6 '+pos[:2]+' '+pos[2:4]+' '+pos[4:6]+' '+pos[6:])
        # print data
        self.Send_data(data)

    def vel_control(self,target_vel):
        #target单位rpm
        vel =  '{:0>4x}'.format(target_vel)#转换成16进制角度
        vel = str(vel).decode('hex')[::-1].encode('hex_codec')#大小端转换
        data = 'FE EF '+self.motro_id+' 05 03 A0 '+vel[:2]+' '+vel[2:]+' '+self.check(self.motro_id+' 05 03 A0 '+vel[:2]+' '+vel[2:])
        # print data
        self.Send_data(data)

    def setting(self,MAX_SPEED=1000,ACC=3000):
        #MAX_SPEED单位rpm ACC单位rpm/s
        max_speed =  '{:0>4x}'.format(MAX_SPEED)#转换成16进制角度
        max_speed = str(max_speed).decode('hex')[::-1].encode('hex_codec')#大小端转换
        max_speed = 'FE EF '+self.motro_id+' 05 03 A4 '+max_speed[:2]+' '++max_speed[2:]+' '+self.check(self.motro_id+' 05 03 A4 '+max_speed[:2]+' '++max_speed[2:])
        # print max_speed
        self.Send_data(max_speed)

        acc =  '{:0>4x}'.format(ACC)#转换成16进制角度
        acc = str(acc).decode('hex')[::-1].encode('hex_codec')#大小端转换
        acc = 'FE EF '+self.motro_id+' 05 03 A2 '+acc[:2]+' '++acc[2:]+' '+self.check(self.motro_id+' 05 03 A2 '+acc[:2]+' '++acc[2:])
        # print acc
        self.Send_data(acc)

    def run(self):
        t = 0
        while not rospy.is_shutdown():
            #print self.command
            #self.Recive_data(0)
            if self.command == 'POS':
                val=180*(math.sin(t/math.pi)+1)
                print val
                self.pos_control(val)
            if self.command == 'VEL':
                self.vel_control(100)
                self.command = ''
            if self.command == 'ENABLE':
                self.enable_motor()
                self.command = ''
            if self.command == 'DISABLE':
                self.disable_motor()
                self.command = ''
            time.sleep(0.01)
            t=t+0.05

if __name__ == '__main__':
    motor_driver = Communication("/dev/ttyUSB0",1000000,0.5)

