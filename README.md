# Minitalk - Inter-Process Communication using Signals

A simple client-server communication program that transmits text messages using Unix signals.

## 🔄 How it works

### Unix Signals
- **SIGUSR1**: Represents bit `1`
- **SIGUSR2**: Represents bit `0`
- Signals are sent from client to server using `kill()` system call

### Bit-by-bit Transmission

#### Client Process:
1. Takes each character from the input string
2. Converts character to binary (8 bits)
3. Sends each bit as a signal:
   - `SIGUSR1` for bit = 1
   - `SIGUSR2` for bit = 0
4. Waits between signals to prevent loss

#### Server Process:
1. Listens for incoming signals
2. Reconstructs each character bit by bit
3. Uses bit shifting to build the character:
   ```c
   if (signal == SIGUSR1)
       char_value |= (1 << bit_position);
   ```
4. Prints completed character when 8 bits received

## 📊 Example Transmission

Sending character `'A'` (ASCII 65 = `01000001`):

```
Bit position:  7 6 5 4 3 2 1 0
Binary:        0 1 0 0 0 0 0 1
Signal sent:   ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
               2 1 2 2 2 2 2 1

SIGUSR2 = 0, SIGUSR1 = 1
```

## 🚀 Usage

### Start the server:
```bash
./server
```
Server displays its PID (Process ID).

### Send message from client:
```bash
./client <server_pid> "Hello World!"
```

## ⚙️ Key Concepts

- **Process Communication**: Using signals instead of pipes or sockets
- **Binary Representation**: Each character split into 8 bits
- **Bit Manipulation**: Using bitwise operations to reconstruct characters
- **Signal Handling**: Asynchronous event handling in Unix systems

## 📁 Files

- `server.c` - Server that receives and displays messages
- `client.c` - Client that sends messages
- `utils.c` - Utility functions (ft_atoi, ft_putstr_fd, etc.)
- `minitalk.h` - Header with structures and function declarations

## 🔧 Compilation

```bash
make        # Compile both client and server
make clean  # Remove object files
make fclean # Remove all compiled files
make re     # Recompile everything
```

---