/*********************************************************************
   PicoTCP. Copyright (c) 2012 TASS Belgium NV. Some rights reserved.
   See LICENSE and COPYING for usage.

   .
 *********************************************************************/
#ifndef PICO_TFTP_H
#define PICO_TFTP_H
#define PICO_TFTP_PORT       (69)
#define PICO_TFTP_SIZE       (512U)

#define PICO_TFTP_NONE  0
#define PICO_TFTP_RRQ   1
#define PICO_TFTP_WRQ   2
#define PICO_TFTP_DATA  3
#define PICO_TFTP_ACK   4
#define TFTP_ERROR 5

/* User errors */
#define PICO_TFTP_ERR_OK    0
#define PICO_TFTP_ERR_PEER  1
#define PICO_TFTP_ERR_LOCAL 2
int pico_tftp_start_rx(union pico_address *a, uint16_t port, uint16_t family, 
        char *filename, int (*user_cb)(uint16_t err, uint8_t *block, uint32_t len));
int pico_tftp_start_tx(union pico_address *a, uint16_t port, uint16_t family, 
        char *filename, int (*user_cb)(uint16_t err, uint8_t *block, uint32_t len));
int pico_tftp_send(const uint8_t *data, int len);
int pico_tftp_listen(uint16_t family, int (*cb)(union pico_address *addr, uint16_t port, uint16_t opcode, char *filename));
void pico_tftp_close(void);

#endif
