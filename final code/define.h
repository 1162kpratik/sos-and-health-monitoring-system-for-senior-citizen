#define WIFI_AP             "PRATIK"
#define WIFI_PASSWORD       "162kpratik"
#define TOKEN               "cIRK59mKVDJB4HD95JLQ"
#define THINGSBOARD_SERVER  "demo.thingsboard.io"
#define SERIAL_DEBUG_BAUD   115200

int sensorPin = A0;
int sensorValue = 0;
float EMA_a = 0.4;
int EMA_S = 0;
int highpass = 0;


const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
float ax = 0, ay = 0, az = 0, gx = 0, gy = 0, gz = 0;
boolean fall = false; //stores if a fall has occurred
boolean trigger1 = false; //stores if first trigger (lower threshold) has occurred
boolean trigger2 = false; //stores if second trigger (upper threshold) has occurred
boolean trigger3 = false; //stores if third trigger (orientation change) has occurred
byte trigger1count = 0; //stores the counts past since trigger 1 was set true
byte trigger2count = 0; //stores the counts past since trigger 2 was set true
byte trigger3count = 0; //stores the counts past since trigger 3 was set true
int angleChange = 0;
int fall_status=0;

// WiFi network info.
const char *ssid = "PRATIK"; // Enter your Wi-Fi Name
const char *pass = "162kpratik"; // Enter your Wi-Fi Password
void send_event(const char *event);
const char *host = "maker.ifttt.com";
const char *privateKey = "H5GtYAX5c74lrAVzeWrm";


