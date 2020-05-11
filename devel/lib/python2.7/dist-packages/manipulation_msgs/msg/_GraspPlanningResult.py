# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from manipulation_msgs/GraspPlanningResult.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import manipulation_msgs.msg
import std_msgs.msg
import sensor_msgs.msg

class GraspPlanningResult(genpy.Message):
  _md5sum = "ff7a88c4aec40207164535a24dc9c440"
  _type = "manipulation_msgs/GraspPlanningResult"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======

# the list of planned grasps
Grasp[] grasps

# whether an error occurred
GraspPlanningErrorCode error_code


================================================================================
MSG: manipulation_msgs/Grasp
# A name for this grasp
string id

# The internal posture of the hand for the pre-grasp
# only positions are used
sensor_msgs/JointState pre_grasp_posture

# The internal posture of the hand for the grasp
# positions and efforts are used
sensor_msgs/JointState grasp_posture

# The position of the end-effector for the grasp 
geometry_msgs/PoseStamped grasp_pose

# The estimated probability of success for this grasp, or some other
# measure of how "good" it is.
float64 grasp_quality

# The approach motion
GripperTranslation approach

# The retreat motion
GripperTranslation retreat

# the maximum contact force to use while grasping (<=0 to disable)
float32 max_contact_force

# an optional list of obstacles that we have semantic information about
# and that can be touched/pushed/moved in the course of grasping
string[] allowed_touch_objects

================================================================================
MSG: sensor_msgs/JointState
# This is a message that holds data to describe the state of a set of torque controlled joints. 
#
# The state of each joint (revolute or prismatic) is defined by:
#  * the position of the joint (rad or m),
#  * the velocity of the joint (rad/s or m/s) and 
#  * the effort that is applied in the joint (Nm or N).
#
# Each joint is uniquely identified by its name
# The header specifies the time at which the joint states were recorded. All the joint states
# in one message have to be recorded at the same time.
#
# This message consists of a multiple arrays, one for each part of the joint state. 
# The goal is to make each of the fields optional. When e.g. your joints have no
# effort associated with them, you can leave the effort array empty. 
#
# All arrays in this message should have the same size, or be empty.
# This is the only way to uniquely associate the joint name with the correct
# states.


Header header

string[] name
float64[] position
float64[] velocity
float64[] effort

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: manipulation_msgs/GripperTranslation
# defines a translation for the gripper, used in pickup or place tasks
# for example for lifting an object off a table or approaching the table for placing

# the direction of the translation
geometry_msgs/Vector3Stamped direction

# the desired translation distance
float32 desired_distance

# the min distance that must be considered feasible before the
# grasp is even attempted
float32 min_distance

================================================================================
MSG: geometry_msgs/Vector3Stamped
# This represents a Vector3 with reference coordinate frame and timestamp
Header header
Vector3 vector

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: manipulation_msgs/GraspPlanningErrorCode
# Error codes for grasp and place planning

# plan completed as expected
int32 SUCCESS = 0

# tf error encountered while transforming
int32 TF_ERROR = 1 

# some other error
int32 OTHER_ERROR = 2

