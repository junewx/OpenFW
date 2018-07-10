#include <stdio.h>

main()
{
        system("rmmod -a ip_tables > /dev/null 2>&1");
        system("rmmod iptable_filter > /dev/null 2>&1");
        system("rmmod iptable_nat > /dev/null 2>&1");
        system("rmmod nf_conntrack > /dev/null 2>&1");
        system("rmmod nf_conntrack_ipv4 > /dev/null 2>&1");
        system("rmmod ip_tables > /dev/null 2>&1");
        system("modprobe ip_tables");
	system("echo 1 > /proc/sys/net/ipv4/ip_forward");
        system("iptables -F INPUT");
        system("iptables -F OUTPUT");
        system("iptables -F FORWARD");
        system("iptables -F POSTROUTING -t nat");
        system("iptables -F PREROUTING -t nat");

	system("iptables -A FORWARD -s 10.0.0.0/8 -j ACCEPT");
	system("iptables -A FORWARD -s 172.18.0.0/16 -j ACCEPT");
    	system("iptables -A FORWARD -i enp3s0 -m state --state ESTABLISHED,RELATED -j ACCEPT");
    	system("iptables -A FORWARD -i tun0 -m state --state ESTABLISHED,RELATED -j ACCEPT");
//    	system("iptables -t nat -A POSTROUTING -o tun0 -s 10.0.0.0/8 -j MASQUERADE");
//    	system("iptables -t nat -A POSTROUTING -o enp3s0 -s 172.18.0.0/16 -j MASQUERADE");
//    	system("iptables -t nat -A POSTROUTING -o enp3s0 -s 192.168.0.0/16 -j MASQUERADE");

        system("iptables -A INPUT -p tcp -m state --state NEW,ESTABLISHED -j ACCEPT");
        system("iptables -A OUTPUT -p tcp -m state --state ESTABLISHED -j ACCEPT");
        system("iptables -A INPUT -p udp -m state --state NEW,ESTABLISHED -j ACCEPT");
        system("iptables -A OUTPUT -p udp -m state --state ESTABLISHED -j ACCEPT");
	

        printf("#############################################################################\n");
        printf("#                                                                           #\n");
        printf("#           The Firewall is running...                                      #\n");
        printf("#                                                                           #\n");
        printf("#############################################################################\n");
}

