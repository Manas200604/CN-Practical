# Code Comparison: Existing vs. PDF vs. Optimized Versions

This document provides a thorough, practical-by-practical analysis comparing the programs across:
1. `01_Existing_Codes/` (Workspace originals)
2. `02_PDF_Codes/` (Extracted from the Handbook PDF)
3. `03_Best_Optimized_Codes/` (Final refined, tested versions)

---

## Summary Overview

- **Existing Programs in Workspace**: 7 practicals found (bundled inside `error_detection.cpp`, `Sliding Window Mechanism.cpp`, and `dijkstra.cpp`).
- **PDF Programs in Handbook**: All 12 practicals (14 source files) found and extracted.
- **Optimized Programs Created**: All 14 source files fully created, compiled, and tested.
- **Programs Missing in Original Folder**: Practicals 7, 8, 10, 11 (Server & Client), and 12 (Server & Client) — 7 files in total.

---

## Detailed Practical-by-Practical Analysis

### Practical 1: Even Parity Check (`01_even_parity.c`)
- **Existing Version Found**: Yes (as `parityCheck()` in `error_detection.cpp`).
- **PDF Version Found**: Yes (Chapter 1, Page 4).
- **Existing Strengths**: Validates input bits strictly to ensure only `'0'` or `'1'` are entered.
- **Existing Weaknesses**: Bundled inside a multi-practical menu; calculates parity bit for the sender but does not simulate the receiver checking the transmitted frame for errors.
- **PDF Strengths**: Complete end-to-end communication flow: sender appends parity bit, simulates transmission, and receiver checks if received frame has odd or even 1s.
- **PDF Weaknesses**: Fixed-size arrays with minimal input boundary checking.
- **Selected Starting Point**: PDF logic combined with existing input validation.
- **Improvements in Optimized Version**:
  - Implemented end-to-end sender and receiver simulation.
  - Added strict binary input validation.
  - Clear, educational printouts explaining why the parity bit was chosen and how receiver detects bit flips.

---

### Practical 2: Hamming Code (7,4) (`02_hamming_code.c`)
- **Existing Version Found**: Yes (as `hammingCode()` in `error_detection.cpp`).
- **PDF Version Found**: Yes (Chapter 2, Page 10).
- **Existing Strengths**: Clean bit-wise XOR calculation for parity bits `h[0]`, `h[1]`, `h[3]` using 0-based indexing.
- **Existing Weaknesses**: Only generates the 7-bit codeword at sender; lacks receiver syndrome computation and automatic error correction.
- **PDF Strengths**: Uses textbook standard 1-based indexing (`h[1]` to `h[7]`), computes syndromes `p1, p2, p4`, identifies exact error position, and flips the corrupted bit.
- **PDF Weaknesses**: Assumes space-separated integers for input rather than string parsing.
- **Selected Starting Point**: PDF version.
- **Improvements in Optimized Version**:
  - Maintained clear 1-based textbook indexing.
  - Added explicit breakdown of data bits vs. parity bit positions.
  - Implemented syndrome calculation: `error = (p4 * 4) + (p2 * 2) + (p1 * 1)`.
  - Added automated bit correction and recovered data bit extraction.

---

### Practical 3: Cyclic Redundancy Check (CRC) (`03_crc.c`)
- **Existing Version Found**: Yes (as `crc()` in `error_detection.cpp`).
- **PDF Version Found**: Yes (Chapter 3, Page 15-16).
- **Existing Strengths**: Manual XOR in-place array manipulation.
- **Existing Weaknesses**: Uses fixed temporary arrays and converts strings to integer arrays; does not simulate receiver validation.
- **PDF Strengths**: Clean helper function `divide(char data[], char gen[])` performing string-based XOR modulo-2 division; simulates receiver frame validation.
- **PDF Weaknesses**: Scanned text in PDF omitted the closing brace and `error = 1` assignment on page 16.
- **Selected Starting Point**: PDF version with OCR bug fix.
- **Improvements in Optimized Version**:
  - Restored missing block from page 16 cleanly.
  - Optimized `modulo2Divide()` function for clarity and reliability.
  - Validates minimum generator length.
  - Clear breakdown of original data, generator polynomial, remainder, and receiver verification.

