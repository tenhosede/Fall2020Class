#!/usr/bin/python2
#
# Move the robot forwards and backwards
from romipi_astar.romipi_driver import AStar
import time

romi = AStar()

distance = 15
sides = 4
for j in range(sides):
    for i in range(distance):
        romi.twist(distance, 0.0)
        time.sleep(1.0)
        romi.twist(0.0, 3.14/2);
        time.sleep(1.0)


romi.twist(0.0,0.0)


print("all done.")
