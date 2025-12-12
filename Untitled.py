#!/usr/bin/env python
# coding: utf-8

# In[1]:


pip install pyserial


# In[11]:


import serial.tools.list_ports

ports = serial.tools.list_ports.comports()

for port in ports:
    print(f"Device: {port.device} | Description: {port.description}")


# In[5]:


from roboclaw_3 import Roboclaw

rc = Roboclaw("/dev/ttyACM1", 115200)  # 또는 ttyUSB0
rc.Open()

address = 0x80
enc1, status1, valid1 = rc.ReadEncM1(address)
enc2, status2, valid2 = rc.ReadEncM2(address)

print("Encoder 1:", enc1, "Encoder 2:", enc2)


# In[17]:


success = rc.Open()
print("Connection opened:", success)


# In[7]:


import sys
sys.path.append("/home/xilinx/pynq/roboclaw")  # 실제 roboclaw_3.py가 있는 경로
from roboclaw_3 import Roboclaw


# In[39]:


rc = Roboclaw("/dev/ttyACM1", 38400)  # 또는 ttyUSB0
rc.Open()

rc.ForwardM1(address, 0)


# In[40]:


encoder_1_count = rc.ReadEncM1(0x80);
print(encoder_1_count)


# In[ ]:





# In[ ]:




