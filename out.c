struct ApolloRange;

struct String;

struct SockAddr;

struct TcpSocket;

struct TcpListener;

struct KernelTimespec;

struct ApolloRange
{
  int start;
  int end;
};

struct String
{
  const char * data;
  unsigned long long len;
};

struct SockAddr
{
  unsigned short sa_family;
  unsigned char[14] sa_data;
};

struct TcpSocket
{
  long long fd;
};

struct TcpListener
{
  long long fd;
  unsigned char[16] socketaddr;
};

struct KernelTimespec
{
  unsigned long long tv_sec;
  unsigned long long tv_nsec;
};

extern int
printf (const char * format); /* (imported) */

extern int
printf (const char * format); /* (imported) */

extern int
sockets ()
{
initial:
  return (int)0;
}

static struct TcpSocket
accept (struct TcpListener * self)
{
  long long socket_fd;
  long long listener_fd;
  unsigned char[16] * sockaddr;
  unsigned long long size;

b822672d-44a6-4117-a05e-fb9d7f5ef642:
  socket_fd = (long long)-((int)1);
  listener_fd = (*self).fd;
  sockaddr = bitcast(&(*self).socketaddr, unsigned char[16] *);
  size = (unsigned long long)(int)16;
  asm volatile ("\nmov %1, %%rdi\nxor %%rsi, %%rsi\nxor %%rdx, %%rdx\nmov $0x2b, %%rax\nsyscall\n" : "=a" (socket_fd) : "r" (listener_fd) : "rdi", "rsi", "rdx", "rcx", "r11", "memory")
  return (struct TcpSocket) {.fd=socket_fd};
}

static long long
new_tcp_socket ()
{
  unsigned long long af_inet;
  unsigned long long tcp_stream;
  long long socket_fd;

new_tcp_socket_block:
  af_inet = (unsigned long long)(int)2;
  tcp_stream = (unsigned long long)(int)1;
  socket_fd = (long long)-((int)1);
  asm volatile ("\nmov %1, %%rdi\nmov %2, %%rsi\nxor %%rdx, %%rdx\nmov $0x29, %%rax\nsyscall\n" : "=a" (socket_fd) : "r" (af_inet), "r" (tcp_stream) : "rdi", "rsi", "rdx", "memory")
  return socket_fd;
}

static unsigned char[4]
pton (const char * addr)
{
  int len;
  int index;
  unsigned char[4] rtn;

pton_block:
  len = (int)0;
  index = (int)0;
  rtn = (unsigned char[4]) {(unsigned char)(int)0, (unsigned char)(int)0, (unsigned char)(int)0, (unsigned char)(int)0};
  goto 46cdba7d-481c-45b2-a7b3-bb3da9a957d4;

be5c908a-d709-4074-a0a4-1918d845c2b5:
  if (addr[len] == (const char)(char)46) goto 44f57a4c-06ae-43b5-972e-a5c4a8ed988b; else goto afb71fed-104f-436f-88a5-78a134040e0f;

46cdba7d-481c-45b2-a7b3-bb3da9a957d4:
  if (addr[len] != (const char)(char)58) goto be5c908a-d709-4074-a0a4-1918d845c2b5; else goto a93c308a-da9d-4aad-b12d-ce7426e7eef6;

a93c308a-da9d-4aad-b12d-ce7426e7eef6:
  return rtn;

44f57a4c-06ae-43b5-972e-a5c4a8ed988b:
  index += (int)1;
  goto b6096d8c-8967-426d-a89c-74a64a8b86e0;

afb71fed-104f-436f-88a5-78a134040e0f:
  rtn[index] = rtn[index] * (unsigned char)(int)10;
  rtn[index] = rtn[index] + (unsigned char)addr[len] - (unsigned char)(char)48;
  goto b6096d8c-8967-426d-a89c-74a64a8b86e0;

b6096d8c-8967-426d-a89c-74a64a8b86e0:
  len += (int)1;
  goto 46cdba7d-481c-45b2-a7b3-bb3da9a957d4;
}

static unsigned short
htons (unsigned short number)
{
htons_block:
  return number >> (unsigned short)(int)8 & (unsigned short)(int)255 | (number & (unsigned short)(int)255) << (unsigned short)(int)8;
}

