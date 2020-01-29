#include "traffic/continuous/WeirdCTP.h"

#include <factory/ObjectFactory.h>

#include <cassert>

WeirdCTP::WeirdCTP(
    const std::string& _name, const Component* _parent, u32 _numTerminals,
    u32 _self, Json::Value _settings)
    : ContinuousTrafficPattern(_name, _parent, _numTerminals, _self,
                               _settings),
      jump_(1), next_(self_) {}

WeirdCTP::~WeirdCTP() {}

u32 WeirdCTP::nextDestination() {
  u32 dest = next_;
  next_ = (next_ + jump_) % numTerminals_;
  jump_ = jump_ == numTerminals_ ? 1 : jump_ + 1;
  return dest;
}

registerWithObjectFactory("weird", ContinuousTrafficPattern,
                          WeirdCTP, CONTINUOUSTRAFFICPATTERN_ARGS);
