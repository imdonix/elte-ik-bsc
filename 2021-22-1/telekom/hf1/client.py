#!/usr/bin/python
 
from subprocess import Popen, PIPE
import time
import sys
import os
import platform
import queue
import json
 
 
def toJSON(res, trace):
 
    traces = list()
    for x in res:
        traces.append({ 'target' : x[0], 'output' : x[1].decode("utf-8") })
 
    if trace:
        return {
            'date' : round(time.time()),
            'system' : platform.system(),
            'traces' : traces
        }
    else:
        return {
        'date' : round(time.time()),
        'system' : platform.system(),
        'pings' : traces
        }
 
 
def traceroute(host, trace):
    cmd = 'traceroute' if trace else 'ping'
    arg = '-m 30' if trace else '-c 10'
    return Popen([cmd, host, arg] , stdout= PIPE, stderr=PIPE)
 
def main(hosts, trace):
    threads = os.cpu_count()
 
    res = list()
    run = list() # ps, done
    todo = queue.Queue() 
    for host in hosts:
        splitted = host.split(',')
        todo.put(splitted[1].rstrip('\n'))
 
    done = True
    running = 0
    while not todo.empty() or not done:
        if not todo.empty() and running < threads:
            cur = todo.get()
            print('[%s] %s started' % (trace, cur))
            run.append((cur ,traceroute(cur, trace), [False]))
 
        #print(running)
        done = True
        running = 0
        for ps in run:
            if not ps[2][0]:
                running += 1
                done = False
                if ps[1].poll() != None:
                    (r,e) = ps[1].communicate()
                    res.append((ps[0] ,r))
                    ps[2][0] = True
        time.sleep(0.1)
 
    return res      
 
 
n = 10
print("CPU:", os.cpu_count())
print("Platform:", platform.system())
print("N:", n)
filename = sys.argv[1]
with open(filename) as file:
    lines = file.readlines()
    hosts = lines[0:n] + lines[-n:]
    with open('ping.json', "w") as trace:
        json.dump(toJSON(main(hosts, False), False), trace)
    with open('traceroute.json', "w") as trace:
        json.dump(toJSON(main(hosts, True), True), trace)