#include <M5Unified.h>
#include <Unit_Encoder.h>

M5Canvas canvas(&M5.Display);
Unit_Encoder sensor;
int sda_pin = -1;
int scl_pin = -1;

void setup() {
    auto cfg = M5.config();
    cfg.clear_display = true;
    cfg.serial_baudrate = 115200;
    M5.begin(cfg);
    Serial.print("M5Unified version: ");
    Serial.print(M5UNIFIED_VERSION_MAJOR);
    Serial.print(".");
    Serial.print(M5UNIFIED_VERSION_MINOR);
    Serial.print(".");
    Serial.println(M5UNIFIED_VERSION_PATCH);
    sda_pin = M5.getPin(m5::ex_i2c_sda);
    scl_pin = M5.getPin(m5::ex_i2c_scl);
    Serial.printf("Use external I2C pin sda:%d, scl:%d\n", sda_pin, scl_pin);
    if (sda_pin >= 0 && scl_pin >= 0) {
        sensor.begin(&Wire, ENCODER_ADDR, sda_pin, scl_pin); // I2C address for encoder: 0x40 (ENCODER_ADDR defined in Unit_Encoder.h)
    } else {
        sensor.begin(&Wire);
    }
    canvas.createSprite(M5.Display.width(), 80);
    canvas.setTextSize(2);
    
    // scan i2c
    byte error, address;
    int nDevices = 0;

    Serial.println("Scanning for I2C devices ...");
    for (address = 0x01; address < 0x7f; address++) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0) {
            Serial.printf("I2C device found at address 0x%02X\n", address);
            nDevices++;
        } else if (error != 2) {
            Serial.printf("Error %d at address 0x%02X\n", error, address);
        }
    }
    if (nDevices == 0) {
        Serial.println("No I2C devices found");
    }
}

signed short int last_value = 0;

void loop() {
    signed short int encoder_value = sensor.getEncoderValue();
    bool btn_status                = sensor.getButtonStatus();
    if (last_value != encoder_value) {
        Serial.println(encoder_value);
        if (last_value > encoder_value) {
            sensor.setLEDColor(1, 0x000011);
        } else {
            sensor.setLEDColor(2, 0x111100);
        }
        last_value = encoder_value;
    } else {
        sensor.setLEDColor(0, 0x001100);
    }
    if (!btn_status) {
        sensor.setLEDColor(0, 0xC800FF);
    }
    canvas.fillSprite(BLACK);
    canvas.setCursor(0, 0);
    canvas.print("BTN: ");
    canvas.println(btn_status);
    canvas.print("ENC: ");
    canvas.println(encoder_value);
    canvas.println();
    canvas.print("SDA: ");
    canvas.println(sda_pin);
    canvas.print("SCL: ");
    canvas.println(scl_pin);
    canvas.pushSprite(0, 0);
    delay(20);
}