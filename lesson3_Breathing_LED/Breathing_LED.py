#!/usr/bin/env python
# encoding: utf-8

import RPi.GPIO
import time

RPi.GPIO.setmode(RPi.GPIO.BCM)
RPi.GPIO.setup(18, RPi.GPIO.OUT)

# ����һ�� PWM ʵ������Ҫ������������һ����GPIO�˿ںţ�����������18��
# �ڶ�����Ƶ�ʣ�Hz����Ƶ��Խ��LED����ȥԽ������˸����Ӧ��CPUҪ���Խ�ߣ����ú��ʵ�ֵ�Ϳ���
pwm = RPi.GPIO.PWM(18, 70)

# ���� PWM��������ռ�ձȣ��������Ϊ������С������Χ��0.0 <= ռ�ձ� >= 100.0
pwm.start(0)

try:
	while True:
		# ������С����LED�ɰ�����
		for i in xrange(0, 101, 1):
			# ����ռ�ձȣ�������С����
			pwm.ChangeDutyCycle(i)
			time.sleep(.02)
			
		# ���õ����Ӵ�С��LED�����䰵
		for i in xrange(100, -1, -1):
			pwm.ChangeDutyCycle(i)
			time.sleep(.02)

# ���һ����һ��С���ɡ�������������ǿ��ֹͣ�᲻ͣ��ִ����ȥ��
# ��Ctrl+Cǿ���ն˳���Ļ���GPIO����û�л�������
# ����һ��try except ���Բ�׽��Ctrl+Cǿ���жϵĶ�����
# ��ͼǿ���ж�ʱ�����򲻻�����ֹͣ���ǻ���������������һЩ������������飬��������GPIO�ڡ�
except KeyboardInterrupt:
	pass

# ͣ�� PWM
pwm.stop()

# ����GPIO��
RPi.GPIO.cleanup()
