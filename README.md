## Steps to reproduce:

#### In a terminal start a ros_noetic docker. I'm using the following command:
```shell
docker run --rm -it -v ~/exp/ws:/home/user/ws -w /home/user/ws --name ros_noetic_exp ros:noetic
# ~/exp/ws is the host location of this test workspace

source /opt/ros/noetic/setup.bash
catkin_make
roscore
```

#### In another terminal, run:
```shell
docker exec -it ros_noetic_exp bash

source devel/setup.bash
rostopic pub /abcdefghijklmnopqrstuvwxyzabcdefgh test_pkg/aabbccddeeffgghhiij  -r 1 '{foo: 5}'
```

#### In another terminal, run:
```shell
docker exec -it ros_noetic_exp bash

source devel/setup.bash
rosrun test_pkg test_app
```
Notice how the callback is **not** triggering.

#### In another terminal, run:
```shell
docker exec -it ros_noetic_exp bash
source devel/setup.bash

roswtf
```
roswtf will detect that the two nodes should be connected but aren't

#### Now, do any of the following and theproblem will disappear:
- Redo the experiment but change node name (in main.cpp ros::init()) to any
    other string that is longer or shorter
- Redo the experiment but change the topic name in (main.cpp)
    to any other string that is longer or shorter. Remember to update the
    rostopic pub to match
- Redo the experiment but change the msg name (use the other msg included
    in this pkg). Remember to update the rostopic pub to match.
