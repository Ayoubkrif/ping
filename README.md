# ping
ping reimplementation in C

// struct icmphdr
// {
//   uint8_t type;		/* message type */
//   uint8_t code;		/* type sub-code */
//   uint16_t checksum;
//   union
//   {
//     struct
//     {
//       uint16_t	id;
//       uint16_t	sequence;
//     } echo;			/* echo datagram */
//     uint32_t	gateway;	/* gateway address */
//     struct
//     {
//       uint16_t	__glibc_reserved;
//       uint16_t	mtu;
//     } frag;			/* path mtu discovery */
//   } un;
// };
