FROM osrf/ros:jazzy-desktop-full

# Install vim and clear package cache to keep image small
RUN apt-get update && apt-get install -y \
    vim \
    && rm -rf /var/lib/apt/lists/*

# Automatically source ROS2 Jazzy for all new shell sessions
RUN echo "source /opt/ros/jazzy/setup.bash" >> /root/.bashrc
