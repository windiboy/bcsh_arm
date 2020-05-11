#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <ros/ros.h>
#include <iostream>
int main(int argc, char** argv) {
    ros::init(argc, argv, "top_controllers");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(1);
    spinner.start();
    ros::Rate loop_rate(10);

    static const std::string PLANNING_GROUP = "arm";
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

    // Raw pointers are frequently used to refer to the planning group for improved performance.
    const robot_state::JointModelGroup* joint_model_group =
            move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    ROS_INFO_NAMED("tutorial", "Planning frame: %s", move_group.getPlanningFrame().c_str());
    ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());
    ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
    std::copy(move_group.getJointModelGroupNames().begin(), move_group.getJointModelGroupNames().end(),
              std::ostream_iterator<std::string>(std::cout, ", "));
    //pose规划
    geometry_msgs::Pose target_pose1;
    target_pose1.orientation.w = 0.0;
    target_pose1.position.x = 0.2;
    target_pose1.position.y = 0.1;
    target_pose1.position.z = 0.0;
    move_group.setPoseTarget(target_pose1);
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;

    bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

    ROS_INFO_NAMED("tutorial", "Visualizing plan 1 (pose goal) %s", success ? "" : "FAILED");
    //关节空间规划
//    moveit::core::RobotStatePtr current_state = move_group.getCurrentState();
//    std::vector<double> joint_group_positions;
//    current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
//    joint_group_positions[0] = -1.0;  // radians
//    move_group.setJointValueTarget(joint_group_positions);
//    success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
//    ROS_INFO_NAMED("tutorial", "Visualizing plan 2 (joint space goal) %s", success ? "" : "FAILED");
    //笛卡尔路径点规划
//    std::vector<geometry_msgs::Pose> waypoints;
//    geometry_msgs::Pose target_pose;
//    target_pose.position.x -= 0.02;
//    waypoints.push_back(target_pose);  // down
////    target_pose.position.y += 0.1;
////    waypoints.push_back(target_pose);  // up
//    move_group.setMaxVelocityScalingFactor(0.1);
//    moveit_msgs::RobotTrajectory trajectory;
//    const double jump_threshold = 0.0;
//    const double eef_step = 0.01;
//    double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
//    ROS_INFO_NAMED("tutorial", "Visualizing plan 4 (Cartesian path) (%.2f%% acheived)", fraction * 100.0);


    move_group.move();
    while (ros::ok()){
        loop_rate.sleep();
    }
    return 0;
}