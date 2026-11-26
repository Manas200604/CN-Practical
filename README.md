# Computer Networks Practicals - C Programming Project

A complete, structured, and exam-ready collection of **Computer Networks Laboratory Practicals** in C.

This project organizes and compares practical implementations across three dedicated folders:
1. `01_Existing_Codes/` - The original programs found in the workspace, preserved verbatim.
2. `02_PDF_Codes/` - The exact programs extracted from the *Computer Networks Practical Examination Study Handbook*.
3. `03_Best_Optimized_Codes/` - The refined, beginner-friendly, fully tested, and cross-platform C implementations (Windows & Linux).

---

## 📁 Repository Directory Structure

```text
Computer-Networks-Practicals/
│
├── 01_Existing_Codes/                  <- Verbatim workspace originals (unmodified)
│   ├── 01_even_parity.c
│   ├── 02_hamming_code.c
│   ├── 03_crc.c
│   ├── 04_stop_and_wait.c
│   ├── 05_go_back_n.c
│   ├── 06_selective_repeat.c
│   ├── 07_distance_vector_matrix.c     (Documented as missing in original workspace)
│   ├── 08_distance_vector_next_hop.c   (Documented as missing in original workspace)
│   ├── 09_dijkstra.c
│   ├── 10_ip_subnetting.c              (Documented as missing in original workspace)
│   ├── 11_tcp_server.c                 (Documented as missing in original workspace)
│   ├── 12_tcp_client.c                 (Documented as missing in original workspace)
│   ├── 13_udp_server.c                 (Documented as missing in original workspace)
│   └── 14_udp_client.c                 (Documented as missing in original workspace)
│
├── 02_PDF_Codes/                       <- Programs extracted from the Handbook PDF
│   ├── 01_even_parity.c
│   ├── 02_hamming_code.c
│   ├── 03_crc.c
│   ├── 04_stop_and_wait.c
│   ├── 05_go_back_n.c
│   ├── 06_selective_repeat.c
│   ├── 07_distance_vector_matrix.c
│   ├── 08_distance_vector_next_hop.c
│   ├── 09_dijkstra.c
│   ├── 10_ip_subnetting.c
│   ├── 11_tcp_server.c
│   ├── 12_tcp_client.c
│   ├── 13_udp_server.c
│   └── 14_udp_client.c
│
├── 03_Best_Optimized_Codes/            <- Tested, optimized, exam-ready C implementations
│   ├── 01_even_parity.c
│   ├── 02_hamming_code.c
│   ├── 03_crc.c
│   ├── 04_stop_and_wait.c
│   ├── 05_go_back_n.c
│   ├── 06_selective_repeat.c
│   ├── 07_distance_vector_matrix.c
│   ├── 08_distance_vector_next_hop.c
│   ├── 09_dijkstra.c
│   ├── 10_ip_subnetting.c
│   ├── 11_tcp_server.c
│   ├── 12_tcp_client.c
│   ├── 13_udp_server.c
│   └── 14_udp_client.c
│
├── README.md                           <- Project overview, compilation & run guide
├── CODE_COMPARISON.md                  <- Detailed practical-by-practical comparison
└── TESTING_REPORT.md                   <- Comprehensive compilation & test execution report
```

---

## 📚 List of 12 Practical Topics (14 C Files)

| Ch. | File Name | Practical Topic | OSI Layer | Core Concept |
|:---:|:---|:---|:---:|:---|
| 01 | `01_even_parity.c` | Even Parity Check | Data Link | Single-bit error detection using parity bit |
| 02 | `02_hamming_code.c` | Hamming Code (7,4) | Data Link | Single-bit error correction & syndrome decoding |
| 03 | `03_crc.c` | CRC (Cyclic Redundancy Check) | Data Link | Modulo-2 polynomial XOR division checksum |
| 04 | `04_stop_and_wait.c` | Stop-and-Wait ARQ | Data Link / Transport | 1-frame sliding window flow & error control |
| 05 | `05_go_back_n.c` | Go-Back-N ARQ | Data Link / Transport | Pipelining with cumulative retransmission |
| 06 | `06_selective_repeat.c` | Selective Repeat ARQ | Data Link / Transport | Out-of-order buffering & selective retransmission |
| 07 | `07_distance_vector_matrix.c` | Distance Vector (Matrix) | Network | All-pairs shortest path matrix (Floyd-Warshall) |
| 08 | `08_distance_vector_next_hop.c` | Distance Vector (Next Hop) | Network | Distributed Bellman-Ford routing table generation |
| 09 | `09_dijkstra.c` | Dijkstra's Shortest Path | Network | Single-source link-state greedy shortest path |
| 10 | `10_ip_subnetting.c` | IP Subnetting (CIDR) | Network | Bitwise masking, network/broadcast IDs, host range |
| 11 | `11_tcp_server.c` | TCP Server | Transport / App | Connection-oriented reliable stream socket |
| 11 | `12_tcp_client.c` | TCP Client | Transport / App | 3-way handshake & client-server stream communication |
| 12 | `13_udp_server.c` | UDP Server | Transport / App | Connectionless datagram socket (`recvfrom` / `sendto`) |
| 12 | `14_udp_client.c` | UDP Client | Transport / App | Datagram message transmission to server port |

