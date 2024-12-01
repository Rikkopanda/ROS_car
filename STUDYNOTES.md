
configureren netwerkadapters
vim /etc/netplan/50-cloud-init.yaml

veschil curl ifconfig.me & ifconfig -a of hostname -I
ifconfig is grabbing your local, NAT'd IP address. curl ifconfig.me is grabbing the public IP provided to you by your ISP.

Network address translation (NAT) is a method of mapping an IP address space into another by modifying network address information in the IP header of packets while they are in transit across a traffic routing device.

![image](https://github.com/user-attachments/assets/abeca84f-86e8-4bd1-aba0-fd034f4ec5ff)
![image](https://github.com/user-attachments/assets/b51d7003-d1e3-4b91-9ffe-ec8ad6d93f87)



wat is socket
https://www.ibm.com/docs/en/aix/7.2?topic=sockets-interface

