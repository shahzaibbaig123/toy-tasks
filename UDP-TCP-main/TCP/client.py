import socket
import time
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


initial_time = time.time() #Store the time when request is sent
s.connect((socket.gethostname(), 1234))

msg = s.recv(80)
ending_time = time.time() #Time when acknowledged the request
elapsed_time = str(ending_time - initial_time)
print(msg.decode("utf-8"))
print("Initiation Time: ", initial_time)
print("Ending Time: ", ending_time)
print("RTT: ", elapsed_time)

