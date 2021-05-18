#include <Arduino.h>

// Parameters can be changed by user
namespace {
constexpr uint32_t seconds_to_open_valve = 10;
constexpr uint32_t seconds_to_close_valve = 30 * 60;
};

// Parameters should NOT be changed
namespace {
enum State {
  STATE_INIT = 0,
  STATE_OPEN,
  STATE_CLOSE,
};

constexpr uint8_t PIN_SOLENOID = 0;
constexpr uint8_t PIN_LED = 1; //LED on Digipark ATTiny Model A or Pro
};

inline uint32_t to_msec(const uint32_t seconds) {
  return seconds * 1000;
}

inline State transitState(const State now_state) {
  static uint32_t prev = 0;
  const uint32_t now = millis();
  State next_state = now_state;

  if (now_state == STATE_INIT) {
    prev = now;
    next_state = STATE_CLOSE;
  } else if (now_state == STATE_CLOSE) {
    if (now - prev > to_msec(seconds_to_close_valve)) {
      prev = now;
      next_state = STATE_OPEN;
    }
  } else if (now_state == STATE_OPEN) {
    if (now - prev > to_msec(seconds_to_open_valve)) {
      prev = now;
      next_state = STATE_INIT;
    }
  }

  return next_state;
}

void setup(void) {
  digitalWrite(PIN_SOLENOID, LOW);
  digitalWrite(PIN_LED, LOW);
  pinMode(PIN_SOLENOID, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  static State now = STATE_INIT;
  const State next = transitState(now);

  if (now != next) {
    if (next == STATE_OPEN) {
      digitalWrite(PIN_SOLENOID, HIGH);
      digitalWrite(PIN_LED, HIGH);
    } else {
      digitalWrite(PIN_SOLENOID, LOW);
      digitalWrite(PIN_LED, LOW);
    }
    now = next;
  }
}
