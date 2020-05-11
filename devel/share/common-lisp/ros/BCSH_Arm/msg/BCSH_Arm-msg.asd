
(cl:in-package :asdf)

(defsystem "BCSH_Arm-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ArmControlMsg" :depends-on ("_package_ArmControlMsg"))
    (:file "_package_ArmControlMsg" :depends-on ("_package"))
  ))