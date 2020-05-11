;; Auto-generated. Do not edit!


(when (boundp 'BCSH_Arm::ArmControlMsg)
  (if (not (find-package "BCSH_ARM"))
    (make-package "BCSH_ARM"))
  (shadow 'ArmControlMsg (find-package "BCSH_ARM")))
(unless (find-package "BCSH_ARM::ARMCONTROLMSG")
  (make-package "BCSH_ARM::ARMCONTROLMSG"))

(in-package "ROS")
;;//! \htmlinclude ArmControlMsg.msg.html


(defclass BCSH_Arm::ArmControlMsg
  :super ros::object
  :slots (_current _velocity _position ))

(defmethod BCSH_Arm::ArmControlMsg
  (:init
   (&key
    ((:current __current) 0.0)
    ((:velocity __velocity) 0.0)
    ((:position __position) 0.0)
    )
   (send-super :init)
   (setq _current (float __current))
   (setq _velocity (float __velocity))
   (setq _position (float __position))
   self)
  (:current
   (&optional __current)
   (if __current (setq _current __current)) _current)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:serialization-length
   ()
   (+
    ;; float32 _current
    4
    ;; float32 _velocity
    4
    ;; float32 _position
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _current
       (sys::poke _current (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _position
       (sys::poke _position (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _current
     (setq _current (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _velocity
     (setq _velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _position
     (setq _position (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get BCSH_Arm::ArmControlMsg :md5sum-) "18fa895f16fc658be1fe0c85d6e1dfb7")
(setf (get BCSH_Arm::ArmControlMsg :datatype-) "BCSH_Arm/ArmControlMsg")
(setf (get BCSH_Arm::ArmControlMsg :definition-)
      "float32 current
float32 velocity
float32 position
")



(provide :BCSH_Arm/ArmControlMsg "18fa895f16fc658be1fe0c85d6e1dfb7")


