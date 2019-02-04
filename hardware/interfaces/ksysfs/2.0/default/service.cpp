#undef PASS_THROUGH_METHOD

#define LOG_TAG "android.hardware.ksysfs@2.0-service"

#include <android/hardware/ksysfs/2.0/IKsyshw.h>
#include <hidl/LegacySupport.h>

using android::hardware::ksysfs::V2_0::IKsyshw;

#ifdef PASS_THROUGH_METHOD
using android::hardware::defaultPassthroughServiceImplementation;

int main() {
    return defaultPassthroughServiceImplementation<ISimphw>("ksysfs");
}
#endif /* PASS_THROUGH_METHOD */

#ifndef PASS_THROUGH_METHOD
#include "Ksyshw.h"

using android::hardware::ksysfs::V2_0::implementation::Ksyshw;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::sp;

int main() {
      int res;
      android::sp<IKsyshw> ser = Ksyshw::getInstance();
      ALOGE("Ksysfs main");
      configureRpcThreadpool(1, true /*callerWillJoin*/);

      if (ser != nullptr) {
          res = ser->registerAsService();
          if(res != 0)
            ALOGE("Can't register instance of Ksysfs Hardware, nullptr");
      } else {
          ALOGE("Can't create instance of Ksysfs Hardware, nullptr");
      }

      joinRpcThreadpool();

      return 0; // should never get here
}
#endif /* ! PASS_THROUGH_METHOD */
