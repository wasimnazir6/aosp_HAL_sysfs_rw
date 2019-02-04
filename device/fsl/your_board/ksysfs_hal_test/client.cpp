#define LOG_TAG "android.hardware.ksysfs@2.0-service"

#include <android/hardware/ksysfs/2.0/IKsyshw.h>
#include <hidl/Status.h>
#include <hidl/LegacySupport.h>
#include <utils/misc.h>
#include <utils/Log.h>
#include <hardware/hardware.h>
#include <hidl/HidlSupport.h>

#include<stdio.h>

using android::hardware::ksysfs::V2_0::IKsyshw;
using android::sp;

int main() {
      int res;
      android::sp<IKsyshw> ser = IKsyshw::getService();

      res = ser->ksysfn(80);

      printf("val=%d\n",res);

      return 0;
}
