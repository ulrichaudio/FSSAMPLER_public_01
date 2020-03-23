from osc4py3.as_eventloop import *
from osc4py3 import oscbuildparse
import time
start=time.time()
# Start the system.
osc_startup()

# Make client channels to send packets.
osc_udp_client("127.0.0.1", 12000, "tester")
stop=time.time()
msg = oscbuildparse.OSCMessage("/test/me", ",sif", [(start-stop), 672, 
8.871])
osc_send(msg, "tester")
osc_process()
