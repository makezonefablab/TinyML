// Copyright (c) 2018 p5ble
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

// The serviceUuid must match the serviceUuid of the device you would like to connect
const serviceUuid = "2A5A20B9-0000-4B9C-9C69-4975713E0FF2";
let valueCharacteristic;
let LEDCharacteristic;
let ServoCharacteristic;
let myBLE;

var temp, humi;

function setup() {
  createCanvas(600, 500);

  // Create a p5ble class
  myBLE = new p5ble();

  //createCanvas(600, 400);
  background("#FFF");
  textSize(20);
  textAlign(CENTER, CENTER);

  
  // Create a text input
  input = createInput();
  input.position(15, 200);

  // Create a 'Write' button
  const writeButton = createButton('Write');
  writeButton.position(input.x + input.width + 15, 230);
  writeButton.mousePressed(writeToServo);

  // Create a 'Write' button
  const onButton = createButton('ON');
  onButton.position(15, 300);
  onButton.mousePressed(onToLED);

  // Create a 'Write' button
  const offButton = createButton('OFF');
  offButton.position(15, 350);
  offButton.mousePressed(offToLED);

  // Create a 'Connect and Start Notifications' button
  const connectButton = createButton('Connect and Start Notifications')
  connectButton.position(10, 100);
  connectButton.mousePressed(connectAndStartNotify);
}

function connectAndStartNotify() {
  // Connect to a device by passing the service UUID
  myBLE.connect(serviceUuid, gotCharacteristics);
  // You can also filter devices by name
  // myBLE.connect({
  //   filters: [{
  //     services: [serviceUuid],
  //   }, {
  //     name: 'ArduinoIMU'
  //   }]
  // }, gotCharacteristics)
}

// A function that will be called once got characteristics
function gotCharacteristics(error, characteristics) {
  if (error) console.log('error: ', error);
  for (let i = 0; i < characteristics.length; i++) {
    if (i == 0) {
      valueCharacteristic = characteristics[i];
      myBLE.read(valueCharacteristic, gotValue);
    }else if (i == 1) {
      LEDCharacteristic = characteristics[i];
    }else if (i == 2) {
      ServoCharacteristic = characteristics[i];
    } else {
      console.log("characteristic doesn't match.");
    }
  }
}

// A function that will be called once got characteristics
function handleDHTSensor(data) {
  temp = data.getFloat32(0);
}

// A function that will be called once got values
function gotValue(error, value) {
  if (error) console.log('error: ', error);
  console.log('value: ', value);
  temp = value;
  // After getting a value, call p5ble.read() again to get the value again
  myBLE.read(valueCharacteristic, gotValue);
}


function writeToServo() {
  const inputValue = input.value();
  // Write the value of the input to the myCharacteristic
  myBLE.write(ServoCharacteristic, inputValue);
}

function onToLED() {
  // Write the value of the input to the myCharacteristic
  myBLE.write(LEDCharacteristic, "1");
  background(128);
}

function offToLED() {
  // Write the value of the input to the myCharacteristic
  myBLE.write(LEDCharacteristic, "0");
  background(220);
}


function draw() {

  background(250);

  text('Door : ', 120, 80);
  text('LED : ', 120, 200);

  text(`Temperature : ${temp}`, 120, 380);
  text(`Humidity : ${humi}`, 120, 400);

}
