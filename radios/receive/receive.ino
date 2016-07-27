#include <VirtualWire.h>
void setup() {
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(12);
  vw_setup(4000);
  pinMode(13, OUTPUT);
  vw_rx_start();
}
void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    if (buf[0] == '1') {
      digitalWrite(13, 1);
    }
    if (buf[0] == '0') {
      digitalWrite(13, 0);
    }
  }
}
