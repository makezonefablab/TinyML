// The serviceUuid must match the serviceUuid of the device you would like to connect
// Copyright (c) 2018 p5ble
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

const serviceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
let myCharacteristic;
let input;
let myBLE;

function setup() {

  createCanvas(710, 400);
  
  myBLE = new p5ble();

  // Create a 'Connect' button
  const connectButton = createButton('Connect')
  connectButton.mousePressed(connectToBle);
  connectButton.position(15, 65);

  // Create a text input
  input = createInput();
  input.position(15, 100);

  // Create a 'Write' button
  const writeButton = createButton('Write');
  writeButton.position(input.x + input.width + 15, 100);
  writeButton.mousePressed(writeToBle);

  // Create a 'Write' button
  const onButton = createButton('ON');
  onButton.position(15, 150);
  onButton.mousePressed(onToBle);

  // Create a 'Write' button
  const offButton = createButton('OFF');
  offButton.position(15, 200);
  offButton.mousePressed(offToBle);
}

function connectToBle() {
  // Connect to a device by passing the service UUID
  myBLE.connect(serviceUuid, gotCharacteristics);
}

function gotCharacteristics(error, characteristics) {
  if (error) console.log('error: ', error);
  console.log('characteristics: ', characteristics);
  // Set the first characteristic as myCharacteristic
  myCharacteristic = characteristics[0];
}

function writeToBle() {
  const inputValue = input.value();
  // Write the value of the input to the myCharacteristic
  myBLE.write(myCharacteristic, inputValue);
}


function onToBle() {
  // Write the value of the input to the myCharacteristic
  myBLE.write(myCharacteristic, "1");
  background(128);
}

function offToBle() {
  // Write the value of the input to the myCharacteristic
  myBLE.write(myCharacteristic, "0");
  background(0);
}