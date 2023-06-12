
AsyncWebServer server(80);

const char* ssid = "Home";
const char* password = "12345678";  
const char* apSSID = "X470-S3";
const char* apPassword = "12121212";

void WifiSetup() {
//--------------------------Wifi Connection--------------------------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to Wi-Fi. IP address: ");
  Serial.println(WiFi.localIP());

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect to Wi-Fi. Starting Access Point...");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(apSSID, apPassword);

    Serial.print("Access Point started. IP address: ");
    Serial.println(WiFi.softAPIP());
  }
//----------------------------------------------------------------------------

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send(200, "text/plain", "Hi! The server is working");
  });

  AsyncElegantOTA.begin(&server);  // Start AsyncElegantOTA

  WebSerial.begin(&server);
  WebSerial.onMessage(recvMsg);  // Attach Message Callback

  server.begin();
  pinMode(BOARD_LED, OUTPUT);
}

/* Message callback of WebSerial */
void recvMsg(uint8_t* data, size_t len) {
  WebSerial.println("Received Data...");
  String d = "";
  for (int i = 0; i < len; i++) {
    d += char(data[i]);
  }
  WebSerial.println(d);
}
