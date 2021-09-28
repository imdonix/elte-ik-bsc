#!/usr/bin/python

import json
import sys

# suppose only one edge between 2 endpoint

def take(links, routes, requests, i, ri):
    for li in routes[i][2]:
        links[li]['capacity'] -= requests[ri]['demand']
    return (requests[ri]['end-time'], i, ri)

def free(links, routes, requests, lib):
    for li in routes[lib[1]][2]:
        links[li]['capacity'] += requests[lib[2]]['demand']

def findAvailable(links, routes, points, demand):
    for i in range(len(routes)):
        if(routes[i][0] in points and routes[i][1] in points):
            can = True
            for edge in routes[i][2]:
                can = can and links[edge]['capacity'] >= demand
            if can:
                return i
    return -1

def findEdge(links, a, b):
    for i in range(len(links)):
        if(a in links[i]['points'] and b in links[i]['points']):
            return i
    raise Exception('edge not found between {} {}' % (a,b))

def edgeRoute(links, circuits):
    res = list()
    for cir in circuits:
        edge = list()
        for i in range(len(cir)-1):
            edge.append(findEdge(links, cir[i], cir[i+1]))
        res.append((cir[0], cir[-1] ,edge))
    return res


def main(raw):
    links = raw['links']
    liberation = list()
    routes = edgeRoute(links, raw['possible-circuits'])
    duration = raw['simulation']['duration']
    requests = raw['simulation']['demands']
    event = 1


    for time in range(1, duration + 1):
        for ri in range(len(requests)):
            if(requests[ri]['start-time'] == time):
                i = findAvailable(links, routes, requests[ri]['end-points'], requests[ri]['demand'])
                if i >= 0:
                    liberation.append(take(links, routes, requests, i, ri))
                ep =requests[ri]['end-points']
                print('%d. igény foglalás: %s<->%s st:%d - %s' % (event, ep[0],ep[1],time,'sikeres' if i >= 0 else 'sikertelen'))
                event += 1
        for lib in liberation:
            if lib[0] == time:
                free(links, routes, requests, lib)
                ep =requests[lib[2]]['end-points']
                print('%d. igény felszabadítás: %s<->%s st:%d' % (event, ep[0],ep[1],time))
                event += 1

filename = sys.argv[1]
with open(filename) as file:
    raw = json.load(file)
    main(raw)