#include "alarm.h"

#include <gmock/gmock.h>

TEST(Alarm, AlarmIsOffByDefault)
{
    auto alarm = Alarm();
    EXPECT_FALSE(alarm.is_alarm_on());
}
