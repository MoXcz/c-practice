#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>

int main(void) {
  struct sockaddr_in sa;   // IPv4
  struct sockaddr_in6 sa6; // IPv6
  int result;

  // 'pton' stands for "Presentation to Network"
  // 'ntop' stands for "Network to Presentation"
  // 'AF' stands for "Address Family", and
  // 'INET' stands for "Internet"
  result = inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));
  if (result < 0)
    printf("Result: %d\n-1: error\n 0: address is not valid", result);

  result = inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr));
  if (result < 0)
    printf("Result: %d\n-1: error\n 0: address is not valid", result);
  /* Obsolete, they do not support IPv6:
   * - 'inet_addr()' and 'inet_aton()' were used for to create the address
   * - 'inet_ntoa()' was used for translation from bytes to the string
   */

  // IPv4:
  char ip4[INET_ADDRSTRLEN]; // space to hold the IPv4 string
  inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);
  printf("The IPv4 address is: %s\n", ip4);

  // IPv6:
  char ip6[INET6_ADDRSTRLEN]; // space to hold the IPv6 string
  inet_ntop(AF_INET6, &(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);
  printf("The IPv6 address is: %s\n", ip6);
}
