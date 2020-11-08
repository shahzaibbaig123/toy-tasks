import socket
import sys
import time

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 1000)
message = 'Hey there, How r you sexi buddy.  THE MESSAGE, haha'

try:

    # Send data
    print ('sending',message )
    initial_time = time.time()  # Store the time when request is sent
    sent = sock.sendto(message.encode(), server_address)

    # Receive response
    print ('waiting to receive')
    data, server = sock.recvfrom(4096)
    ending_time = time.time()  # Time when acknowledged the request
    elapsed_time = str(ending_time - initial_time)

    print ('received',data)

finally:
    print ('closing socket')
    sock.close()


print("Initiation Time: ", initial_time)
print("Ending Time: ", ending_time)
print("RTT: ", elapsed_time)
