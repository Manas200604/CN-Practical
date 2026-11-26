# Testing Report: Compilation & Functional Test Verification

**Date of Execution**: 2026-11-26  
**Compiler Used**: GCC 9.2.0 (tdm64-1, MinGW / Windows 64-bit)  
**Host Environment**: Microsoft Windows 11 / PowerShell  
**Target Code Directory**: `Computer-Networks-Practicals/03_Best_Optimized_Codes/`

---

## 1. Compilation Verification

All 14 optimized C programs were compiled using standard GCC flags.

| Program File | Target Executable | Compilation Flags | Compilation Result |
|:---|:---|:---|:---:|
| `01_even_parity.c` | `01_even_parity.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `02_hamming_code.c` | `02_hamming_code.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `03_crc.c` | `03_crc.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `04_stop_and_wait.c` | `04_stop_and_wait.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `05_go_back_n.c` | `05_go_back_n.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `06_selective_repeat.c` | `06_selective_repeat.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `07_distance_vector_matrix.c` | `07_distance_vector_matrix.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `08_distance_vector_next_hop.c` | `08_distance_vector_next_hop.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `09_dijkstra.c` | `09_dijkstra.exe` | `-Wall -O2` | **PASS (0 errors, 0 warnings)** |
| `10_ip_subnetting.c` | `10_ip_subnetting.exe` | `-Wall -O2` (with `<math.h>`) | **PASS (0 errors, 0 warnings)** |
| `11_tcp_server.c` | `11_tcp_server.exe` | `-lws2_32` | **PASS (0 errors, 0 warnings)** |
| `12_tcp_client.c` | `12_tcp_client.exe` | `-lws2_32` | **PASS (0 errors, 0 warnings)** |
| `13_udp_server.c` | `13_udp_server.exe` | `-lws2_32` | **PASS (0 errors, 0 warnings)** |
| `14_udp_client.c` | `14_udp_client.exe` | `-lws2_32` | **PASS (0 errors, 0 warnings)** |

---

## 2. Functional Test Cases & Results

### Practical 1: Even Parity Check (`01_even_parity.c`)
- **Test Case 1A (Valid Frame)**:
  - Input: Data `1011001`, Received `10110010`
  - Output: Total 1s received: 4 -> `Result: NO ERROR DETECTED (Parity verified successfully)`
  - Status: **PASS**
- **Test Case 1B (Corrupted Frame)**:
  - Input: Data `1011001`, Received `10110011`
  - Output: Total 1s received: 5 -> `Result: ERROR DETECTED! (Odd count of 1s indicates transmission error)`
  - Status: **PASS**

### Practical 2: Hamming Code (7,4) (`02_hamming_code.c`)
- **Test Case 2A (No Error)**:
  - Input: Data `1 0 1 1`, Received `0 1 1 0 0 1 1`
  - Output: `Syndrome (P4 P2 P1): 0 0 0 -> Error Position: 0` -> `Result: NO ERROR DETECTED`
  - Status: **PASS**
- **Test Case 2B (Single-Bit Error Correction)**:
  - Input: Data `1 0 1 1`, Received `0 1 1 0 1 1 1` (Bit 5 corrupted from 0 to 1)
  - Output: `Syndrome (P4 P2 P1): 1 0 1 -> Error Position: 5`  
    `Automatically Corrected Code: 0110011`  
    `Recovered Data Bits (D1 D2 D3 D4): 1 0 1 1`
  - Status: **PASS**

### Practical 3: Cyclic Redundancy Check (`03_crc.c`)
- **Test Case 3A (Valid Frame)**:
  - Input: Data `110101`, Generator `1011`, Received Frame `110101111`
  - Output: Remainder `000` -> `Result: FRAME IS VALID (Remainder is all zeros, no error)`
  - Status: **PASS**
- **Test Case 3B (Corrupted Frame)**:
  - Input: Data `110101`, Generator `1011`, Received Frame `110101001`
  - Output: Non-zero remainder -> `Result: ERROR DETECTED! (Remainder is non-zero)`
  - Status: **PASS**

### Practical 4: Stop-and-Wait ARQ (`04_stop_and_wait.c`)
- **Test Case**:
  - Input: 3 frames, lost frame = 2
  - Output: Frame 1 sent & ACKed; Frame 2 lost, timeout triggered, Frame 2 retransmitted & ACKed; Frame 3 sent & ACKed.
  - Status: **PASS**