# the actual value of this error code
int32 value"""
  __slots__ = ['grasps','error_code']
  _slot_types = ['manipulation_msgs/Grasp[]','manipulation_msgs/GraspPlanningErrorCode']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       grasps,error_code

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(GraspPlanningResult, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.grasps is None:
        self.grasps = []
      if self.error_code is None:
        self.error_code = manipulation_msgs.msg.GraspPlanningErrorCode()
    else:
      self.grasps = []
      self.error_code = manipulation_msgs.msg.GraspPlanningErrorCode()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.grasps)
      buff.write(_struct_I.pack(length))
      for val1 in self.grasps:
        _x = val1.id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v1 = val1.pre_grasp_posture
        _v2 = _v1.header
        buff.write(_get_struct_I().pack(_v2.seq))
        _v3 = _v2.stamp
        _x = _v3
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v2.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        length = len(_v1.name)
        buff.write(_struct_I.pack(length))
        for val3 in _v1.name:
          length = len(val3)
          if python3 or type(val3) == unicode:
            val3 = val3.encode('utf-8')
            length = len(val3)
          buff.write(struct.pack('<I%ss'%length, length, val3))
        length = len(_v1.position)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(struct.pack(pattern, *_v1.position))
        length = len(_v1.velocity)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(struct.pack(pattern, *_v1.velocity))
        length = len(_v1.effort)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(struct.pack(pattern, *_v1.effort))
        _v4 = val1.grasp_posture
        _v5 = _v4.header
        buff.write(_get_struct_I().pack(_v5.seq))
        _v6 = _v5.stamp
        _x = _v6
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v5.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        length = len(_v4.name)
        buff.write(_struct_I.pack(length))
        for val3 in _v4.name:
          length = len(val3)
          if python3 or type(val3) == unicode:
            val3 = val3.encode('utf-8')
            length = len(val3)
          buff.write(struct.pack('<I%ss'%length, length, val3))
        length = len(_v4.position)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(struct.pack(pattern, *_v4.position))
        length = len(_v4.velocity)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(struct.pack(pattern, *_v4.velocity))
        length = len(_v4.effort)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(struct.pack(pattern, *_v4.effort))
        _v7 = val1.grasp_pose
        _v8 = _v7.header
        buff.write(_get_struct_I().pack(_v8.seq))
        _v9 = _v8.stamp
        _x = _v9
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v8.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v10 = _v7.pose
        _v11 = _v10.position
        _x = _v11
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v12 = _v10.orientation
        _x = _v12
        buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        buff.write(_get_struct_d().pack(val1.grasp_quality))
        _v13 = val1.approach
        _v14 = _v13.direction
        _v15 = _v14.header
        buff.write(_get_struct_I().pack(_v15.seq))
        _v16 = _v15.stamp
        _x = _v16
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v15.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v17 = _v14.vector
        _x = _v17
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = _v13
        buff.write(_get_struct_2f().pack(_x.desired_distance, _x.min_distance))
        _v18 = val1.retreat
        _v19 = _v18.direction
        _v20 = _v19.header
        buff.write(_get_struct_I().pack(_v20.seq))
        _v21 = _v20.stamp
        _x = _v21
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v20.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v22 = _v19.vector
        _x = _v22
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = _v18
        buff.write(_get_struct_2f().pack(_x.desired_distance, _x.min_distance))
        buff.write(_get_struct_f().pack(val1.max_contact_force))
        length = len(val1.allowed_touch_objects)
        buff.write(_struct_I.pack(length))
        for val2 in val1.allowed_touch_objects:
          length = len(val2)
          if python3 or type(val2) == unicode:
            val2 = val2.encode('utf-8')
            length = len(val2)
          buff.write(struct.pack('<I%ss'%length, length, val2))
      buff.write(_get_struct_i().pack(self.error_code.value))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.grasps is None:
        self.grasps = None
      if self.error_code is None:
        self.error_code = manipulation_msgs.msg.GraspPlanningErrorCode()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.grasps = []
      for i in range(0, length):
        val1 = manipulation_msgs.msg.Grasp()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.id = str[start:end].decode('utf-8')
        else:
          val1.id = str[start:end]
        _v23 = val1.pre_grasp_posture
        _v24 = _v23.header
        start = end
        end += 4
        (_v24.seq,) = _get_struct_I().unpack(str[start:end])
        _v25 = _v24.stamp
        _x = _v25
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v24.frame_id = str[start:end].decode('utf-8')
        else:
          _v24.frame_id = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        _v23.name = []
        for i in range(0, length):
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val3 = str[start:end].decode('utf-8')
          else:
            val3 = str[start:end]
          _v23.name.append(val3)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v23.position = struct.unpack(pattern, str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v23.velocity = struct.unpack(pattern, str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v23.effort = struct.unpack(pattern, str[start:end])
        _v26 = val1.grasp_posture
        _v27 = _v26.header
        start = end
        end += 4
        (_v27.seq,) = _get_struct_I().unpack(str[start:end])
        _v28 = _v27.stamp
        _x = _v28
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v27.frame_id = str[start:end].decode('utf-8')
        else:
          _v27.frame_id = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        _v26.name = []
        for i in range(0, length):
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val3 = str[start:end].decode('utf-8')
          else:
            val3 = str[start:end]
          _v26.name.append(val3)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v26.position = struct.unpack(pattern, str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v26.velocity = struct.unpack(pattern, str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v26.effort = struct.unpack(pattern, str[start:end])
        _v29 = val1.grasp_pose
        _v30 = _v29.header
        start = end
        end += 4
        (_v30.seq,) = _get_struct_I().unpack(str[start:end])
        _v31 = _v30.stamp
        _x = _v31
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v30.frame_id = str[start:end].decode('utf-8')
        else:
          _v30.frame_id = str[start:end]
        _v32 = _v29.pose
        _v33 = _v32.position
        _x = _v33
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _v34 = _v32.orientation
        _x = _v34
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 8
        (val1.grasp_quality,) = _get_struct_d().unpack(str[start:end])
        _v35 = val1.approach
        _v36 = _v35.direction
        _v37 = _v36.header
        start = end
        end += 4
        (_v37.seq,) = _get_struct_I().unpack(str[start:end])
        _v38 = _v37.stamp
        _x = _v38
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v37.frame_id = str[start:end].decode('utf-8')
        else:
          _v37.frame_id = str[start:end]
        _v39 = _v36.vector
        _x = _v39
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _x = _v35
        start = end
        end += 8
        (_x.desired_distance, _x.min_distance,) = _get_struct_2f().unpack(str[start:end])
        _v40 = val1.retreat
        _v41 = _v40.direction
        _v42 = _v41.header
        start = end
        end += 4
        (_v42.seq,) = _get_struct_I().unpack(str[start:end])
        _v43 = _v42.stamp
        _x = _v43
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v42.frame_id = str[start:end].decode('utf-8')
        else:
          _v42.frame_id = str[start:end]
        _v44 = _v41.vector
        _x = _v44
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _x = _v40
        start = end
        end += 8
        (_x.desired_distance, _x.min_distance,) = _get_struct_2f().unpack(str[start:end])
        start = end
        end += 4
        (val1.max_contact_force,) = _get_struct_f().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.allowed_touch_objects = []
        for i in range(0, length):
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val2 = str[start:end].decode('utf-8')
          else:
            val2 = str[start:end]
          val1.allowed_touch_objects.append(val2)
        self.grasps.append(val1)
      start = end
      end += 4
      (self.error_code.value,) = _get_struct_i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.grasps)
      buff.write(_struct_I.pack(length))
      for val1 in self.grasps:
        _x = val1.id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v45 = val1.pre_grasp_posture
        _v46 = _v45.header
        buff.write(_get_struct_I().pack(_v46.seq))
        _v47 = _v46.stamp
        _x = _v47
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v46.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        length = len(_v45.name)
        buff.write(_struct_I.pack(length))
        for val3 in _v45.name:
          length = len(val3)
          if python3 or type(val3) == unicode:
            val3 = val3.encode('utf-8')
            length = len(val3)
          buff.write(struct.pack('<I%ss'%length, length, val3))
        length = len(_v45.position)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(_v45.position.tostring())
        length = len(_v45.velocity)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(_v45.velocity.tostring())
        length = len(_v45.effort)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(_v45.effort.tostring())
        _v48 = val1.grasp_posture
        _v49 = _v48.header
        buff.write(_get_struct_I().pack(_v49.seq))
        _v50 = _v49.stamp
        _x = _v50
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v49.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        length = len(_v48.name)
        buff.write(_struct_I.pack(length))
        for val3 in _v48.name:
          length = len(val3)
          if python3 or type(val3) == unicode:
            val3 = val3.encode('utf-8')
            length = len(val3)
          buff.write(struct.pack('<I%ss'%length, length, val3))
        length = len(_v48.position)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(_v48.position.tostring())
        length = len(_v48.velocity)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(_v48.velocity.tostring())
        length = len(_v48.effort)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(_v48.effort.tostring())
        _v51 = val1.grasp_pose
        _v52 = _v51.header
        buff.write(_get_struct_I().pack(_v52.seq))
        _v53 = _v52.stamp
        _x = _v53
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v52.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v54 = _v51.pose
        _v55 = _v54.position
        _x = _v55
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v56 = _v54.orientation
        _x = _v56
        buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        buff.write(_get_struct_d().pack(val1.grasp_quality))
        _v57 = val1.approach
        _v58 = _v57.direction
        _v59 = _v58.header
        buff.write(_get_struct_I().pack(_v59.seq))
        _v60 = _v59.stamp
        _x = _v60
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v59.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v61 = _v58.vector
        _x = _v61
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = _v57
        buff.write(_get_struct_2f().pack(_x.desired_distance, _x.min_distance))
        _v62 = val1.retreat
        _v63 = _v62.direction
        _v64 = _v63.header
        buff.write(_get_struct_I().pack(_v64.seq))
        _v65 = _v64.stamp
        _x = _v65
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v64.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v66 = _v63.vector
        _x = _v66
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = _v62
        buff.write(_get_struct_2f().pack(_x.desired_distance, _x.min_distance))
        buff.write(_get_struct_f().pack(val1.max_contact_force))
        length = len(val1.allowed_touch_objects)
        buff.write(_struct_I.pack(length))
        for val2 in val1.allowed_touch_objects:
          length = len(val2)
          if python3 or type(val2) == unicode:
            val2 = val2.encode('utf-8')
            length = len(val2)
          buff.write(struct.pack('<I%ss'%length, length, val2))
      buff.write(_get_struct_i().pack(self.error_code.value))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.grasps is None:
        self.grasps = None
      if self.error_code is None:
        self.error_code = manipulation_msgs.msg.GraspPlanningErrorCode()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.grasps = []
      for i in range(0, length):
        val1 = manipulation_msgs.msg.Grasp()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.id = str[start:end].decode('utf-8')
        else:
          val1.id = str[start:end]
        _v67 = val1.pre_grasp_posture
        _v68 = _v67.header
        start = end
        end += 4
        (_v68.seq,) = _get_struct_I().unpack(str[start:end])
        _v69 = _v68.stamp
        _x = _v69
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v68.frame_id = str[start:end].decode('utf-8')
        else:
          _v68.frame_id = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        _v67.name = []
        for i in range(0, length):
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val3 = str[start:end].decode('utf-8')
          else:
            val3 = str[start:end]
          _v67.name.append(val3)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v67.position = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v67.velocity = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v67.effort = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
        _v70 = val1.grasp_posture
        _v71 = _v70.header
        start = end
        end += 4
        (_v71.seq,) = _get_struct_I().unpack(str[start:end])
        _v72 = _v71.stamp
        _x = _v72
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v71.frame_id = str[start:end].decode('utf-8')
        else:
          _v71.frame_id = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        _v70.name = []
        for i in range(0, length):
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val3 = str[start:end].decode('utf-8')
          else:
            val3 = str[start:end]
          _v70.name.append(val3)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v70.position = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v70.velocity = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        _v70.effort = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
        _v73 = val1.grasp_pose
        _v74 = _v73.header
        start = end
        end += 4
        (_v74.seq,) = _get_struct_I().unpack(str[start:end])
        _v75 = _v74.stamp
        _x = _v75
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v74.frame_id = str[start:end].decode('utf-8')
        else:
          _v74.frame_id = str[start:end]
        _v76 = _v73.pose
        _v77 = _v76.position
        _x = _v77
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _v78 = _v76.orientation
        _x = _v78
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 8
        (val1.grasp_quality,) = _get_struct_d().unpack(str[start:end])
        _v79 = val1.approach
        _v80 = _v79.direction
        _v81 = _v80.header
        start = end
        end += 4
        (_v81.seq,) = _get_struct_I().unpack(str[start:end])
        _v82 = _v81.stamp
        _x = _v82
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v81.frame_id = str[start:end].decode('utf-8')
        else:
          _v81.frame_id = str[start:end]
        _v83 = _v80.vector
        _x = _v83
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _x = _v79
        start = end
        end += 8
        (_x.desired_distance, _x.min_distance,) = _get_struct_2f().unpack(str[start:end])
        _v84 = val1.retreat
        _v85 = _v84.direction
        _v86 = _v85.header
        start = end
        end += 4
        (_v86.seq,) = _get_struct_I().unpack(str[start:end])
        _v87 = _v86.stamp
        _x = _v87
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v86.frame_id = str[start:end].decode('utf-8')
        else:
          _v86.frame_id = str[start:end]
        _v88 = _v85.vector
        _x = _v88
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _x = _v84
        start = end
        end += 8
        (_x.desired_distance, _x.min_distance,) = _get_struct_2f().unpack(str[start:end])
        start = end
        end += 4
        (val1.max_contact_force,) = _get_struct_f().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.allowed_touch_objects = []
        for i in range(0, length):
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val2 = str[start:end].decode('utf-8')
          else:
            val2 = str[start:end]
          val1.allowed_touch_objects.append(val2)
        self.grasps.append(val1)
      start = end
      end += 4
      (self.error_code.value,) = _get_struct_i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_d = None
def _get_struct_d():
    global _struct_d
    if _struct_d is None:
        _struct_d = struct.Struct("<d")
    return _struct_d
_struct_f = None
def _get_struct_f():
    global _struct_f
    if _struct_f is None:
        _struct_f = struct.Struct("<f")
    return _struct_f
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
_struct_2f = None
def _get_struct_2f():
    global _struct_2f
    if _struct_2f is None:
        _struct_2f = struct.Struct("<2f")
    return _struct_2f
_struct_4d = None
def _get_struct_4d():
    global _struct_4d
    if _struct_4d is None:
        _struct_4d = struct.Struct("<4d")
    return _struct_4d
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
