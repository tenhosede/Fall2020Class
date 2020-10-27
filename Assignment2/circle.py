 #!/usr/bin/python2
#
# Move the robot forwards and backwards
from romipi_astar.romipi_driver import AStar
import time

romi = AStar()

distance = 10.0
runtime = 15.0

romi.twist(2*3.14*distance/runtime,2*3.14/runtime)
time.sleep(runtime)


romi.twist(0.0,0.0)


print("all done.")
