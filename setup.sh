echo "Update Linux Packages..."
sudo apt-get update --assume-yes;	
sudo apt-get install libglfw3 libglfw3-dev --assume-yes;
sudo apt-get install vulkan-tools mesa-vulkan-drivers --assume-yes;
sudo apt-get install libxinerama-dev --assume-yes;
sudo apt install libxcursor-dev --assume-yes;
sudo apt install libxi-dev --assume-yes;
sleep $sleep_time; clear;