static unsigned char[16]
new_tcp_sock_addr (const char * addr)
{
  unsigned char[16] sa_data;
  int len;
  int port;
  int dd_index;
  int current_pos;
  unsigned short inv;
  unsigned char[4] b_addr;
  unsigned short family;

new_tcp_sock_addr_block:
  len = (int)0;
  port = (int)0;
  dd_index = (int)0;
  goto be310390-1aef-4825-aecc-6d9f48e84650;

56637f5e-4c21-46a7-9db4-93680596fa01:
  if (addr[len] == (const char)(char)58) goto 5810112c-40fb-47a6-a815-02e9e0827cb9; else goto 627aaec5-c7e6-489b-ac85-59ed40a63a98;

be310390-1aef-4825-aecc-6d9f48e84650:
  if (addr[len] != (const char)(char)0) goto 56637f5e-4c21-46a7-9db4-93680596fa01; else goto 579fa62a-6472-4be5-af20-f91e6ddd1eb2;

579fa62a-6472-4be5-af20-f91e6ddd1eb2:
  current_pos = dd_index + (int)1;
  goto 0c9f9dcc-f845-4a90-95f5-91acfa2dc127;

5810112c-40fb-47a6-a815-02e9e0827cb9:
  dd_index = len;
  goto 627aaec5-c7e6-489b-ac85-59ed40a63a98;

627aaec5-c7e6-489b-ac85-59ed40a63a98:
  len += (int)1;
  goto be310390-1aef-4825-aecc-6d9f48e84650;

43ca4cff-e48c-45ba-8bed-2fcaf827f94b:
  port = port * (int)10 + (int)(addr[current_pos] - (const char)(char)48);
  current_pos += (int)1;
  goto 0c9f9dcc-f845-4a90-95f5-91acfa2dc127;

0c9f9dcc-f845-4a90-95f5-91acfa2dc127:
  if (addr[current_pos] != (const char)(char)0) goto 43ca4cff-e48c-45ba-8bed-2fcaf827f94b; else goto 61a4daa1-ecae-4fff-9f63-57874f8971aa;

61a4daa1-ecae-4fff-9f63-57874f8971aa:
  inv = htons (((unsigned short)port));
  b_addr = pton (addr);
  family = (unsigned short)(int)2;
  (void)memcpy ((&sa_data[(int)0]), ((const void *)&family), ((size_t)(int)2));
  (void)memcpy ((&sa_data[(int)2]), ((const void *)&inv), ((size_t)(int)2));
  (void)memcpy ((&sa_data[(int)4]), ((const void *)&b_addr), ((size_t)(int)4));
  return sa_data;
}

static struct TcpListener
new_tcp_listener (const char * addr)
{
  long long tcp_socket;
  unsigned char[16] sock_addr;
  unsigned char[16] * sock_addr_ptr;
  unsigned long long addr_len;
  long long result;

new_tcp_listener_block:
  tcp_socket = new_tcp_socket ();
  sock_addr = new_tcp_sock_addr (addr);
  sock_addr_ptr = &sock_addr;
  addr_len = (unsigned long long)(int)16;
  result = (long long)-((int)1);
  asm volatile ("\nmov %1, %%rdi\nmov %2, %%rsi\nmov %3, %%rdx\nmov $0x31, %%rax\nsyscall\n" : "=a" (result) : "r" (tcp_socket), "r" (sock_addr_ptr), "r" (addr_len) : "rdi", "rsi", "rdx", "memory")
  asm volatile ("\nmov %1, %%rdi\nmov $256, %%rsi\nmov $0x32, %%rax\nsyscall\n" : "=a" (result) : "r" (tcp_socket) : "rdi", "rsi", "memory")
  return (struct TcpListener) {.fd=tcp_socket, .socketaddr=sock_addr};
}

extern int
printf (const char * format); /* (imported) */

extern int
printf (const char * format); /* (imported) */

extern int
allocations ()
{
initial:
  return (int)0;
}

static void *
mmap (unsigned long long size, unsigned long long prot, unsigned long long flags)
{
  void * dest;
  unsigned long long addr;
  long long fd;
  unsigned long long result;

mmap_block:
  addr = bitcast(&dest, unsigned long long);
  fd = (long long)((int)1 - (int)2);
  result = (unsigned long long)(int)0;
  asm ("\nmov %1, %%rdi\nmov %2, %%rsi\nmov %3, %%rdx\nmov %4, %%r10\nmov %5, %%r8\nxor %%r10, %%r10\nmov $9, %%rax\nsyscall\n" : "=a" (result) : "r" (addr), "r" (size), "r" (prot), "r" (flags), "r" (fd) : "rdi", "rsi", "r10", "r9", "r10", "memory")
  (void)printf ("Result %d\n", result);
  return dest;
}

extern int
threads ()
{
initial:
  return (int)0;
}

static void
sleep (unsigned long long seconds, unsigned long long nanos)
{
  struct KernelTimespec time;
  struct KernelTimespec * time_addr;
  struct KernelTimespec remaining;
  struct KernelTimespec * remaining_addr;
  unsigned long long result;

sleep_block:
  time = (struct KernelTimespec) {.tv_sec=seconds, .tv_nsec=nanos};
  time_addr = &time;
  remaining_addr = &remaining;
  result = (unsigned long long)(int)0;
  asm ("\nmov %1, %%rdi\nmov %2, %%rsi\nmov $0x23, %%rax\nsyscall\n" : "=a" (result) : "r" (time_addr), "r" (remaining_addr) : "rdi", "rsi", "memory")
  return;
}

extern int
main ()
{
  struct TcpListener tcp_listener;
  struct TcpSocket socket;

initial:
  tcp_listener = new_tcp_listener ("127.0.0.1:8080");
  (void)printf ("TcpListener socket fd is %d\n", tcp_listener.fd);
  goto 8d3178e6-e9b3-44e2-b350-982af7ab6350;

c09d7fa7-9c04-4d81-aaab-886649098b21:
  socket = accept ((bitcast(&tcp_listener, struct TcpListener *)));
  (void)printf ("Socket fd is %d\n", socket.fd);
  goto 8d3178e6-e9b3-44e2-b350-982af7ab6350;

8d3178e6-e9b3-44e2-b350-982af7ab6350:
  if ((bool)1) goto c09d7fa7-9c04-4d81-aaab-886649098b21; else goto d228ad32-9ac2-49dc-bd26-b02f82076be4;

d228ad32-9ac2-49dc-bd26-b02f82076be4:
  return (int)0;
}

