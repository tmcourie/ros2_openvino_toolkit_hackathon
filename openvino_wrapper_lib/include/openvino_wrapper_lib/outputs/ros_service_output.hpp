// Copyright (c) 2018-2022 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @brief A header file with declaration for RosServiceOutput Class
 * @file ros_topic_output.hpp
 */

#ifndef OPENVINO_WRAPPER_LIB__OUTPUTS__ROS_SERVICE_OUTPUT_HPP_
#define OPENVINO_WRAPPER_LIB__OUTPUTS__ROS_SERVICE_OUTPUT_HPP_

#include <object_msgs/msg/object.hpp>
#include <object_msgs/msg/object_in_box.hpp>
#include <object_msgs/msg/objects_in_boxes.hpp>
#include <object_msgs/msg/emotion.hpp>
#include <object_msgs/msg/emotions_stamped.hpp>
#include <object_msgs/msg/age_gender.hpp>
#include <object_msgs/msg/age_gender_stamped.hpp>
#include <object_msgs/msg/head_pose.hpp>
#include <object_msgs/msg/head_pose_stamped.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/header.hpp>

#include <memory>
#include <string>
#include <vector>

#include "openvino_wrapper_lib/inferences/face_detection.hpp"
#include "openvino_wrapper_lib/outputs/ros_topic_output.hpp"

namespace Outputs
{
/**
 * @class RosServiceOutput
 * @brief This class handles and publish the detection result for service calling.
 */
class RosServiceOutput : public RosTopicOutput
{
public:
  explicit RosServiceOutput(std::string output_name)
  : RosTopicOutput(output_name) {}

  /**
   * @brief Publish all the detected infomations generated by the accept
   * functions with ros topic.
   */
  void handleOutput() override {}
  void clearData() override;

  void setServiceResponse(std::shared_ptr<object_msgs::srv::DetectObject::Response> response);
  void setResponseForFace(std::shared_ptr<object_msgs::srv::DetectObject::Response> response);
  void setServiceResponse(std::shared_ptr<object_msgs::srv::AgeGenderSrv::Response> response);
  void setServiceResponse(std::shared_ptr<object_msgs::srv::EmotionSrv::Response> response);
  void setServiceResponse(std::shared_ptr<object_msgs::srv::HeadPoseSrv::Response> response);
  void setServiceResponse(std::shared_ptr<object_msgs::srv::People::Response> response);

private:
  const std::string service_name_;
};
}  // namespace Outputs
#endif  // OPENVINO_WRAPPER_LIB__OUTPUTS__ROS_SERVICE_OUTPUT_HPP_