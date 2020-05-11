; Auto-generated. Do not edit!


(cl:in-package BCSH_Arm-msg)


;//! \htmlinclude ArmControlMsg.msg.html

(cl:defclass <ArmControlMsg> (roslisp-msg-protocol:ros-message)
  ((current
    :reader current
    :initarg :current
    :type cl:float
    :initform 0.0)
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0)
   (position
    :reader position
    :initarg :position
    :type cl:float
    :initform 0.0))
)

(cl:defclass ArmControlMsg (<ArmControlMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ArmControlMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ArmControlMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name BCSH_Arm-msg:<ArmControlMsg> is deprecated: use BCSH_Arm-msg:ArmControlMsg instead.")))

(cl:ensure-generic-function 'current-val :lambda-list '(m))
(cl:defmethod current-val ((m <ArmControlMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BCSH_Arm-msg:current-val is deprecated.  Use BCSH_Arm-msg:current instead.")
  (current m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <ArmControlMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BCSH_Arm-msg:velocity-val is deprecated.  Use BCSH_Arm-msg:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <ArmControlMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BCSH_Arm-msg:position-val is deprecated.  Use BCSH_Arm-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ArmControlMsg>) ostream)
  "Serializes a message object of type '<ArmControlMsg>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'current))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'position))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ArmControlMsg>) istream)
  "Deserializes a message object of type '<ArmControlMsg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'current) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ArmControlMsg>)))
  "Returns string type for a message object of type '<ArmControlMsg>"
  "BCSH_Arm/ArmControlMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ArmControlMsg)))
  "Returns string type for a message object of type 'ArmControlMsg"
  "BCSH_Arm/ArmControlMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ArmControlMsg>)))
  "Returns md5sum for a message object of type '<ArmControlMsg>"
  "18fa895f16fc658be1fe0c85d6e1dfb7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ArmControlMsg)))
  "Returns md5sum for a message object of type 'ArmControlMsg"
  "18fa895f16fc658be1fe0c85d6e1dfb7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ArmControlMsg>)))
  "Returns full string definition for message of type '<ArmControlMsg>"
  (cl:format cl:nil "float32 current~%float32 velocity~%float32 position~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ArmControlMsg)))
  "Returns full string definition for message of type 'ArmControlMsg"
  (cl:format cl:nil "float32 current~%float32 velocity~%float32 position~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ArmControlMsg>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ArmControlMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'ArmControlMsg
    (cl:cons ':current (current msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':position (position msg))
))
