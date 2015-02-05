# Arduino-Bluetooth-RC-Car
Turn an existing RC car into a Bluetooth controlled device with an Arduino and PS3 controller.

### Project Description

The project is to implement an Arduino microprocessor to control the functions of a pre-built RC car. The primary objective of this project was to make the car function using a PS3 controller. To implement the functionality and use the PS3 controller, we would use an open-source PS3 controller library. With the use of this library, we are able to use the PS3 controller to connect between the PS3 Bluetooth adapter and a USB Host Shield attached to the Arduino microprocessor. Once the connection is complete, we will be able to use the buttons on the PS3 controller to perform functions such as moving the car forwards, backwards, left and right.

![Alt text](https://github.com/nsalerni/Arduino-Bluetooth-RC-Car/blob/master/SBD_CPS310.png "Figure 1")

The figure above shows a simple block diagram of the project. The figure shows an RC car with two motors
that are connected to the Arduino Uno. Motor #1 is responsible for turning the front wheels (left and right), which is done by simply sending signals to pins 5 and 6 respectively. Motor #2 is responsible for moving the car forward and is controlled with pin 9 acting as a switch for an NPN transistor which in turn gives us enough current to power the second motor. The Arduino Uno has a USB Host Shield connected on top with a Bluetooth dongle that is responsible for communicating with the PS3 controller.

### Setup and Requirements

In order to start the project you must have the following parts:
  - An Adruino board (Arduino Uno 3 was used in the above project)
  - A USB Host Shield for the Arudino 
  - A Bluetooth USB dongle 
  - A PS3 Controller (the library works with Xbox and Wii controllers as well, however additional setup is required)
  - NPN Transistors 
  - Various wires (of varying length)
  - Solder and a soldering iron

In order to set up the library, uncompress the zip folder (called "USB\_Host\_Shield\_20") and rename the directory to "USB\_Host\_Shield\_20", as any special characters are not supported by the Arduino IDE.

Now open up the Arduino IDE and open "File>Preferences". There you will see the location of your sketchbook. Open that directory and create a directory called "libraries" inside that directory. Now move the "USB\_Host\_Shield\_20" directory to the "libraries" directory.

Now quit the Arduino IDE and reopen it. Then, you should be able to go open all the examples codes by navigating to "File>Examples>USB\_Host\_Shield\_20" and then select the example you will like to open.

In order to test the Bluetooth dongle with the PS3 controller, open PS3BT.ino and upload it to your board. If the code does not work as is, you can find instructions on how to set up your PS3 controller with the Bluetooth dongle here: http://forum.arduino.cc/index.php?topic=137747.0.

Once your PS3 controller and Bluetooth dongle communicate successfully you can upload Project.ino to your board and have fun controlling your RC car over Bluetooth!

Note: You may also use R2 and L2 triggers on the controller to vary the speed of the motors.
