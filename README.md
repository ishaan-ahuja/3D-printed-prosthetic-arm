# 3D-printed-prosthetic-arm
Our servo-driven prosthetic arm combines computer vision, eye-tracking, and EEG data for precise control. Dual cameras track your gaze and the environment to pinpoint target objects. An EEG brainwave sensor then verifies your intent. Once confirmed, the system commands the arm to grasp the object or execute tasks.


# Step 1:
Download the codes and open them in the arduino IDE and download any necessary libraries and import them into the project

# Step 2:
Upload the servoMoveTest.ino to test if everything works with just one servo

# Step 3:
Upload the goToAngle.ino code and open serial monitor and starting at 90 degrees, type in different angles to find the open and close position of each finger.

# Step 4:
Edit the array of stored positions in 5_Fingers_openClose.ino to contain the values found in step 3. Upload the code to the arduino and in the serial monintor you should type in openall and closeall to move all finger servos at once.