---

### Practical 4: Stop-and-Wait ARQ (`04_stop_and_wait.c`)
- **Existing Version Found**: Yes (as `stopAndWait()` in `Sliding Window Mechanism.cpp`).
- **PDF Version Found**: Yes (Chapter 4, Page 21).
- **Existing Strengths**: Robust input validation functions (`readPositive()`, `readFrame()`).
- **Existing Weaknesses**: Overly complex input handling helper functions spanning 40 lines.
- **PDF Strengths**: Extremely concise (17 lines), easy to memorize and explain in viva.
- **PDF Weaknesses**: Basic output trace.
- **Selected Starting Point**: PDF logic combined with robust input validation.
- **Improvements in Optimized Version**:
  - Clear simulation trace highlighting Sender, Network (loss simulation), Timeout, Retransmission, and Receiver ACK.
  - Handled invalid frame counts and out-of-range loss numbers safely.

---

### Practical 5: Go-Back-N ARQ (`05_go_back_n.c`)
- **Existing Version Found**: Yes (as `goBackN()` in `Sliding Window Mechanism.cpp`).
- **PDF Version Found**: Yes (Chapter 5, Page 26).
- **Existing Strengths**: Window boundary checking and frame tracking.
- **Existing Weaknesses**: Complex loop structures with multiple condition branches.
- **PDF Strengths**: Simple `while (base <= n)` sliding window loop; clearly shows that upon loss, the entire remaining window is retransmitted.
- **PDF Weaknesses**: Scanned page dropped assignment operators in `int base 1;` and `%d` in `printf`.
- **Selected Starting Point**: PDF version with syntax restoration.
- **Improvements in Optimized Version**:
  - Fixed syntax errors from PDF scan.
  - Clarified the Go-Back-N mechanism: frames prior to loss succeed, the lost frame triggers timeout, and frames from `lost` to `end` are retransmitted.
  - Beginner-friendly console output with bracketed frame ranges.

---

### Practical 6: Selective Repeat ARQ (`06_selective_repeat.c`)
- **Existing Version Found**: Yes (as `selectiveRepeat()` in `Sliding Window Mechanism.cpp`).
- **PDF Version Found**: Yes (Chapter 6, Page 31).
- **Existing Strengths**: Validates window sizes.
- **Existing Weaknesses**: Nested loop logic is lengthy and hard to follow in exams.
- **PDF Strengths**: Clear two-step logic per window: 1) send all frames, 2) retransmit *only* the lost frame if it was in that window.
- **PDF Weaknesses**: Minimal explanatory comments.
- **Selected Starting Point**: PDF version.
- **Improvements in Optimized Version**:
  - Shows contrasting behavior against Go-Back-N: only the corrupted/lost frame is retransmitted.
  - Clear simulation trace showing individual frame ACKs and selective retransmission.

---

### Practical 7: Distance Vector Routing - Distance Matrix (`07_distance_vector_matrix.c`)
- **Existing Version Found**: No (Missing from workspace).
- **PDF Version Found**: Yes (Chapter 7, Page 36).
- **Existing Strengths/Weaknesses**: N/A (Missing).
- **PDF Strengths**: Direct, elegant Floyd-Warshall dynamic programming implementation with 3 nested loops (`k, i, j`).
- **PDF Weaknesses**: Magic number `999` hardcoded without `#define INF`.
- **Selected Starting Point**: PDF version.
- **Improvements in Optimized Version**:
  - Defined `#define INF 999` and `#define MAX 10`.
  - Formatted final distance matrix with router headers (`R1`, `R2`, `R3`) and aligned columns for presentation.

---

### Practical 8: Distance Vector Routing - Next Hop (`08_distance_vector_next_hop.c`)
- **Existing Version Found**: No (Missing from workspace).
- **PDF Version Found**: Yes (Chapter 8, Page 41).
- **Existing Strengths/Weaknesses**: N/A (Missing).
- **PDF Strengths**: Correct distributed Bellman-Ford table relaxation using `do ... while (changed)`.
- **PDF Weaknesses**: Scanned PDF had slight formatting compression.
- **Selected Starting Point**: PDF version.
- **Improvements in Optimized Version**:
  - Defined `#define INF 999` and `#define MAX 10`.
  - Structured routing table printing showing Destination, Cost, and Next Hop for each router.
  - Properly handled self-hops (`i == j`) and unreachable destinations (`INF`).

