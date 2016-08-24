// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <gtest/gtest.h>

TEST(Issue338, SignedLong) {
  struct cStepsFromZero {
    signed long slAzimStepsFromZero;
    signed long slElevStepsFromZero;
  };
  cStepsFromZero mystepsfromzero;
  mystepsfromzero.slAzimStepsFromZero = 1234567;

  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["Azimuth Steps From Zero"] = mystepsfromzero.slAzimStepsFromZero;

  char json[256];
  root.printTo(json, sizeof(json));
  ASSERT_STREQ("{\"Azimuth Steps From Zero\":1234567}", json);

  root.prettyPrintTo(json, sizeof(json));
  ASSERT_STREQ("{\r\n  \"Azimuth Steps From Zero\": 1234567\r\n}", json);
}
