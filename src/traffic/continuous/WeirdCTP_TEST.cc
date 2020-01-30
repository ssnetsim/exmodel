#include "traffic/continuous/WeirdCTP.h"

#include <gtest/gtest.h>
#include <json/json.h>
#include <prim/prim.h>

#include "test/TestSetup_TEST.h"

TEST(WeirdCTP, simple) {
  TestSetup test(123, 123, 123, 456789);
}