### Practical 5: Go-Back-N ARQ (`05_go_back_n.c`)
- **Test Case**:
  - Input: 5 frames, window size = 3, lost frame = 2
  - Output: Frame 1 ACKed; Frame 2 lost; Sender goes back and retransmits frames 2 and 3; Window slides to [4 .. 5]; Frames 4 and 5 sent & ACKed.
  - Status: **PASS**

### Practical 6: Selective Repeat ARQ (`06_selective_repeat.c`)
- **Test Case**:
  - Input: 5 frames, window size = 3, lost frame = 2
  - Output: Frames 1 and 3 ACKed; Frame 2 lost; Sender retransmits **ONLY Frame 2**; Frames 4 and 5 sent & ACKed.
  - Status: **PASS**

### Practical 7: Distance Vector Matrix (`07_distance_vector_matrix.c`)
- **Test Case**:
  - Input: 3 routers; Link cost matrix:
    ```
    0   2   999
    2   0   3
    999 3   0
    ```
  - Output:
    ```
    R1:   0   2   5
    R2:   2   0   3
    R3:   5   3   0
    ```
  - Status: **PASS**

### Practical 8: Distance Vector Next Hop (`08_distance_vector_next_hop.c`)
- **Test Case**:
  - Input: Same 3-router topology.
  - Output:
    - Router 1 -> Dest 3: Cost 5, Next Hop Router 2
    - Router 3 -> Dest 1: Cost 5, Next Hop Router 2
  - Status: **PASS**

### Practical 9: Dijkstra's Shortest Path (`09_dijkstra.c`)
- **Test Case**:
  - Input: 4 routers; Source Router 1; Link costs:
    ```
    0   2   999 1
    2   0   3   999
    999 3   0   2
    1   999 2   0
    ```
  - Output:
    - Router 1 -> Router 1 : Cost 0
    - Router 1 -> Router 2 : Cost 2
    - Router 1 -> Router 3 : Cost 3 (via Router 4: 1 + 2 = 3)
    - Router 1 -> Router 4 : Cost 1
  - Status: **PASS**

### Practical 10: IP Subnetting (CIDR) (`10_ip_subnetting.c`)
- **Test Case**:
  - Input: IP `192.168.1.75`, CIDR prefix `26`
  - Output:
    - Subnet Mask: `255.255.255.192`
    - Network Address: `192.168.1.64`
    - Broadcast Address: `192.168.1.127`
    - First Usable IP: `192.168.1.65`
    - Last Usable IP: `192.168.1.126`
    - Total Usable Hosts: `62`
  - Status: **PASS**

### Practical 11: TCP Client and Server (`11_tcp_server.c`, `12_tcp_client.c`)
- **Test Execution**: Server launched as background process; Client launched to connect to `127.0.0.1:8080`.
- **Server Trace**:
  ```
  TCP Server started successfully.
  Listening on port 8080... Waiting for client to connect...
  [Connection Established] Client connected successfully!
  Client says: Hello from TCP Client!
  Reply sent to client.
  Connection closed cleanly.
  ```
- **Client Trace**:
  ```
  Connecting to TCP Server at 127.0.0.1:8080...
  Connected to TCP Server!
  Message sent to server: "Hello from TCP Client!"
  Server replied: Hello from TCP Server! Connection confirmed.
  Client disconnected cleanly.
  ```
- Status: **PASS (100% End-to-End Handshake and Stream Communication Verified)**

### Practical 12: UDP Client and Server (`13_udp_server.c`, `14_udp_client.c`)
- **Test Execution**: Server launched as background datagram listener; Client launched to transmit datagram to `127.0.0.1:8080`.
- **Server Trace**:
  ```
  UDP Server started successfully.
  Waiting for datagram packet on port 8080...
  Received 22 bytes from 127.0.0.1:53258
  Client says: Hello from UDP Client!
  Reply sent to client.
  UDP Server shut down cleanly.
  ```
- **Client Trace**:
  ```
  Datagram sent to server: "Hello from UDP Client!"
  Waiting for reply from server...
  Server replied: Hello from UDP Server! Datagram received.
  UDP Client closed cleanly.
  ```
- Status: **PASS (100% Datagram Exchange and Sender Address Capture Verified)**

---

## 3. Summary of Testing Conclusions

1. **Every one of the 14 optimized C programs compiles cleanly** with zero syntax errors, zero compiler warnings, and zero linking errors.
2. **Every practical was actively executed and functionally verified** with actual inputs and validated against theoretical expected outputs.
3. **TCP and UDP client-server socket programs were live-tested** with concurrent process execution, establishing verified inter-process network communication over port 8080.
