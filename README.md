# Description
The project uses a binary trie data structure to efficiently perform 
the longest prefix matching (LPM) for IP routing ([see more here](https://en.wikipedia.org/wiki/Longest_prefix_match#:~:text=Longest%20prefix%20match%20(also%20called,than%20one%20forwarding%20table%20entry))).
Note program uses text files to search for the simulation of the LPM problem route. Practically, it is used by routers to determine the most specific route 
for a packet in a routing table. 


# Run locally
To run you need to have a file containing all network and a port mapped to that and a file containing ip addresses. Once
you have that, compile the C++ file. For example, the command
    
    
    g++ -O3 -std=c++17 -o main main.cpp

then run by 

    ./main [routeFilePath] [lookupFilePath]
