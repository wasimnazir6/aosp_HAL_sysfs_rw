#ifndef ANDROID_HARDWARE_KSYSFS_V2_0_KSYSHW_H
#define ANDROID_HARDWARE_KSYSFS_V2_0_KSYSHW_H

#include <android/hardware/ksysfs/2.0/IKsyshw.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace ksysfs {
namespace V2_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Ksyshw : public IKsyshw {
    // Methods from IKsysw follow.
    Return<int32_t> ksysfn(int32_t valueIn) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    static IKsyshw* getInstance(void);
};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IKsyshw* HIDL_FETCH_IKsyshw(const char* name);

}  // namespace implementation
}  // namespace V2_0
}  // namespace ksysfs
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_KSYSFS_V2_0_KSYSHW_H
