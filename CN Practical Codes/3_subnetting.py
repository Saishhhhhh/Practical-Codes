import ipaddress
def demonstrate_subnetting(network_cidr, new_prefix):
    try:
        # Create network object
        network = ipaddress.ip_network(network_cidr, strict=False)
        print(f"\nOriginal Network: {network}")
        print(f"Network Address : {network.network_address}")
        print(f"Broadcast Addr  : {network.broadcast_address}")
        print(f"Default Mask    : {network.netmask}")
        print(f"Prefix Length   : /{network.prefixlen}")
        print(f"Total Hosts     : {network.num_addresses - 2} usable\n")

        print(f"--- Subnetting {network} into /{new_prefix} subnets ---")
        subnets = list(network.subnets(new_prefix=new_prefix))
        for i, subnet in enumerate(subnets, start=1):
            print(f"Subnet {i}: {subnet}")
            print(f"   Network Addr : {subnet.network_address}")
            print(f"   Broadcast    : {subnet.broadcast_address}")
            print(f"   Mask         : {subnet.netmask}")
            print(f"   Usable Hosts : {subnet.num_addresses - 2}\n")

    except Exception as e:
        print(f"Error: {e}")
if __name__ == "__main__":
    demonstrate_subnetting("192.168.1.0/24", 26)