---

## ⚙️ Compilation and Execution Instructions

### Prerequisites
- **C Compiler**: `gcc` (MinGW / TDM-GCC on Windows, or standard GCC on Linux/macOS).

### A. Practicals 1 to 9 (Standard C Programs)

Compile using:
```bash
gcc 01_even_parity.c -o 01_even_parity
./01_even_parity
```
*(On Windows cmd/PowerShell: use `01_even_parity.exe`)*

### B. Practical 10 (IP Subnetting)
Practical 10 uses `pow()` from `<math.h>`. On Linux, link the math library using `-lm`:
```bash
gcc 10_ip_subnetting.c -lm -o 10_ip_subnetting
./10_ip_subnetting
```
*(On Windows MinGW/GCC, `-lm` is linked automatically or can be provided)*

### C. Practicals 11 & 12 (Socket Programs: TCP & UDP)

The socket programs in `03_Best_Optimized_Codes` are **cross-platform**:
- On **Linux / macOS**: Compiled directly with `gcc`:
  ```bash
  gcc 11_tcp_server.c -o 11_tcp_server
  gcc 12_tcp_client.c -o 12_tcp_client
  gcc 13_udp_server.c -o 13_udp_server
  gcc 14_udp_client.c -o 14_udp_client
  ```
- On **Windows** (MinGW / GCC): Compiled with `-lws2_32` to link the Winsock library:
  ```bash
  gcc 11_tcp_server.c -o 11_tcp_server.exe -lws2_32
  gcc 12_tcp_client.c -o 12_tcp_client.exe -lws2_32
  gcc 13_udp_server.c -o 13_udp_server.exe -lws2_32
  gcc 14_udp_client.c -o 14_udp_client.exe -lws2_32
  ```

#### How to Run Socket Programs (Two Terminal Setup)
Socket communication requires two independent processes running simultaneously:

1. **Terminal 1 (Server First)**:
   ```bash
   ./11_tcp_server
   ```
   *The server binds to port 8080 and enters listening state.*

2. **Terminal 2 (Client Second)**:
   ```bash
   ./12_tcp_client
   ```
   *The client connects to 127.0.0.1:8080, sends a message, and receives the server's reply.*

The same two-terminal procedure applies to UDP (`13_udp_server` and `14_udp_client`).

---

## 🧪 Sample Inputs and Expected Outputs

### 1. Even Parity (`01_even_parity.c`)
- **Input Data**: `1011001` (4 ones -> parity bit `0` -> transmitted `10110010`)
- **Received Frame**: `10110010` -> **Result**: `NO ERROR DETECTED`
- **Corrupted Frame**: `10110011` -> **Result**: `ERROR DETECTED!`

### 2. Hamming Code (`02_hamming_code.c`)
- **Input 4 bits**: `1 0 1 1`
- **Generated Code**: `0 1 1 0 0 1 1` (Positions 1 to 7)
- **Received with Error at bit 5**: `0 1 1 0 1 1 1`
- **Syndrome**: `P4=1, P2=0, P1=1 -> Position 5`
- **Corrected Code**: `0 1 1 0 0 1 1` (Bit 5 flipped back)

### 3. Cyclic Redundancy Check (`03_crc.c`)
- **Data Bits**: `110101`
- **Generator Polynomial**: `1011`
- **CRC Remainder**: `111`
- **Transmitted Frame**: `110101111`
- **Receiver Check**: Remainder `000` -> `FRAME IS VALID`

### 4. IP Subnetting (`10_ip_subnetting.c`)
- **IP**: `192.168.1.75`, **CIDR**: `26`
- **Subnet Mask**: `255.255.255.192`
- **Network ID**: `192.168.1.64`
- **Broadcast ID**: `192.168.1.127`
- **Usable Host Range**: `192.168.1.65` to `192.168.1.126`
- **Total Usable Hosts**: `62`