---

### Practical 9: Dijkstra's Shortest Path Algorithm (`09_dijkstra.c`)
- **Existing Version Found**: Yes (`dijkstra.cpp` in workspace).
- **PDF Version Found**: Yes (Chapter 9, Page 46-47).
- **Existing Strengths**: Pure C implementation despite `.cpp` extension; clean greedy relaxation loop.
- **Existing Weaknesses**: Missing check for unreachable nodes (`min == 999`), which could cause unnecessary iterations.
- **PDF Strengths**: Includes `if (u == -1) break;` guard and explicitly prints `"Unreachable"` for disconnected routers.
- **PDF Weaknesses**: Page break between lines 46 and 47 split a `printf` statement.
- **Selected Starting Point**: Synthesis of existing file and PDF version.
- **Improvements in Optimized Version**:
  - Clean C syntax with `#define INF 999`.
  - Early exit when no reachable unvisited node remains (`u == -1`).
  - Clear path cost output distinguishing reachable and unreachable destinations.

---

### Practical 10: IP Subnetting (CIDR) (`10_ip_subnetting.c`)
- **Existing Version Found**: No (Missing from workspace).
- **PDF Version Found**: Yes (Chapter 10, Page 51-52).
- **Existing Strengths/Weaknesses**: N/A (Missing).
- **PDF Strengths**: Comprehensive subnet calculations: Subnet Mask, Network Address, Broadcast Address, First Usable IP, Last Usable IP, and Total Hosts.
- **PDF Weaknesses**: Scanned text dropped minus signs and bitwise OR `|`.
- **Selected Starting Point**: PDF version with mathematical and bitwise correction.
- **Improvements in Optimized Version**:
  - Restored bitwise formulas: `network = ip & mask` and `broadcast = network | (255 - mask)`.
  - Added octet range validation (0-255) and CIDR prefix bounds check (0-32).
  - Explicit handling of `/31` (point-to-point links) and `/32` (host routes).

---

### Practical 11: TCP Server and Client (`11_tcp_server.c`, `12_tcp_client.c`)
- **Existing Version Found**: No (Missing from workspace).
- **PDF Version Found**: Yes (Chapter 11, Pages 57 & 58).
- **Existing Strengths/Weaknesses**: N/A (Missing).
- **PDF Strengths**: Clean POSIX socket calls (`socket`, `bind`, `listen`, `accept`, `connect`, `read`, `write`, `close`).
- **PDF Weaknesses**: Linux-only headers (`<unistd.h>`, `<arpa/inet.h>`); fails to compile on Windows without POSIX emulator.
- **Selected Starting Point**: PDF architecture augmented with conditional cross-platform macros.
- **Improvements in Optimized Version**:
  - Added conditional compilation `#ifdef _WIN32` supporting both Windows Winsock (`ws2_32`) and Linux/POSIX sockets with zero code changes.
  - Added port reuse considerations and detailed socket status logging.
  - Clean, symmetrical message exchange and proper socket shutdown.

---

### Practical 12: UDP Server and Client (`13_udp_server.c`, `14_udp_client.c`)
- **Existing Version Found**: No (Missing from workspace).
- **PDF Version Found**: Yes (Chapter 12, Pages 63 & 64).
- **Existing Strengths/Weaknesses**: N/A (Missing).
- **PDF Strengths**: Demonstrates connectionless socket operations using `recvfrom()` and `sendto()`.
- **PDF Weaknesses**: Linux-only POSIX headers.
- **Selected Starting Point**: PDF architecture augmented with conditional cross-platform macros.
- **Improvements in Optimized Version**:
  - Implemented dual-platform support (Windows Winsock and Linux POSIX).
  - Server captures client's ephemeral IP and port dynamically from `recvfrom()` and replies to that exact sender.
  - Clean client datagram dispatch without requiring `connect()`.
