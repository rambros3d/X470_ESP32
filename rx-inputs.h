//========================= RECEIVER ===============================

#ifdef SBUS
HardwareSerial SBUSS(1);
bfs::SbusRx sbus_rx(&SBUSS, RXpin, TXpin, RXinverted);
bfs::SbusData data;
#define sbusMin 172
#define sbusMax 1811
#endif

#ifdef IBUS
#define ibusMin 900
#define ibusMax 2100
IBusBM IBus;  // IBus object
#endif

//------------------------------------------------------------------
void RXsetup() {
#ifdef IBUS
  IBus.begin(Serial2, 1, AUX1, AUX2);
  //IBus.begin(Serial2, IBUSBM_NOTIMER, AUX1, AUX2);
#endif
}
//------------------------------------------------------------------
void ReadRX() {

#ifdef SBUS
  if (sbus_rx.Read()) {
    data = sbus_rx.data();  // Read and Organize the received data
    for (uint8_t i = 1; i <= 10; i++) {
      RXchannel[i] = map(data.ch[i - 1], sbusMin, sbusMax, RXmin, RXmax);
      RXchannel[i] = constrain(RXchannel[i], RXmin, RXmax);
    }
  }
#endif

#ifdef IBUS
  for (uint8_t i = 1; i <= 10; i++) {
    RXchannel[i] = IBus.readChannel(i - 1);
    RXchannel[i] = map(RXchannel[i], ibusMin, ibusMax, RXmin, RXmax);
    //RXchannel[i] = constrain(RXchannel[i], RXmin, RXmax);
  }
#endif

#ifdef RX_DEBUG
  /* Display the received data */
  for (uint8_t i = 1; i <= 10; i++) {
    Serial.print(RXchannel[i]);
    Serial.print("\t");
  }
#ifdef SBUS
  Serial.println(data.NUM_CH);
#else
  Serial.println();
#endif
#endif
  delay(1);
}
