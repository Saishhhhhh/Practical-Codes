import ipaddress

try:
    # Create network object
    network = ipaddress.ip_network("192.168.1.0/24", strict=False)
    print(f"\nOriginal Network: {network}")
    print(f"Network Address : {network.network_address}")
    print(f"Broadcast Addr  : {network.broadcast_address}")
    print(f"Default Mask    : {network.netmask}")
    print(f"Prefix Length   : /{network.prefixlen}")
    print(f"Total Hosts     : {network.num_addresses - 2} usable\n")

    new_prefix = 26
    print(f"--- Subnetting {network} into /{new_prefix} subnets ---")
    subnets = list(network.subnets(new_prefix=new_prefix))
    for i, subnet in enumerate(subnets, start=1):
        print(f"Subnet {i}: {subnet}")
        print(f"   Network Addr : {subnet.network_address}")
        print(f"   Broadcast    : {subnet.broadcast_address}")
        print(f"   Mask         : {subnet.netmask}")
        print(f"   Usable Hosts : {subnet.num_addresses - 2}\n")

    # (Optional)
    # first_octet = int(str(network.network_address).split('.')[0])

    # if 0 <= first_octet <= 127:
    #     ip_class = 'Class A'
    #     default_mask = '255.0.0.0'
    # elif 128 <= first_octet <= 191:
    #     ip_class = 'Class B'
    #     default_mask = '255.255.0.0'
    # elif 192 <= first_octet <= 223:
    #     ip_class = 'Class C'
    #     default_mask = '255.255.255.0'
    # elif 224 <= first_octet <= 239:
    #     ip_class = 'Class D (Multicast)'
    #     default_mask = 'N/A'
    # else:
    #     ip_class = 'Class E (Experimental)'
    #     default_mask = 'N/A'

    
    # print("\n--- IP Class Information ---")
    # print(f"Class: {ip_class}")
    # print(f"Default Mask: {default_mask}")

except Exception as e:
    print(f"Error: {e}")
