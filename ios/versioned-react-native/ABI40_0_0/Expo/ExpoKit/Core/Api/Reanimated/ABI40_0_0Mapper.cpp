#include "ABI40_0_0Mapper.h"
#include "ABI40_0_0SharedParent.h"
#include "ABI40_0_0MutableValue.h"

namespace ABI40_0_0reanimated {

Mapper::Mapper(NativeReanimatedModule *module,
               unsigned long id,
               jsi::Function &&mapper,
               std::vector<std::shared_ptr<MutableValue>> inputs,
               std::vector<std::shared_ptr<MutableValue>> outputs):
id(id),
module(module),
mapper(std::move(mapper)),
inputs(inputs),
outputs(outputs) {
  auto markDirty = [this, module]() {
    this->dirty = true;
    module->maybeRequestRender();
  };
  for (auto input : inputs) {
    input->addListener(id, markDirty);
  }
}

void Mapper::execute(jsi::Runtime &rt) {
  dirty = false;
  mapper.callWithThis(rt, mapper);
}

Mapper::~Mapper() {
  for (auto input : inputs) {
    input->removeListener(id);
  }
}

}
