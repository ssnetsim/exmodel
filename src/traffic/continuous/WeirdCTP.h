#ifndef TRAFFIC_CONTINUOUS_WEIRDCTP_H_
#define TRAFFIC_CONTINUOUS_WEIRDCTP_H_

#include <json/json.h>
#include <prim/prim.h>

#include <string>

#include "event/Component.h"
#include "traffic/continuous/ContinuousTrafficPattern.h"

class WeirdCTP : public ContinuousTrafficPattern {
 public:
  WeirdCTP(const std::string& _name, const Component* _parent,
          u32 _numTerminals, u32 _self, Json::Value _settings);
  ~WeirdCTP();
  u32 nextDestination() override;

 private:
  u32 jump_;
  u32 next_;
};

#endif  // TRAFFIC_CONTINUOUS_WEIRDCTP_H_
