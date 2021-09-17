from subprocess import Popen, PIPE
import os
import platform
import queue
import sys
from time import sleep

print("CPU:", os.cpu_count())
print("OS:",platform.system())

availableCore = os.cpu_count()
maxLevel = int(sys.argv[1])

cmd = ''
if platform.system() == "Windows":
	cmd = 'echo "Windows"'
elif platform.system() == "Linux":
	cmd = 'echo "Linux"'
else:
	print("ERROR",platform.system())
	sys.exit(1)

process = [None]*availableCore # None-nal feltott tomb
activeProcess = 0
levelQueue = queue.Queue()
levelQueue.put(0)

def addProcess(level):
	global activeProcess
	activeProcess += 1
	p = Popen(cmd, stdout= PIPE, stderr=PIPE, shell=True)
	for i in range(availableCore):
		if process[i] == None:
			process[i] = (level,p)
			break

def processRes(l,res):
	global activeProcess
	activeProcess -= 1
	if l < maxLevel:
		for i in range(l+1):
			levelQueue.put(l+1)
	print("  "*l,l,res.decode().strip())  #decode = bytes --> string
	
fut = 1
while (fut>0 or not levelQueue.empty()):
	fut = 0
	if not levelQueue.empty() and activeProcess < availableCore:
		level = levelQueue.get_nowait()
		addProcess(level)
	
	for i in range(len(process)):
		tupl = process[i]
		if not tupl is None:
			l,p = tupl
			if p.poll() != None:
				(res,err) = p.communicate()
				processRes(l,res)
				process[i] = None
			else:
				fut += 1
	sleep(0.1)

# addProcess(0)