#undef PASS_THROUGH_METHOD
#define SYSFS_CHECK
#define SYSPATH	"/sys/class/backlight/pwm-backlight.0/brightness"

#include "Ksyshw.h"

namespace android {
namespace hardware {
namespace ksysfs {
namespace V2_0 {
namespace implementation {

// Methods from IKsyshw follow.
Return<int32_t> Ksyshw::ksysfn(int32_t valueIn) {
#ifdef SYSFS_CHECK
    // TODO implement
    int result = -1;
    FILE *file;
	file = fopen(SYSPATH, "w");
    if (!file) {
        return result;
    }
    fprintf(file, "%d", valueIn);
    fclose(file);
	return valueIn;
#else
    return valueIn + 10;
#endif
}

#ifndef PASS_THROUGH_METHOD
IKsyshw *Ksyshw::getInstance(void){
  return new Ksyshw();
}
#endif

// Methods from ::android::hidl::base::V1_0::IBase follow.

#ifdef PASS_THROUGH_METHOD
IKsyshw* HIDL_FETCH_IKsyshw(const char* /* name */) {
    return new Ksyshw();
}
#endif

}  // namespace implementation
}  // namespace V2_0
}  // namespace ksysfs
}  // namespace hardware
}  // namespace android
