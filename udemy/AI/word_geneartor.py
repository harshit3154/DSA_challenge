import random
import numpy as np
text="""
What is networking?
A computer network comprises two or more computers that are connected—either by cables (wired) or wifi (wireless)—with the purpose of transmitting, exchanging, or sharing data and resources.

You build a computer network by using hardware (for example, routers, switches, access points, and cables) and software (for example, operating systems or business applications).
Geographic location often defines a computer network. For example, a LAN (local area network) connects computers in a defined physical space, like an office building, whereas a WAN (wide area network) can connect computers across continents. The internet is the largest example of a WAN, connecting billions of computers worldwide.

You can further define a computer network by the protocols it uses to communicate, the physical arrangement of its components, how it controls traffic, and its purpose.

Computer networks enable communication for every business, entertainment, and research purpose. The internet, online search, email, audio and video sharing, online commerce, live-streaming, and social networks all exist because of computer networks.

Guide
Achieve workplace flexibility with DaaS
Read how desktop as a service (DaaS) enables enterprises to achieve the same level of performance and security as deploying the applications on premises.

Related content
Register for the guide on app modernization

Computer network types
As networking needs evolved, so did the computer network types that serve those needs. Here are the most common and widely used computer network types:

LAN (local area network): A LAN connects computers over a relatively short distance, allowing them to share data, files, and resources. For example, a LAN may connect all the computers in an office building, school, or hospital. Typically, LANs are privately owned and managed.
 

WLAN (wireless local area network): A WLAN is just like a LAN but connections between devices on the network are made wirelessly.
 

WAN (wide area network): As the name implies, a WAN connects computers over a wide area, such as from region to region or even continent to continent. The internet is the largest WAN, connecting billions of computers worldwide. You will typically see collective or distributed ownership models for WAN management.
 

MAN (metropolitan area network): MANs are typically larger than LANs but smaller than WANs. Cities and government entities typically own and manage MANs.
 

PAN (personal area network): A PAN serves one person. For example, if you have an iPhone and a Mac, it’s likely you’ve set up a PAN that shares and syncs content—text messages, emails, photos, and more—across both devices.
 

SAN (storage area network): A SAN is a specialized network that provides access to block-level storage—shared network or cloud storage. To the user, it looks, and works like a storage drive that’s physically attached to a computer. (For more information on how a SAN works with block storage, see Block Storage: A Complete Guide).
 

CAN (campus area network): A CAN is also known as a corporate area network. A CAN is larger than a LAN but smaller than a WAN. CANs serve sites such as colleges, universities, and business campuses.
 

VPN (virtual private network): A VPN is a secure, point-to-point connection between two network end points (see ‘nodes’ below). A VPN establishes an encrypted channel that keeps a user’s identity and access credentials, as well as any data transferred, inaccessible to hackers.

Important terms and concepts
The following are some common terms to know when discussing computer networking:

IP address: An IP address is a unique number assigned to every device connected to a network that uses the Internet Protocol for communication. Each IP address identifies the device’s host network and the location of the device on the host network. When one device sends data to another, the data includes a ‘header’ that includes the IP address of the sending device and the IP address of the destination device.
 

Nodes: A node is a connection point inside a network that can receive, send, create, or store data. Each node requires you to provide some form of identification to receive access, like an IP address. A few examples of nodes include computers, printers, modems, bridges, and switches. A node is essentially any network device that can recognize, process, and transmit information to any other network node.
 

Routers: A router is a physical or virtual device that sends information that is contained in data packets between networks. Routers analyze data within the packets to determine the best way for the information to reach its ultimate destination. Routers forward data packets until they reach their destination node.
 

Switches: A switch is a device that connects other devices and manages node-to-node communication within a network, ensuring that data packets reach their ultimate destination. While a router sends information between networks, a switch sends information between nodes in a single network. When discussing computer networks, ‘switching’ refers to how data is transferred between devices in a network. The three main types of switching are as follows:

Circuit switching, which establishes a dedicated communication path between nodes in a network. This dedicated path assures the full bandwidth is available during the transmission, meaning that no other traffic can travel along that path.
 

Packet switching involves breaking down data into independent components that are called packets, which because of their small size, make fewer demands on the network. The packets travel through the network to their end destination.
 

Message switching sends a message in its entirety from the source node, traveling from switch to switch until it reaches its destination node.
 

Ports: A port identifies a specific connection between network devices. Each port is identified by a number. If you think of an IP address as comparable to the address of a hotel, then ports are the suites or room numbers within that hotel. Computers use port numbers to determine which application, service, or process should receive specific messages.
 

Network cable types: The most common network cable types are Ethernet twisted pair, coaxial, and fiber optic. The choice of cable type depends on the size of the network, the arrangement of network elements, and the physical distance between devices.

Examples of computer networks
The wired or wireless connection of two or more computers for the purpose of sharing data and resources form a computer network. Today, nearly every digital device belongs to a computer network.

In an office setting, you and your colleagu""".lower()    

k=4
dic=dict()
for i in range(len(text)-4):
    x=text[i:i+k]
    y=text[i+k]

    if dic.get(x) is None:
        dic[x]={}
        dic[x][y]=1
    else:
        if dic[x].get(y) is None:
            dic[x][y]=1
        else:
            dic[x][y]+=1

for kx in dic.keys():
    s=sum(dic[kx].values())
    for ky in dic[kx].keys():
        dic[kx][ky]/=s


def predNextChar(sentence):
    state=sentence[-4:]
    if(dic.get(state) is None):
        return " "
    possible_key=list(dic[state].keys())
    possible_values=list(dic[state].values())
    return np.random.choice(possible_key,p=possible_values)

output=input("Enter your question :")  
for i in range(500):
    next_char=predNextChar(output)
    output+=next_char
print(output)