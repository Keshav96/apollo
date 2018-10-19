/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <gtest/gtest.h>
#include <memory>

#include "cybertron/common/util.h"
#include "cybertron/cybertron.h"
#include "cybertron/scheduler/policy/task_choreo.h"
#include "cybertron/scheduler/processor.h"

namespace apollo {
namespace cybertron {
namespace scheduler {

void func() {}
TEST(SchedulerPolicyTest, choreo) {
  auto processor = std::make_shared<Processor>();
  std::shared_ptr<ProcessorContext> ctx;
  ctx.reset(new TaskChoreoContext());
  processor->BindContext(ctx);
  ctx->BindProcessor(processor);

  std::shared_ptr<CRoutine> cr = std::make_shared<CRoutine>(func);
  EXPECT_TRUE(ctx->RqEmpty());
  cr->set_id(common::Hash("choreo"));
}

}  // namespace scheduler
}  // namespace cybertron
}  // namespace apollo